// Caesar encryption

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool is_number();

int main(int argc, string argv[])
{
    //check if the command line is valid
    if (argc != 2 || !is_number(argv[1]))
    {
        printf("./caesar key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;
    long value_letter; //using for get ascii number, in a chart pass the bits
    int key = atoi(argv[1]);

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char letter = plaintext[i];
        //check the letter is A to Z and a to z, by the ascii number
        if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122))
        {
            //upper the letter for unified the text
            value_letter = toupper(letter);
            value_letter += key;

            //if the letter pass 90 (Z) turn to 64 (A-1 position) and add the rest of the key and check the letter is not lowercase
            do
            {
                int aux = 0;
                if (value_letter >= 91)
                {
                    value_letter = 64 + (value_letter - 90);
                }
                value_letter += aux;
                aux++;
            }
            while (value_letter >= 91);

            //value of the letter in a position of the ciphertext
            ciphertext[i] = value_letter;

            //check if the original is lower to lower the ciphertext letter
            if (islower(letter))
            {
                ciphertext[i] = tolower(ciphertext[i]);
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    printf("ciphertext: %s\n", ciphertext);
}

//check if a string is a number
bool is_number(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] < 48 || text[i] > 57)
        {
            return false;
        }
    }
    return true;
}