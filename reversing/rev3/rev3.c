#include <stdio.h>
#include <stdlib.h>

#define FLAGSIZE_MAX 256

int alg(char *buff_1, char *buff_2);

int main(int argc, char **argv)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    int bad = 0;
    char input_1[64];
    char input_2[64];

    char *lp_input_1 = input_1;
    char *lp_input_2 = input_2;
    printf("I can do math, but I need numbers from you!\n");
    fgets(lp_input_1, 64, stdin);
    printf("One more number!\n");
    fgets(lp_input_2, 64, stdin);

    bad = !alg(lp_input_1, lp_input_2);

    if (bad)
    {
        printf("Hm.. not quite..\n");
    }
    else
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
    return 0;
}

int alg(char *buff_1, char *buff_2)
{
    int i = atoi(buff_1) * atoi(buff_2);
    if (i == 1337)
    {
        return 1;
    }
    return 0;
}