#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define FLAGSIZE_MAX 48

void sigsegv_handler(int sig)
{
    char flag[FLAGSIZE_MAX];
    FILE *f = fopen("flag.txt", "r");
    if (f == NULL)
    {
        printf("Too bad you can only run this exploit on the server...\n");
        exit(0);
    }
    fgets(flag, FLAGSIZE_MAX, f);
    fprintf(stderr, "%s\n", flag);
    fflush(stderr);
    exit(1);
}

void vuln(char *input)
{
    signal(SIGSEGV, sigsegv_handler);
    char copy[256];
    strcpy(copy, input);
    printf("Thanks! Received: %s\n", copy);
}

int main(int argc, char **argv)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Give me some input!!! But not to much please :)\n");
    char buffer[1024];
    char *lp_buffer = buffer;
    fgets(buffer, 1024, stdin);

    vuln(lp_buffer);

    return 0;
}