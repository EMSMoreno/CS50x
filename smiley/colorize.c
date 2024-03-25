#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate over image rows
    for (int i = 0; i < height; i++)
    {
        // iterate over image columns
        for (int j = 0; j < width; j++)
        {
            // check if pixel is black
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                // change pixel color to red
                image[i][j].rgbtRed = 255;
                image[i][j].rgbtGreen = 0;
                image[i][j].rgbtBlue = 0;
            }
        }
    }
}
