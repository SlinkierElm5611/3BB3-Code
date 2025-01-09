#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 1 | 3
 * 01 | 10 = 11
 * 1^3
 * 01 ^ 11 = 10
 * 1 & 3
 * 01 & 11 = 01

**/

int main(void){
    void* data = malloc(sizeof(unsigned int)*3);
    printf("What is the initial state (in decimal)? ");
    scanf("%d", (unsigned int*)data);
    memcpy((unsigned int*)data+1, (unsigned int*)data, sizeof(unsigned int));
    printf("What is the change (in decimal)? ");
    scanf("%d", (unsigned int*)data+2);
    *((unsigned int*)data+1) |= *((unsigned int*)data+2);
    printf("The |= of %d, and %d is %d\n", *(unsigned int*)data, *((unsigned int*)data+2), *((unsigned int*)data+1));
    memcpy((unsigned int*)data+1, (unsigned int*)data, sizeof(unsigned int));
    *((unsigned int*)data+1) ^= *((unsigned int*)data+2);
    printf("The ^= of %d, and %d is %d\n", *(unsigned int*)data, *((unsigned int*)data+2), *((unsigned int*)data+1));
    memcpy((unsigned int*)data+1, (unsigned int*)data, sizeof(unsigned int));
    *((unsigned int*)data+1) &= *((unsigned int*)data+2);
    printf("The &= of %d, and %d is %d\n", *(unsigned int*)data, *((unsigned int*)data+2), *((unsigned int*)data+1));
    free(data);
    return 0;
}
