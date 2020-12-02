/* 
This program creates two threads using mutual exclusion. 
The first thread counts up to 10 and once finished the second thread counts down to 0. 
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int count=0;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *start_thread_one()
{
        printf("Starting thread one ");
        
        int i;
        
        for (i=0;i<10;i++)
        {
           pthread_mutex_lock (&mutex1);
                count++;
                printf("value of count thread one: %d\n",count);

          pthread_mutex_unlock (&mutex1);
        }
        
        return NULL;
}


void *start_thread_two()
{
        printf("Starting thread two ");
        
        int i;
        
        for (i=0;i<10;i++)
        {
        pthread_mutex_lock (&mutex1);
                count--;
                printf("value of count thread two: %d\n",count);

        pthread_mutex_unlock (&mutex1);
       }
       
       return NULL;
}


int main()
{
        pthread_t one,two;
       
        pthread_create(&one,NULL,start_thread_one,NULL);
        pthread_create(&two,NULL,start_thread_two,NULL);
    
        pthread_join(one,NULL);
        pthread_join(two,NULL);
        
        return (0);
}
