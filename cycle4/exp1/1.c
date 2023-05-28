#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<semaphore.h>
#include<pthread.h>

#define BUFF_SIZE 10 

int buffer[BUFF_SIZE] ;
int count = -1 ;
int in = 0 ;
int out = 0 ; 

sem_t semaphore ; 


void* producer(void * arg){
    while(1){
        int y = rand() % 100 ; 
        sem_wait(&semaphore) ; 
        if ( count < BUFF_SIZE ){
            buffer[++count] = y ;
            printf("produced = %d\n",y) ;
        }
        sem_post(&semaphore) ;
        sleep(1);
    }
    return NULL ;
}

void* consumer(void * arg){
    while(1){
        int y ;
        sem_wait(&semaphore) ; 
        if ( count >= 0 ){
            y = buffer[count--] ;
            printf("Consumed : %d\n",y) ;
        }
        sem_post(&semaphore) ;
        sleep(1) ;
    }
}

int main(){
    pthread_t p, c ; 
    srand(time(NULL)) ;

    sem_init(&semaphore, 0, 1);
   

    pthread_create(&p, NULL , producer, NULL) ;
    pthread_create(&c, NULL , consumer, NULL) ;
    
    pthread_join(p, NULL) ; 
    pthread_join(c, NULL) ; 

    sem_destroy(&semaphore) ; 
   
 
}