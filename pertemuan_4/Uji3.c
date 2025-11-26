#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char *args[] = {"/bin/echo", "Hello", NULL}; // Contoh argumen
    execv("/bin/echo", args);
    printf("EXEC Failed\n");
    return 0;
}
