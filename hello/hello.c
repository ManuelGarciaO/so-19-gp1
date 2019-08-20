#include <stdio.h> //Esta entre <> porque es una libreria del sistema
# include "./libhello.h" //Es una local que creamos

int main(int argc, char **argv){
    int i;
    for(i=1;i<argc;i++){
        printHello(argv[i]);
    }
    return 0;
}