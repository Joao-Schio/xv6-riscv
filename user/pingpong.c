#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"




int main(void){

    int pai[2];
    int filho[2];

    int PID;
    char buffer[64];

    pipe(pai);
    pipe(filho);

    PID = fork();

    if(PID > 0){
        close(pai[0]);
        write(pai[1],"ping",5); // 5 bytes por causa do \0 ??
        close(filho[1]);
        read(filho[0],buffer,5);
        printf("%d recebeu %s\n",getpid(),buffer);
    }
    else if(PID == 0){
        close(pai[1]);
        read(pai[0],buffer,5);
        close(filho[0]);
        printf("%d recebeu %s\n",getpid(),buffer);
        write(filho[1],"pong",5);
    }

    else{
        exit(1);
    }

    exit(0);
}