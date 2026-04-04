/* example.c */
#include "corc.h"
#include <stdio.h>

void ping(void *arg){
    Chan *c = arg;
    for(int i=1;i<=3;i++){
        printf("ping: sending %d\n", i);
        chan_send(c, &i);
        corc_yield();
    }
}

void pong(void *arg){
    Chan *c = arg;
    int v;
    for(;;){
        if(chan_recv(c, &v) < 0) break;
        printf("pong: received %d\n", v);
        if(v==3) break;
    }
    corc_runtime_stop(); /* stop runtime when done */
}

int main(void){
    corc_runtime_init(2); /* two Ms (threads) */
    Chan *c = chan_create(sizeof(int));
    corc_create(ping, c, 0);
    corc_create(pong, c, 0);
    corc_runtime_run();
    printf("done\n");
    return 0;
}

