#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <search.h>
#include <math.h>

int main(void)
{
    // get input and the name of the input is gomle_asli
    string gomle_asli = get_string("Text: ");

    //______________________________________________________

    //make some int for words , sentences , letters
    int harf   = 0;
    int gomle  = 0;
    int kalame = 1;

    //count the letters:

    for (int i = 0, n = strlen(gomle_asli); i < n; i++)
    {
        if (gomle_asli[i] >= 'a' && gomle_asli[i] <= 'z')
        {
            harf ++;

        }
        else if (gomle_asli[i] >= 'A' && gomle_asli[i] <= 'Z')
        {
            harf++;
        }
        if (gomle_asli[i] == 32)
        {
            kalame ++;
        }
        if (gomle_asli[i] == 46 || gomle_asli[i] == 63 || gomle_asli[i] == 33)
        {
            gomle ++;
        }

    }
    //for debugging--> printf("%i %i %i\n" , harf , kalame , gomle);

    float L = (harf * 100) / (kalame);
    float S = (gomle * 100) / (kalame);

    float index = (0.0588 * L) - (0.296 * S) - 15.8;

    float index2 = index;
    int index1 = round(index);
    int q = index1;



    if (q >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (q < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", q);
    }








}