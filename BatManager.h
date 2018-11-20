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
int waitNorth;
int waitSouth;
int waitEast;
int waitWest;
//condtionVariables
pthread_cond_t  NorthQueue, EastQueue, SouthQueue, WestQueue, NorthFirst, EastFirst, SouthFirst, WestFirst;
typedef struct {
    int index;
    char direction;
} bat;
int bat_arrive(bat b);
void bat_cross(bat b);
void bat_leave(bat b);
void check();
char getRight(char dir);
char getLeft(char dir);
void waitRight(char right);
void signalLeft(char left);
#endif //SYNCHRONIZATION_BATMANAGER_H
