#include <stdio.h>
#include <stdlib.h>
int main(void){
    void* ptr = malloc(sizeof(unsigned char));
    for(*(unsigned char*)ptr = 0; *(unsigned char*)ptr <= 10; (*(unsigned char*)ptr)++){
        if(*(unsigned char*)ptr % 2 == 0){
            printf("%d\n", *(unsigned char*)ptr);
        }
    }
    free(ptr);
    return 0;
}
