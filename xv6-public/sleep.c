#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char *argv[]) {
    if(argc<2){
        printf(2,"sleep sin parametro\n");
        exit();
    }
    if(argv[1]>0){
        sleep(atoi(argv[1]));
    }
	exit();
}