#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAGSIZE_MAX 256

char *pass_1 = "aubie";

char *pass_2 = "hackathon";

int encrypt(char *password_1, char *password_2);
void print_flag(char *file);
void remove_newline(char *buff);

int main(int argc, char *argv[])
{
    setvbuf(stdout, NULL, _IONBF, 0);

    char input_1[64];
    char input_2[64];

    char *lp_input_1 = input_1;
    char *lp_input_2 = input_2;

    printf("Please give me some input!\n");
    fgets(lp_input_1, 64, stdin);
    printf("More more!!\n");
    fgets(lp_input_2, 64, stdin);

    // since we are using fgets we need to remove the newline character
    remove_newline(lp_input_1);
    remove_newline(lp_input_2);

    int amount = (encrypt(lp_input_1, lp_input_2));

    if (amount)
    {
        if (amount >= 1)
        {
            print_flag("flag_1.txt");
        }
        if (amount == 2)
        {
            print_flag("flag_2.txt");
        }
        printf("\n");
    }
    else
    {
        printf("That's not it!\n");
    }

    return 0;
}

void remove_newline(char *buff)
{
    int len = strlen(buff);
    if (buff[len - 1] == '\n')
    {
        buff[len - 1] = '\0';
    }
}

int encrypt(char *password_1, char *password_2)
{
    int password_1_check = !strcmp(password_1, pass_1);
    int password_2_check = !strcmp(password_2, pass_2);

    return password_1_check + password_2_check;
}

void print_flag(char *file)
{

    char flag[FLAGSIZE_MAX];
    FILE *f = fopen(file, "r");
    if (f == NULL)
    {
        printf("Too bad you can only run this exploit on the server...\n");
        exit(0);
    }
    fgets(flag, FLAGSIZE_MAX, f);
    printf("%s", flag);
}