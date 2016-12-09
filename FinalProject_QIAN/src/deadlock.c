#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
pthread_mutex_t m1, m2;

void *threadA(void *d)
{

    pthread_mutex_lock(&m1);
    pthread_mutex_lock(&m2);
    printf("threadA entered");
    pthread_mutex_unlock(&m2);
    pthread_mutex_unlock(&m1);

}
void *threadB(void *d)
{
    pthread_mutex_lock(&m2);
    pthread_mutex_lock(&m1);
    printf("threadB entered");
    pthread_mutex_unlock(&m1);
    pthread_mutex_unlock(&m2);
}
int main(int argc, char* argv[])
{
    pthread_t t1,t2;
    pthread_mutex_init(&m1,0);
    pthread_mutex_init(&m2,0);
    pthread_create(&t1,NULL,threadA,0);
    pthread_create(&t2,NULL,threadB,0);
    pthread_join(t1,(void**)0);
    pthread_join(t2,(void**)0);
    pthread_mutex_destroy(&m1);
    pthread_mutex_destroy(&m2);
    return 0;
}