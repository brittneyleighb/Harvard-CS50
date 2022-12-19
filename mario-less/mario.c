#include <cs50.h>
#include <stdio.h>

int main(void)


    {

    int n;
    do
        {
            n = get_int("Height: "); //for user to input the height
        }
        while (n < 0 || n > 8);  //input must be within these parameters

    {
        for (int r = 0; r < n; r++) //loop for a certain number of rows, referencing int height for that number and adds one to the rows until it matches the int height
        {
            for (int c = n - r; c > 1; c--) //loop for columns, referencing max height and the rows that change based on the input
            {
                printf(" "); //number of spaces
            }
            for (int bricks = -1; bricks < r; bricks++) //the bricks that will be generated
            {
                printf("#"); //number of bricks
            }

            printf("\n"); //after numbers of spaces and bricks are printed, print a new line
        }
    };
}
