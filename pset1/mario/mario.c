#include <cs50.h>
#include <stdio.h>





int main(void)
{

    unsigned int n;
    n = get_int("Start size: ");
    if (n > 8)
    {
        while (n > 8)
        {
            n = get_int("Start size: ");
        }

    }
    //----------------------------------
    if (n < 1)
    {
        while (n < 1)
        {
            n = get_int("Start size: ");
        }

    }
// gereftan aadad az karbar
//_______________________________________________

    int m = n - 1;





    for (int i = 0; i <= m; i++)
    {

        for (int p = m - i; p > 0; p--)
        {
            printf(" ");
        }

        for (int j = 0; j <= i ; j++)
        {

            printf("#");
        }

        for (int po = 2; po > 0; po--)
        {

            printf(" ");

        }
        for (int z = 0; z <= i ; z++)
        {

            printf("#");
        }





        printf("\n");

    }

}
