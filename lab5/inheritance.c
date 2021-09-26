// I didnt undrestand some part of this lab and I've done this project with another partner.
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

person *create_family(int generations)
{
    // TODO: Allocate memory for new person

    // Generation with parent data
    person *p = malloc(sizeof(person));
    if (p == NULL)
    {
        return NULL;
    }
    if (generations > 1)
    {
        // TODO: Recursively create blood type histories for parents

        // TODO: Randomly assign child alleles based on parents
        p->parents[0] = create_family(generations - 1);
        p->parents[1] = create_family(generations - 1);
        p->alleles[0] = p->parents[0]->alleles[rand() % 2];
        p->alleles[1] = p->parents[1]->alleles[rand() % 2];
    }
    else
    {
        // TODO: Set parent pointers to NULL

        // TODO: Randomly assign alleles
        p->parents[0] = NULL;
        p->parents[1] = NULL;
        p->alleles[0] = random_allele();
        p->alleles[1] = random_allele();
    }

    return p;
}

void free_family(person *p)
{

    if (p == NULL)
    {
        return;
    }

    free_family(p->parents[0]);

    free_family(p->parents[1]);

    free(p);
}
void print_family(person *p, int generation)
{

    if (p == NULL)
    {
        return;
    }

    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}