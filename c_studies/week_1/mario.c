#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int row;
    int column;
    int createspace;

    // Gets the height if the number is between 1 or 8
    do
    {
        height = get_int("Choose the height: ");
    } while (height < 1 || height > 8);

    // Loop to check for the rows
    for (row = 0; row < height; row++)
    {
        // Makes sure to add a space so the pyramid is right aligned
        for (createspace = 0; createspace < height - row - 1; createspace++)
        {
            printf(" ");
        }
        // Every time the row is incresead, the columns goes back to 0
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}
