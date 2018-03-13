#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

pthread_mutex_t x,ad;
pthread_t tid;
int readcount;

void intialize()
{
    pthread_mutex_init(&x,NULL);
    pthread_mutex_init(&ad,NULL);
    readcount=0;
}
