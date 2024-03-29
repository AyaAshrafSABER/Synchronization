//
// Created by aya on 18/11/18.
//

#include "BatManager.h"
int bat_arrive(bat b){
    // code to check traffic in line, use counters, condition variables
    pthread_mutex_lock(&mutexMonitor);
    int can = 1;
    switch (b.direction)
    {
        case WEST: // code to be executed if direction[n]= w;
            westCounter++;
            if (westCounter > 1) {
                pthread_cond_wait(&WestQueue,&mutexMonitor);
            }
            break;
        case EAST: // code to be executed if direction[n]= e;
            eastCounter++;
            if (eastCounter > 1) {
                pthread_cond_wait(&EastQueue,&mutexMonitor);
            }
            break;
        case NORTH: // code to be executed if direction[n]= n;
            northCounter++;
            if (northCounter > 1) {
                pthread_cond_wait(&NorthQueue,&mutexMonitor);
            }
            break;
        case SOUTH:// code to be executed if direction[n]= s;
            southCounter++;
            if (southCounter > 1) {
                pthread_cond_wait(&SouthQueue,&mutexMonitor);
            }
            break;
        default: // code to be executed if n doesn't match any cases
            printf("You enter wrong direction\n");
            can = 0;
            return can;
    }
    printf("BAT %d from %c arrives at crossing\n", b.index, b.direction);
    crossingCounter++;
    printf(" northCounter = %d;\n"
           "    southCounter = %d;\n"
           "    eastCounter = %d;\n"
           "    westCounter = %d;\n"
           "    crossingCounter = %d ;\n"
           "    waitEast = %d;\n"
           "    waitNorth = %d;\n"
           "    waitSouth = %d;\n"
           "    waitWest = %d;\n",  northCounter, southCounter,eastCounter ,
           westCounter,crossingCounter, waitEast, waitNorth , waitSouth , waitWest );
    printf("-----before checking---\n");
    check();
    pthread_mutex_unlock (&mutexMonitor);
    return can;
}
void bat_cross(bat b){
    // code to check traffic from the right, use counters,condition variables etc
    pthread_mutex_lock (&mutexMonitor);
    char right = getRight(b.direction);
    waitRight(right);
    printf("**********Enter the cross and try to wait on the right********");
    printf(" northCounter = %d;\n"
           "    southCounter = %d;\n"
           "    eastCounter = %d;\n"
           "    westCounter = %d;\n"
           "    crossingCounter = %d ;\n"
           "    waitEast = %d;\n"
           "    waitNorth = %d;\n"
           "    waitSouth = %d;\n"
           "    waitWest = %d;\n",  northCounter, southCounter,eastCounter ,
           westCounter,crossingCounter, waitEast, waitNorth , waitSouth , waitWest );
    pthread_mutex_unlock (&mutexMonitor);
    printf("bat %d wait to cross from %c crossing\n",b.index ,b.direction);
    sleep(1); // it takes one second for a BAT to cross
    pthread_mutex_lock (&mutexMonitor);
    printf("BAT %d from %c crossing\n", b.index, b.direction);
    char left = getLeft(b.direction);
    crossingCounter--;
    printf("**********After Crossing **********\n");
    printf(" northCounter = %d;\n"
           "    southCounter = %d;\n"
           "    eastCounter = %d;\n"
           "    westCounter = %d;\n"
           "    crossingCounter = %d ;\n"
           "    waitEast = %d;\n"
           "    waitNorth = %d;\n"
           "    waitSouth = %d;\n"
           "    waitWest = %d;\n",  northCounter, southCounter,eastCounter ,
           westCounter,crossingCounter, waitEast, waitNorth , waitSouth , waitWest );
    signalLeft(left);
    pthread_mutex_unlock (&mutexMonitor);
}
void bat_leave(bat b){
    pthread_mutex_lock (&mutexMonitor);
    switch (b.direction)
    {
        case WEST: // code to be executed if direction[n]= w;
            westCounter--;
            if (westCounter > 0) {
                pthread_cond_signal(&WestQueue);
            }
            if (waitNorth >= 1) {
                waitNorth --;
                pthread_cond_signal(&NorthFirst);
            }
            break;
        case EAST: // code to be executed if direction[n]= e;
            eastCounter--;
            if (eastCounter > 0) {
                pthread_cond_signal(&EastQueue);
            }
            if (waitSouth >= 1) {
                pthread_cond_signal(&SouthFirst);
                waitSouth--;
            }
            break;
        case NORTH: // code to be executed if direction[n]= n;
            northCounter--;
            if (northCounter > 0) {
                pthread_cond_signal(&NorthQueue);
            }
            if (waitEast >= 1) {
                pthread_cond_signal(&EastFirst);
                waitEast--;
            }
            break;
        case SOUTH:// code to be executed if direction[n]= s;
            southCounter--;
            if (southCounter > 0) {
                pthread_cond_signal(&SouthQueue);
            }
            if (waitWest >= 1){
                pthread_cond_signal(&WestFirst);
                waitWest--;
            }
            break;
        default: // code to be executed if n doesn't match any cases
            printf("You enter wrong direction\n");
            return;
    }
    //// code to check traffic, use counters, condition variables etc.
    printf("BAT %d from %c leaving crossing\n", b.index, b.direction);
    pthread_mutex_unlock (&mutexMonitor);

}
void check(){
// the manager checks for deadlock and resolves it
    if (crossingCounter == 4) {
        printf("DEADLOCK: BAT jam detected, signalling North to go\n");
        if (northCounter > 1 && waitNorth > 1) {
            waitNorth--;
            pthread_cond_signal(&NorthFirst);
        }
        crossingCounter--;
        printf("---------Solving the DeadLock -----------------\n");
        printf(" northCounter = %d;\n"
               "    southCounter = %d;\n"
               "    eastCounter = %d;\n"
               "    westCounter = %d;\n"
               "    crossingCounter = %d ;\n"
               "    waitEast = %d;\n"
               "    waitNorth = %d;\n"
               "    waitSouth = %d;\n"
               "    waitWest = %d;\n",  northCounter, southCounter,eastCounter ,
               westCounter,crossingCounter, waitEast, waitNorth , waitSouth , waitWest );
    }
}

