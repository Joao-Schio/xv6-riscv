#include "kernel/types.h"
#include "user/user.h"






int main(int argc, char **argv){

    if(argc != 2){
        printf("Modo de usar: sleep <tempo em segundos>\n");
        exit(1);
    }

    int tempo = atoi(argv[1]);
    tempo = tempo * 10; // a syscall de sleep define um tick, que pelos testes 10 ticks estao em um segundo, ou algo muito proximo a isso pelo menos
    sleep(tempo);

    exit(0);
}