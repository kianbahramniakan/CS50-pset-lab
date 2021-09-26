#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};



int main(void)
{
    // Get input words from both players

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    //for uppercase word1 do this:
    int score    = 0;
    int score2_5 = 0;
    for (int i = 0, n = strlen(word1); i < n; i++)
    {
        if (word1[i] >= 'a' && word1[i] <= 'z')
        {
            int score1 = word1[i] - 97;
            score +=  POINTS[i];


        }

        else
        {
            int score1_2 = word1[i] - 65;
            score +=  POINTS[i];

        }

    }



//for uppercase word2 do this:


    for (int i2 = 0, n = strlen(word2); i2 < n; i2++)
    {
        if (word2[i2] >= 'a' && word2[i2] <= 'z')

        {
            int score2 = word2[i2] - 97;
            score2_5 +=  POINTS[i2];

        }
        else
        {
            int score2_2 = word2[i2] - 65;
            score2_5 +=  POINTS[i2];

        }


    }

    if (score > score2_5)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2_5 > score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }



}



