#include <stdio.h>
#include <stdlib.h>
int main(void){
    void* ptr = malloc(sizeof(unsigned char));
    *(unsigned char*)ptr = 1;
    while(11-*(unsigned char*)ptr){
        printf("%d\n", *(unsigned char*)ptr);
        *(unsigned char*)ptr += 1;
    }
    free(ptr);
    return 0;
}
