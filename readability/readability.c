#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    int letter_count = 0;
    int word_count = 1; // There is always at least one word
    int sentence_count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letter_count++;
        }
        else if (text[i] == ' ')
        {
            word_count++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }

    // Calculate L and S values
    float L = ((float) letter_count / word_count) * 100;
    float S = ((float) sentence_count / word_count) * 100;

    // Using Coleman-Liau Formula
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print grade level
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
