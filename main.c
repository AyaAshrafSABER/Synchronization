#include <pthread.h>
#include <string.h>
#include "BatManager.h"
char directions[256];
void *status;
void intialize(){
    pthread_mutex_init(&mutexMonitor, NULL);
    pthread_cond_init (&NorthQueue, NULL);
    pthread_cond_init (&EastQueue, NULL);
    pthread_cond_init (&SouthQueue, NULL);
    pthread_cond_init (&WestQueue, NULL);
    pthread_cond_init (&NorthFirst, NULL);
    pthread_cond_init (&EastFirst, NULL);
    pthread_cond_init (&SouthFirst, NULL);
    pthread_cond_init (&WestFirst, NULL);
    northCounter = 0;
    southCounter = 0;
    eastCounter = 0;
    westCounter = 0;
    crossingCounter = 0;
    waitEast = 0;
    waitNorth = 0;
    waitSouth = 0;
    waitWest = 0;
}
void destroy(){
    pthread_cond_destroy(&NorthQueue);
    pthread_cond_destroy(&EastQueue);
    pthread_cond_destroy(&SouthQueue);
    pthread_cond_destroy(&WestQueue);
    pthread_cond_destroy(&NorthFirst);
    pthread_cond_destroy(&EastFirst);
    pthread_cond_destroy(&SouthFirst);
    pthread_cond_destroy(&WestFirst);
    pthread_mutex_destroy(&mutexMonitor);

}


void *batOperation(void* arg){
    int  i = *((int *) arg);
    bat * batObj = (bat *) malloc(sizeof(bat));
    batObj->direction = directions[i];
    batObj->index = i;
    int canArr = bat_arrive(*batObj);
    if (canArr) {
        bat_cross(*batObj);
        bat_leave(*batObj);
    }
}
int main() {
    intialize();
    scanf( "%s" , &directions[0]);
    int len = strlen(directions);
    pthread_t bat[len];
    pthread_attr_t attr [len];
    crossingCounter = 0;
    for(int i = 0; i < len; i++) {
        pthread_attr_init(&attr[i]);
        int *arg = malloc(sizeof(*arg));
        if ( arg == NULL ) {
            fprintf(stderr, "Couldn't allocate memory for thread arg.\n");
            exit(EXIT_FAILURE);
        }
        *arg = i;
        pthread_create(&bat[i], &attr[i], batOperation, arg);
        pthread_attr_destroy(&attr[i]);
    }
    for(int i=0; i<len; i++)
    {
        pthread_join(bat[i], &status);
    }
    destroy();
    pthread_exit(NULL);
}