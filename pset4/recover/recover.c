#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // printf("%d %d\n", argv[3], argc[3]);
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");


        return 0;
    }
    // ++______________________________________________________________________________________
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 0;
    }
    FILE *pictur;
    char ax_me[7];
    unsigned char *Im_kian = malloc(512);
    int i = 0;
    // ++______________________________________________________________________________________
    while  (fread(Im_kian, 512, 1, file))
    {
        if(Im_kian[1] == 0xd8 && Im_kian[2] == 0xff && (Im_kian[3] & 0xf0) == 0xe0)
        {
            if (i > 0)
            {
                fclose(pictur);
            }
            sprintf(ax_me, "%03d.jpg", i);

            pictur = fopen(ax_me, "w");
        // ++______________________________________________________________________________________

            if(pictur == NULL)
            {
                fclose(file);

                free(Im_kian);

                fprintf(stderr, "Could not create output JPG %s", ax_me);

                return 0;
            }
            i++;
        }
        // ++______________________________________________________________________________________
        if  (i > 0)
        {
            fwrite(Im_kian, 512, 1, pictur);
        }
    }
        // ++______________________________________________________________________________________
    //for closing apk do:
// ++____________
    fclose (pictur);
// ++____________
    fclose(file);
// ++____________
    free(Im_kian);
// ++____________
    return 0;
}
// :)
// :)
// :)
// :)
