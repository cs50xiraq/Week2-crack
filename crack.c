#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <crypt.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Invalid input\n");
        return 1;
    }

    char *ash = argv[1];
    char code[4];
    char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int length = strlen(alphabet);// sum the lenght of alphabet

    for (int i = 0; i <= length; i++)// loop for first char
    {
        code[0] = alphabet[i];
        if (strcmp(crypt(code, "50"), hash) == 0)// compare the crypt function with hash
        {
            printf("%s\n", code);
            return 0;
        }

        for (int j = 0; j <= length; j++)// loop for second char
        {
            code[1] = alphabet[j];
            if (strcmp(crypt(code, "50"), hash) == 0)
            {
                printf("%s\n", code);
                return 0;
            }

            for (int c = 0; c <= length; c++)// loop for third char
            {
                code[2] = alphabet[c];
                if (strcmp(crypt(code, "50"), hash) == 0)
                {
                    printf("%s\n", code);
                    return 0;
                }

                for (int k = 0; k <= length; k++)// loop for fourth char
                {
                    code[3] = alphabet[k];
                    if (strcmp(crypt(code, "50"), hash) == 0)
                    {
                        printf("%s\n", code);// resault
                        return 0;
                    }
                }
            }
        }
    }
}
