#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    float n;
    do
    {
        n = get_float("Change owed: ");



    }
    while (n < 0);
    int cents = round(n * 100);

    int z = cents;
    int i = 0;
    while (z >= 25)
    {
        i++;
        z = z - 25;
    }
    while (z >= 10)
    {
        i++;
        z = z - 10;
    }
    while (z >= 5)
    {
        i++;
        z = z - 5;
    }
    while (z >= 1)
    {
        i++;
        z = z - 1;
    }

    printf("%i\n", i);


}