char getRight(char dir) {
    switch (dir)
    {
        case WEST: // code to be executed if direction[n]= w;                            N
            return SOUTH;   //                                                       W <-|-> E
        case EAST: // code to be executed if direction[n]= e;                            s
            return NORTH;
        case NORTH: // code to be executed if direction[n]= n;
            return WEST;
        case SOUTH:// code to be executed if direction[n]= s;
            return EAST;
        default: // code to be executed if n doesn't match any cases
            break;
    }
}
char getLeft(char dir) {
    switch (dir)
    {
        case WEST: // code to be executed if direction[n]= w;                            N
            return NORTH;   //                                                       W <-|-> E
        case EAST: // code to be executed if direction[n]= e;                            s
            return SOUTH;
        case NORTH: // code to be executed if direction[n]= n;
            return EAST;
        case SOUTH:// code to be executed if direction[n]= s;
            return WEST;
        default: // code to be executed if n doesn't match any cases
            break;
    }
}
void waitRight(char right){
    switch (right)
    {
        case WEST: // code to be executed if direction[n]= w;
            if (westCounter >= 1) {
                waitNorth++;
                pthread_cond_wait(&NorthFirst,&mutexMonitor);
            }
            break;
        case EAST: // code to be executed if direction[n]= e;
            if (eastCounter >= 1) {
                waitSouth++;
                pthread_cond_wait(&SouthFirst,&mutexMonitor);
            }
            break;
        case NORTH: // code to be executed if direction[n]= n;
            if (northCounter >= 1) {
                waitEast++;
                pthread_cond_wait(&EastFirst,&mutexMonitor);
            }
            break;
        case SOUTH:// code to be executed if direction[n]= s;
            if (southCounter >= 1) {
                waitWest++;
                pthread_cond_wait(&WestFirst,&mutexMonitor);
            }
            break;
        default: // code to be executed if n doesn't match any cases
            break;
    }

}
void signalLeft(char left){
    switch (left)
    {
        case WEST: // code to be executed if direction[n]= w;
            if (westCounter >= 1) {
                if (waitWest > 0) {
                    waitWest--;
                    pthread_cond_signal(&WestFirst);
                }
            }
            break;
        case EAST: // code to be executed if direction[n]= e;
            if (eastCounter >= 1) {
                if(waitEast > 0) {
                    waitEast--;
                    pthread_cond_signal(&EastFirst);
                }
            }
            break;
        case NORTH: // code to be executed if direction[n]= n;
            if (northCounter >= 1) {
                if (waitNorth > 0) {
                    waitNorth--;
                    pthread_cond_signal(&NorthFirst);
                }
            }
            break;
        case SOUTH:// code to be executed if direction[n]= s;
            if (southCounter >= 1) {
                if(waitSouth > 0) {
                    waitSouth--;
                    pthread_cond_signal(&SouthFirst);
                }
            }
            break;
        default: // code to be executed if n doesn't match any cases
            break;
    }
    printf("-*-*-*-*-*-*Try to signal left--*-*-*-*-*-\n");
    printf(" northCounter = %d;\n"
           "    southCounter = %d;\n"
           "    eastCounter = %d;\n"
           "    westCounter = %d;\n"
           "    crossingCounter = %d ;\n"
           "    waitEast = %d;\n"
           "    waitNorth = %d;\n"
           "    waitSouth = %d;\n"
           "    waitWest = %d;\n",  northCounter, southCounter,eastCounter ,
           westCounter,crossingCounter, waitEast, waitNorth , waitSouth , waitWest );
}
