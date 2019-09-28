#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>
int main(int argc, string argv[])
{

    if (argc != 2)
    {
        //To check if the user entered two arguments in the command line.
        printf("Usage: ./crack hash\n");
        return 1; // exit code to end the program (not like other exit codes).
    }
    // array to compare those letters in crypt function .
    string alphapaticalLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int alphaL = strlen(alphapaticalLetters);
    string hashedS = argv[1];
    // to manipulate salt charecters .
    char *salt = malloc(3 * sizeof(char));
    // initialize the salt with values from input in the command line.
    salt[0] = hashedS[0];
    salt[1] = hashedS[1];
    // to end initialization of salt
    salt[2] = '\0';
    //to hold password cracking .
    char crack[4];


    for (int frthHash = 0; frthHash < alphaL; frthHash++)
    {
        
        crack[3] = hashedS[frthHash];
        if (strcmp(crypt(crack, salt), hashedS) == 0)
        {
            printf("%s\n", crack);
            return 0;
        }
        for (int trdHash = 0; trdHash < alphaL; trdHash++)
        {
            crack[2] = hashedS[trdHash];
            if (strcmp(crypt(crack, salt), hashedS) == 0)
            {
                printf("%s\n", crack);
                return 0;
            }
            for (int sndHash = 0 ; sndHash < alphaL; sndHash++)
            {
                crack[1] = hashedS[sndHash];
                if (strcmp(crypt(crack, salt), hashedS) == 0)
                {
                    printf("%s\n", crack);
                    return 0;
                }
                for (int fstHash = 0; fstHash < alphaL; fstHash++)
                {
                    crack[0] = hashedS[fstHash];
                    if (strcmp(crypt(crack, salt), hashedS) == 0)
                    {
                        printf("%s\n", crack);
                        return 0;
                    }
                }
            }
        }
    }
    printf("The password can not be cracked.\n");
    return 2; //end the problem with this exit code to makr differentation between other exit code.
    free(salt); //give the taken space back to the memory(by malloc function).
}
