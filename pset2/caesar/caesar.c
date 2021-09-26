#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <search.h>
#include <math.h>
#include <stdlib.h>

// int average(int argc, string argv[]);



int average(int argc, string argv[])
{


    if (argc != 2)
    {

        printf("./caesar key\n");
        return 0;

    }
    string key = argv[1];
    for (int rt = 0, n = strlen(key); rt < n; rt++)
    {
        //printf("%c %d\n", key[rt], key[rt] < '0' || key[rt] > '9');
        if (key[rt] <= '/' || key[rt] >= ':')
        {
            printf("./caesar key\n");
            return 0;
        }
    }


    return atoi(key);


}

int main(int argc, char **argv)
{

    int lol = average(argc, argv);
    if (lol < 1)
    {

        return 1;
    }
    char c;
    string q = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(q); i < n; i++)
    {
        if (q[i] >= 'a' && q[i] <= 'z')
        {
            c = (((q[i] - 97) + (lol)) % (26)) + (97);

        }
        else if (q[i] >= 'A' && q[i] <= 'Z')
        {
            c = (((q[i] - 65) + (lol)) % (26) + (65));
        }
        else
        {
            c = q[i];
        }

        printf("%c", c);


    }
    printf("\n");

}


