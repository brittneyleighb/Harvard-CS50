#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)


{
    string string = get_string("What is the wrting to analyze? \n"); // User input prompt

    int letterCount = 0, wordCount = 0, sentenceCount = 0; // Count letters, words, and sentences

    for (int i = 0, stringLength = strlen(string); i < stringLength + 1; i++) //assume a through z and A through Z are letters
    {
        if (string[i] >= 'a' & string [i] <= 'z' || string[i] >= 'A' & string[i] <= 'Z')
        {
            letterCount++;
        }
        if (string[i] == ' ' || string[i] == '\0') // Any characters separated by space is a word, check the end of the string count
        {
            wordCount++;


        }
        if (string [i] == '!' || string [i] == '.' || string [i] == '?') // Count . ! or ? as a sentence
        {
            sentenceCount++;
        }

    }

    float averageWordsPer100 = (100 / (float) wordCount) * (float) letterCount; // Reading level index
    float averageSentencePer100 = (100 / (float) wordCount) * (float) sentenceCount;
    int readingIndex = round(0.0588 * averageWordsPer100 - 0.296 * averageSentencePer100 - 15.8);

    if (readingIndex < 1)
    {
        printf("Before Grade 1\n"); // If the reading index is less than one, print Before Grade 1
    }
    else if (readingIndex > 16)
    {
        printf("Grade 16+\n"); // If the reading index is more than 16, print 16+
    }
    else
    {
        printf("Grade %i\n", readingIndex);
    }

    return 0;
}
