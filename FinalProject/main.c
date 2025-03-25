#include "intrinsics.h"
#include "msp430g2553.h"
#include <msp430.h>

#define NPOINTS 400

void Init(void);
void Init_ADC(void);
void Init_UART(void);
void Init_PWM(void);

volatile unsigned char v[NPOINTS]; //store ADC Values
volatile char received_char = 0; // Stores recived UART data
volatile char command = 0; // Stores command
volatile unsigned char pwm = 0; // Stores PWM value
volatile unsigned char pwm_flag = 0;
volatile int task_ready = 0; //Flag to start converstion 

void main(void) {
    Init();
    Init_UART();
    Init_ADC();
    Init_PWM();

    IE2 |= UCA0RXIE; //interrupt
    __bis_SR_register(GIE);

    while (1) {
        if (task_ready == 1) {
            ADC10CTL0 |= ADC10IE;
            ADC10CTL0 |= ENC + ADC10SC; // start ADC conversion
            task_ready = 0;
        } else {
            __bis_SR_register(LPM0_bits + GIE); // enter low-power mode
        }
    }
}

void Init(void) {
    WDTCTL = WDTPW | WDTHOLD; // Stop the watchdog timer
    DCOCTL = CALDCO_16MHZ; // Set clock speed to 16MHz
    BCSCTL1 = CALBC1_16MHZ;
    P1DIR |= 0x01 | 0x03; // Set P1.0 as the output
    P1OUT = 0x00; // Turn off LED
}

void Init_ADC(void) {
    //set input channel to 4
    ADC10CTL1 = INCH_4 + CONSEQ_2;
    // Enable ACD input to P1.4
    ADC10AE0 |= BIT4;
    ADC10CTL0 = SREF_0 + ADC10SHT_2 + MSC + ADC10ON;
    // Clear Flag
    ADC10CTL0 &= ~ADC10IFG;
    ADC10CTL0 |= ENC + ADC10SC;
}

void Init_UART(void) {
    //set P1.1 and P1.2 for UART 
    P1SEL |= BIT1 + BIT2;
    P1SEL2 |= BIT1 + BIT2;
    UCA0CTL1 |= UCSSEL_2;
    //Baud rate settings
    UCA0BR0 = 138;
    UCA0BR1 = 0;

    UCA0MCTL = UCBRS_7;
    UCA0CTL1 &= ~UCSWRST;
    IE2 |= UCA0RXIE;
}

void Init_PWM(void) {
    P1DIR |= BIT6;
    P1SEL |= BIT6;

    TA0CCR0 = 255;
    TA0CCTL1 = OUTMOD_7;
    TA0CCR1 = 0;
    TA0CTL = TASSEL_2 + MC_1;
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void) {
    // read received character
    received_char = UCA0RXBUF;
    if (pwm_flag) {
        pwm = received_char;
        pwm_flag = 0;
    } else {
        command = received_char;
        pwm_flag = 1;
        TA0CCR1 = pwm;
        if(command == 'C'){
            P1OUT |= 0x03;
        } else {
            P1OUT &= ~0x03;
        }
    }
    task_ready = 1;
    __bic_SR_register_on_exit(LPM0_bits);
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {
    P1OUT |= BIT0;
    unsigned int i;
    for (i = 0; i < NPOINTS; i++) {
        v[i] = ADC10MEM >> 2;
    }
    IE2 |= UCA0TXIE;
}

#pragma vector=USCIAB0TX_VECTOR
__interrupt void USCI0TX_ISR(void) {
    P1OUT &= ~BIT0;
    unsigned int i;
    for (i = 0; i < NPOINTS; i++) {
        while (!(IFG2 & UCA0TXIFG));
        UCA0TXBUF = v[i];
    }
    IE2 &= ~UCA0TXIE;
}
