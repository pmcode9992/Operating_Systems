#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define num_phil 5
#define num_forks 5

void dine(int n);
pthread_t philosopher[num_phil];
pthread_mutex_t forks[num_forks];

int main()
{
    int status=0,i;
    void *msg;
    printf("Declaration done\n");
    for(i=0;i<num_forks;i++){
        status = pthread_mutex_init(&forks[i],NULL);
        if(status ==-1){
            printf("Mutex initialization failed\n");
            exit(1);
        }
    }
    for(i=0;i<num_phil;i++){
        status = pthread_create(&philosopher[i],NULL, (void *) dine, (int *)i);
        if(status !=0){
            printf("Thread initialization failed\n");
            exit(1);
        }
    }
    for(int i=0;i<num_phil;i++){
        status = pthread_join(philosopher[i],&msg);
        if(status !=0){
            printf("Thread Joining failed\n");
            exit(1);
        }
    }
    for(i=0;i<num_forks;i++){
        status = pthread_mutex_destroy(&forks[i]);
        if(status !=0){
            printf("Mutex destroyed\n");
            exit(1);
        }
    }
    return 0;
}

void dine(int n){
    printf("Philosopher %d is thinking \n",n);
    pthread_mutex_lock(&forks[n]);
    pthread_mutex_lock(&forks[(n+1)%num_forks]);
    printf("Philosopher %d is eating \n",n);
    pthread_mutex_unlock(&forks[n]);
    pthread_mutex_unlock(&forks[(n+1)%num_forks]);
    printf("Philosopher %d is done eating\n",n);
}
