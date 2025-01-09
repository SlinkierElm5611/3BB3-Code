#include <stdio.h>
#include <stdlib.h>

void averageCalculator(void* data);

int main(){
    void* data = malloc(sizeof(int)*3 + sizeof(float));
    printf("What is the first value? ");
    scanf("%d", (int*)data);
    printf("What is the second value? ");
    scanf("%d", (int*)data+1);
    printf("What is the third value? ");
    scanf("%d", (int*)data+2);
    averageCalculator(data);
    printf("The average of the three values is: %f\n", *((float*)data+3));
    free(data);
    return 0;
}

void averageCalculator(void* data){
    *((float*)data+3)  = ((*(int*)data + *((int*)data+1) + *((int*)data+2))) / 3.0f;
}
