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

void * reader(int * arg )
{
  pthread_mutex_lock(&x);
    
     if ( nw_active + nw_waiting == 0 )
      {
         nr_active++; // Notify we are active
        
      }
    else
      nr_waiting++;  // We are waiting

pthread_mutex_unlock(&x); 


   nr_active--;
   if (( nr_active == 0 ) && ( nw_waiting > 0 )) // If we are the last reader
     {
        while ( nw_waiting > 0 )  // Allow all waiting writers to enter
        {
           
           w_active++;  // one more active writer
           w_waiting--; // one less waiting writer.
        }
      }
   
}

