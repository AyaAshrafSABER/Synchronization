//
// Created by aya on 18/11/18.
//

#ifndef SYNCHRONIZATION_BATMANAGER_H
#define SYNCHRONIZATION_BATMANAGER_H
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#define WEST 'w'
#define EAST 'e'
#define NORTH 'n'
#define SOUTH 's'
pthread_mutex_t mutexMonitor; //mutex

//Diretions counters
int crossingCounter; // deadlock counter
//queuing counter
int northCounter; //^
int westCounter; //<
int eastCounter; //>
int southCounter; // V
int waitNorth; // count the waiting bat from North on the right
int waitSouth;// count the waiting bat from south on the right
int waitEast;// count the waiting bat from East on the right
int waitWest;// count the waiting bat from West on the right
//condtionVariables
pthread_cond_t  NorthQueue, EastQueue, SouthQueue, WestQueue, NorthFirst, EastFirst, SouthFirst, WestFirst;
typedef struct {
    int index; //order for the input
    char direction;
} bat; //bat structure
int bat_arrive(bat b);
void bat_cross(bat b);
void bat_leave(bat b);
void check();
char getRight(char dir);
char getLeft(char dir);
void waitRight(char right);
void signalLeft(char left);
#endif //SYNCHRONIZATION_BATMANAGER_H
