#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#define _REENTRANT

// Function for the thread to run
void *ThreadRoutine(void *arg)
{
    int number = *((int *)arg);  // Cast argument back to int
    int i;
    for (i = 0; i < 10; i++)  // Loop to give the thread something to do
    {
        printf("thread %d running %d\n", number, i);
        sleep(number);  // Sleep for a time passed as a parameter
    }
    return NULL;
}

int main(void)
{
    pthread_t tid1, tid2;  // Create 2 thread IDs
    int t1 = 1, t2 = 2;    // Parameters for the threads
    
    // Create two threads
    pthread_create(&tid1, NULL, ThreadRoutine, (void *)(intptr_t)t1);
    pthread_create(&tid2, NULL, ThreadRoutine, (void *)(intptr_t)t2);

    // Detach thread 1
    pthread_detach(tid1);

    // Try to join thread 1
    if (pthread_join(tid1, NULL) != 0)  // Check for errors in joining
        printf("unable to join thread 1\n");

    // Try to join thread 2
    if (pthread_join(tid2, NULL) != 0)  // Check for errors in joining
        printf("unable to join thread 2\n");

    printf("parent finished\n");
    exit(0);
}
