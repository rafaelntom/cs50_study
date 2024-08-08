#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");

    BYTE buffer[BLOCK_SIZE];
    FILE *img = NULL;  // setting a pointer for our image output;
    int img_count = 0; // variable to define the file name later on
    char filename[8];  // buffer for the image file name

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            // allocating a space in memory to store the image file name
            sprintf(filename, "%03i.jpg", img_count);
            img_count++;

            img = fopen(filename, "w");
        }

        if (img != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
        }
    }

    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);
    return 0;
}
