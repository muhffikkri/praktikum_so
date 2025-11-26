#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int howmany = 0, status, whichone, child1, child2;
    
    if ((child1 = fork()) == 0) { /* Child 1 */
        printf("Hi, I am the first child, my ID is %d\n", getpid());
        sleep(10);
        printf("\nexiting first child\n");
        exit(0);
    }
    
    if ((child2 = fork()) == 0) { /* Child 2 */
        printf("Hi, I am the second child, my ID is %d\n", getpid());
        sleep(5);
        printf("\nexiting second child\n");
        exit(0);
    }
    
    printf("This is parent, my ID is %d\n", getpid());
    
    while (howmany < 2) {
        whichone = wait(&status);
        howmany++;
        
        if (whichone == child1)
            printf("First child exited\n");
        else if (whichone == child2)
            printf("Second child exited\n");
    }
    printf("\nParent terminated\n");
    return 0;
}
