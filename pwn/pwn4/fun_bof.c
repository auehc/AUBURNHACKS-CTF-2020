#include <stdio.h>
#include <stdlib.h>

#define FLAGSIZE_MAX 256

void print_flag();
void vuln();

int main()
{

    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Can I have some text to process?\n");
    vuln();

    return 0;
}

void vuln()
{
    char buff[64];
    gets(buff);

    printf("Processing....\n");

    printf("Done!...\n");

    return;
}

void print_flag()
{

    char flag[FLAGSIZE_MAX];
    FILE *f = fopen("flag.txt", "r");
    if (f == NULL)
    {
        printf("Too bad you can only run this exploit on the server...\n");
        exit(0);
    }
    fgets(flag, FLAGSIZE_MAX, f);
    printf("%s", flag);
    return;
}