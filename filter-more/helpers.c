#include "helpers.h"
#include <math.h>
#include <stdlib.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++){
        for (int j = 0; j < width; j ++){

            int aver = roundf((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = aver;
            image[i][j].rgbtGreen = aver;
            image[i][j].rgbtRed = aver;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++){
        for (int j = 0; j < width / 2; j ++){

            RGBTRIPLE tem = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tem;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i ++){
        for (int j = 0; j < width; j ++){
            temp[i][j] = image[i][j];

        }
    }

    for (int i = 0; i < height; i ++){
        for (int j = 0; j < width; j ++){

            int blue = 0;
            int green = 0;
            int red = 0;
            float counter = 0.0;

            for (int k = -1; k < 2; k ++){
                for (int l = -1; l < 2; l ++){
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width){
                        blue += temp[i + k][j + l].rgbtBlue;
                        green += temp[i + k][j + l].rgbtGreen;
                        red += temp[i + k][j + l].rgbtRed;
                        counter ++;
                    }
                }
            }

            image[i][j].rgbtBlue = round(blue / counter);
            image[i][j].rgbtGreen = round(green / counter);
            image[i][j].rgbtRed = round(red / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
