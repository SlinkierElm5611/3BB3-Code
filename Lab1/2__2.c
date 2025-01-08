#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 4

#define MODULO %
#define TWO 2
#define IS ==
#define ZERO 0
#define CHECK_THAT if
#define OTHERWISE else
#define DEREFERENCE *(unsigned int*)
#define CAST (unsigned int*)
#define VOID_BOI void*
#define GIMME_SOME_RAM malloc
#define RAM_OVERDOSE free
#define PROPHECY return
#define READ_BOI scanf
#define PRINT_BOI printf
#define PROCEDURE int
#define PROCEDURE_BOI main

PROCEDURE PROCEDURE_BOI (void) {
    VOID_BOI stack = GIMME_SOME_RAM(STACK_SIZE);
    PRINT_BOI("Please enter a non-zero number: ");
    READ_BOI("%d", CAST stack);
    CHECK_THAT (DEREFERENCE stack MODULO TWO IS ZERO) {
        PRINT_BOI("The entered number %d is even.\n", DEREFERENCE stack);
    }
    OTHERWISE {
        PRINT_BOI("The entered number %d is odd.\n", DEREFERENCE stack);
    }
    RAM_OVERDOSE(stack);
    PROPHECY ZERO;
}
