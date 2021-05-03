// Command-Line program that takes a '.raw' file and recover the photos

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //Open the command file (memory card)
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    //counter of jpeg headers
    int counter_jpg = 0;
    //name of files jpeg
    char img_name[8];
    //stores the 512 bytes of a chunk of the input file
    uint8_t buffer[512];
    //file of image
    FILE *jpeg;

    while (fread(buffer, sizeof(uint8_t), 512, input_file))
    {
        //if the first 4 bytes is the same of these, thats a header jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            if (buffer[3] == 0xe0 || buffer[3] == 0xe1 || buffer[3] == 0xe2 || buffer[3] == 0xe3
                || buffer[3] == 0xe4 || buffer[3] == 0xe5 || buffer[3] == 0xe6 || buffer[3] == 0xe7
                || buffer[3] == 0xe8 || buffer[3] == 0xea || buffer[3] == 0xeb || buffer[3] == 0xec
                || buffer[3] == 0xed || buffer[3] == 0xee || buffer[3] == 0xef)
            {
                //if the counter is 0 is the first jpeg
                if (counter_jpg == 0)
                {
                    sprintf(img_name, "%03i.jpg", counter_jpg);
                    jpeg = fopen(img_name, "w");
                    fwrite(buffer,  sizeof(uint8_t), 512, jpeg);

                    counter_jpg++;
                }
                else
                {
                    sprintf(img_name, "%03i.jpg", counter_jpg);
                    jpeg = fopen(img_name, "w");
                    fwrite(buffer,  sizeof(uint8_t), 512, jpeg);

                    counter_jpg++;
                }
            }
        }
        //if the header isn´t the same but is already a jpeg file write the 512 bytes at the file
        else if (counter_jpg > 0)
        {
            fwrite(buffer,  sizeof(uint8_t), 512, jpeg);
        }

    }
    //close the files
    fclose(jpeg);
    fclose(input_file);
    return 0;
}