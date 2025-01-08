#include <stdio.h>

int main(void)
{
    int value1, value2, value3;
    float sum, average;
    printf("What is the first value? ");
    scanf("%d", &value1);
    printf("What is the second value? ");
    scanf("%d", &value2);
    printf("What is the third value? ");
    scanf("%d", &value3);
    sum = value1 + value2 + value3;
    average = sum / 3;
    printf("The average of %d, %d, and %d is %f\n", value1, value2, value3,
            average);
    return 0;
}
