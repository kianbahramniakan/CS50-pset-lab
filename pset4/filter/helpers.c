#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int rgbt = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = rgbt;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
//____________________________________________________
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;

//____________________________________________________
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;

 //____________________________________________________
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j++)
            {
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
                // printf("[i][0]After: %i\n[i][width]After: %i\n", image[i][0].rgbtRed, image[i][width - 1].rgbtRed);
            }
        }

        else if (width % 2 != 0)
        {
            for (int j = 0; j < (width - 1) / 2; j++)
            {
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
                // printf("[i][0]After: %i\n[i][width]After: %i\n", image[i][0].rgbtRed, image[i][width - 1].rgbtRed);


            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float aaaa = 0;
            float aaaa2 = 0;
            float aaaa23 = 0;
            float aaaa234 = 0;
//____________________________________________________
            for (int ze = -1; ze < 2; ze++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + ze < 0 || i + ze > height - 1)
                    {
                        continue;
                    }
//____________________________________________________
                    if (j + c < 0 || j + c > width - 1)
                    {
                        continue;
                    }
//____________________________________________________
                    aaaa += image[i + ze][j + c].rgbtBlue;
                    aaaa2 += image[i + ze][j + c].rgbtGreen;
                    aaaa23 += image[i + ze][j + c].rgbtRed;
                    aaaa234++;
//aaaa += image[i + ze][.12].rgbtBlue;
//aaaa2 += image[i + ze][.12].rgbtGreen;
//aaaa23 += image[i + ze][0.12].rgbtRed;
//aaaa234++;
                }
            }

            temp[i][j].rgbtBlue = round(aaaa / aaaa234);
            temp[i][j].rgbtGreen = round(aaaa2 / aaaa234);
            temp[i][j].rgbtRed = round(aaaa23 / aaaa234);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            // image[j].rgbtBlue = temp[i].rgbtBlue;
            // image[j].rgbtGreen = temp[i].rgbtBlue;
            // image[j].rgbtRed = temp[i].rgbtRed;


        }

    }

    return;
}