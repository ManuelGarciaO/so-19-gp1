
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int forever = 1;
void signalHandler(int sgn){
    printf("Received signal: %d\n",sgn);
    forever = 0;
}
int main(){
    int pid;
    signal(10, signalHandler);
    pid = fork();
    if(pid == 0){
        //soy el hijo
        printf("Soy el hijo\n");
        //codigo que quiero que haga el hijo
        while(forever){
            printf("Hola\n");
        }
        printf("Salio del ciclo infinito\n");
    }
    else{
        printf("Soy el proceso padre y mi hijo es %d\n",pid);
        sleep(1);
        kill(pid,10);
        //codigo del padre
        for(;;){}
    }
}
