#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num = 0;
    int num1 = 0;
    scanf("%d\n",&num1);
    if(num1==-1){
        fprintf(stderr, "programa terminado\n");
        exit(-1);
    }
    fprintf(stderr,"%d\n",num1);
    while(1){
        scanf("%d\n",&num);
        if(num == -1){
            printf("%d\n", -1);
            break;
        }
        if(num % num1 != 0){
            printf("%d\n", num);
        }
    }
}