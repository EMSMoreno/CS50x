#include "helpers.h"
#include <math.h>

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Define the color to use for black pixels
    RGBTRIPLE color = {255, 0, 255};

    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Check if the current pixel is black
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                // Set the color to the defined color
                image[i][j] = color;
            }
        }
    }
}