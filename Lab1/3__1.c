#include <stdio.h>
#include <stdlib.h>

int main(){
    void* data = malloc(sizeof(int)*2);
    printf("What is the first value (in decimal)? ");
    scanf("%d", (int*)data);
    printf("What is the second value (in decimal)? ");
    scanf("%d", (int*)data+1);
    
    printf("The bitwise AND of %d and %d is %d\n", *(int*)data, *((int*)data+1), *(int*)data & *((int*)data+1));
    printf("The bitwise OR of %d and %d is %d\n", *(int*)data, *((int*)data+1), *(int*)data | *((int*)data+1));
    printf("The bitwise XOR of %d and %d is %d\n", *(int*)data, *((int*)data+1), *(int*)data ^ *((int*)data+1));
    printf("The bitwise NOT of %d is %d\n", *(int*)data, ~*(int*)data);
    printf("The bitwise left shift of %d by 1 is %d\n", *(int*)data, *(int*)data << 1);
    printf("The bitwise right shift of %d by 1 is %d\n", *(int*)data, *(int*)data >> 1);
    free(data);
    return 0;
}
