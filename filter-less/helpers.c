// Inside this file are all the functions used to apply a filter to a picture

#include "helpers.h"
#include <math.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Convert the image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbGray;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // averages the color intensity and then applies the same value to all the colors to get gray
            rgbGray = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed) / 3.000);

            image[j][i].rgbtBlue = rgbGray;
            image[j][i].rgbtGreen = rgbGray;
            image[j][i].rgbtRed = rgbGray;
        }
    }
}

// Stops the max value at 255, preventing overflow
int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert the image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaBlue;
    int sepiaRed;
    int sepiaGreen;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sepiaBlue = limit(round(0.272 * image[j][i].rgbtRed + 0.534 * image[j][i].rgbtGreen + 0.131 * image[j][i].rgbtBlue));
            sepiaGreen = limit(round(0.349 * image[j][i].rgbtRed + 0.686 * image[j][i].rgbtGreen + 0.168 * image[j][i].rgbtBlue));
            sepiaRed = limit(round(0.393 * image[j][i].rgbtRed + 0.769 * image[j][i].rgbtGreen + 0.189 * image[j][i].rgbtBlue));

            image[j][i].rgbtBlue = sepiaBlue;
            image[j][i].rgbtGreen = sepiaGreen;
            image[j][i].rgbtRed = sepiaRed;
        }
    }
}

// Reflect the image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Use of a temporary array to swap values
    RGBTRIPLE temp;

    for (int j = 0; j < width / 2; j++)
    {
        for (int i = 0; i < height; i++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int sumBlue;
    int sumGreen;
    int sumRed;
    float counter;
    //The creation of a temporary table of colors so the calculations are not altered
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sumBlue = 0;
            sumGreen = 0;
            sumRed = 0;
            counter = 0.00;

            // Adds the values of the pixel and 8 neighboring ones, skipping iteration if it goes outside the picture
            for (int k = -1; k < 2; k++)
            {
                if (j + k < 0 || j + k > height - 1)
                {
                    continue;
                }

                for (int h = -1; h < 2; h++)
                {
                    if (i + h < 0 || i + h > width - 1)
                    {
                        continue;
                    }

                    sumBlue += image[j + k][i + h].rgbtBlue;
                    sumGreen += image[j + k][i + h].rgbtGreen;
                    sumRed += image[j + k][i + h].rgbtRed;
                    counter++;
                }
            }

            // Averages the sum to make picture look more blurry
            temp[j][i].rgbtBlue = round(sumBlue / counter);
            temp[j][i].rgbtGreen = round(sumGreen / counter);
            temp[j][i].rgbtRed = round(sumRed / counter);
        }
    }

    // Copies values from a temporary table
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
}