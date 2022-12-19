#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{



    if (argc == 2 && isdigit(*argv[1])) // Check that there is only one argument

    {

        int k = atoi(argv[1]); // Get the Caesar key to convert the value into an integer

        string s = get_string("plaintext: "); // Get text
        printf("ciphertext: "); // Print out cipher code

        for (int i = 0, n = strlen(s) ; i < n; i++)
        {

            if (s[i] >= 'a' && s[i] <= 'z') // Checking if it is lowercase 97 = a to 112 = z and if it + 13 characters along.
            {
                printf("%c", (((s[i] - 'a') + k) % 26) + 'a'); // Lowercase print out
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                printf("%c", (((s[i] - 'A') + k) % 26) + 'A'); // Uppercase print out
            }

            else

            {
                printf("%c", s[i]);
            }
        }

        printf("\n");
        return 0;
    }

    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
t
    }

}