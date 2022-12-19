// substitution.c

// Implement a program that does a substitution cipher with a user supplied key

// Sample Usage

// $ ./substitution MNOPQRFGHIJTUVWDSBEXYZAKLC
// Text to encrypt: Britt loves programming
// plaintext: Britt loves programming
// ciphertext: Nbhxx twzqe dbwfmuuhvf

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{


    string cipherKey;

    void printCipher(string s, string cipherKeyValue);

    bool isAlphaOnly(string s);
    bool hasDuplicateCharacter(string s);
    bool isCorrectLength(string s);

    int main(int argc, string argv[]);

    if (argc == 2)
    {
        cipherKey = argv[1];

        if (!isCorrectLength(
                cipherKey))  // A valid cipherKey is 26 alpha characters and doesn't have duplicate characters, numbers, or special characters
        {
            printf("Invalid cipherKey. Must be 26 characters. Substitution cipherKey must include 26 alpha characters only and must not contain any duplicates.");
            return 1;
        }
        if (!isAlphaOnly(cipherKey))
        {
            printf("Invalid cipherKey. Number found. Substitution cipherKey must include 26 alpha characters only and must not contain any duplicates.");
            return 1;
        }
        if (hasDuplicateCharacter(cipherKey))
        {
            printf("Invalid cipherKey. Duplicate character found. Substitution cipherKey must include 26 alpha characters only and must not contain any duplicates.");
            return 1;
        }
    }
    else
    {
        // no cipher cipherKey provided
        printf("You must supply a substitution cipherKey\n");
        return 1;
    }

    string userText = get_string("Text to encrypt: ");

    fputs("plaintext:", stdout);
    puts(userText);
    printCipher(userText, cipherKey);
    printf("\n");

    return 0;

}

void printCipher(string s, string cipherKeyValue) // Print out new value after substitution
{
    fputs("ciphertext:", stdout);
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0, length = strlen(s); i < length; i++)
    {
        int valueIndex;


        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))  // check if the letter is upper case of lower case
        {
            if ((s[i] >= 65 && s[i] <= 90))
            {
                valueIndex = s[i];
                putchar(toupper(cipherKeyValue[valueIndex - 65]));
            }
            else
            {
                valueIndex = s[i];
                putchar(tolower(cipherKeyValue[valueIndex - 97]));
            }
        }
        else
        {
            putchar(s[i]); // If not A through Z then output the given character
        }
    }
    return;
}

bool isCorrectLength(string s) // If string is exactly 26 characters in length return true
{
    if (strlen(s) == 26)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isAlphaOnly(string s) // If string is only lowercase a through z or uppercase A through Z return true
{
    bool result = false;

    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (isalpha(s[i]))
        {
            result = true;
        }
        else
        {
            result = false;
            break;
        }
    }
    return result;
}

bool hasDuplicateCharacter(string s) // Check for duplicates in string
{

    int count = 0;

    for (int i = 0, length = strlen(s); i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (s[i] == s[j])
            {
                count++;
            }
        }

        if (count > 1) // If the count is over 1 there is a duplicate, exit
        {
            return true;
        }
        else
        {
            count = 0;
        }
    }
    return false;

}