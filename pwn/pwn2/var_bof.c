#include <stdio.h>
#include <stdlib.h>

#define FLAGSIZE_MAX 256

void print_flag();

int main()
{

    setvbuf(stdout, NULL, _IONBF, 0);

    int secret = 0;

    char buff[8];

    printf("Can I have some text to process?\n");
    gets(buff);

    printf("Processing....\n");

    if (secret)
    {
        print_flag();
    }
    else
    {
        printf("Done!...\n");
    }

    return 0;
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
}