#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define _REENTRANT

// Thread function with correct signature
void *ThreadRoutine(void *arg)
{
    int number = *((int *)arg);  // Cast the argument back to an integer
    printf("thread %d running\n", number);
    sleep(number);  // sleep for a time passed as a parameter
    printf("thread %d finished, joining... \n", number);
    return NULL;  // Ensure proper return
}

int main(void)
{
    int t;
    pthread_t tid;  // Thread ID variable
    
    // Loop through and create threads, passing t as the parameter
    for (t = 1; t < 5; t++) {
        // Passing the address of t as a void pointer
        pthread_create(&tid, NULL, ThreadRoutine, (void *)(intptr_t)t);
    }
    
    // Wait for the thread to finish
    pthread_join(tid, NULL);
    printf("All threads joined, parent running\n");
    exit(1);
}
