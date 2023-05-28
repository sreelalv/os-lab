#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (noPhil + 4) % N
#define RIGHT (noPhil + 1) % N

int state[N];
int phil[N] = { 0, 1, 2, 3, 4 };
sem_t mutex;
sem_t S[N];

void test(int noPhil){
    if (state[noPhil] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {

        state[noPhil] = EATING;
        sleep(2);
        printf("Philosopher %d takes fork %d and %d\n", noPhil + 1, LEFT + 1, noPhil + 1);
        printf("Philosopher %d is Eating\n", noPhil + 1);
        sem_post(&S[noPhil]);
    }
}

void take_fork(int noPhil){
    sem_wait(&mutex);

    state[noPhil] = HUNGRY;
    printf("Philosopher %d is Hungry\n", noPhil + 1);

    test(noPhil);
    sem_post(&mutex);

    sem_wait(&S[noPhil]);
    sleep(1);
}

void put_fork(int noPhil){
    sem_wait(&mutex);

    state[noPhil] = THINKING;
    printf("Philosopher %d putting fork %d and %d down\n",noPhil + 1, 
    LEFT + 1, noPhil + 1);
    printf("Philosopher %d is thinking\n", noPhil + 1);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}

void* philosopher(void* num){
    while (1) {
        int* i = num;
        sleep(1);
        take_fork(*i);
        sleep(0);
        put_fork(*i);
    }
}

void main(){
    int i;
    pthread_t thread_id[N];

    sem_init(&mutex, 0, 1);
    for (i = 0; i < N; i++)
    sem_init(&S[i], 0, 0);
    for (i = 0; i < N; i++) {

        pthread_create(&thread_id[i], NULL,philosopher, &phil[i]);
        printf("Philosopher %d is thinking\n", i + 1);
    }
    for (i = 0; i < N; i++){
    pthread_join(thread_id[i], NULL);
}
}
