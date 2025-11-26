#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *args[] = {"echo", "Hello", NULL}; 
    execvp("echo", args);
    printf("EXEC Failed\n");
    return 0;
}
