// program that takes the Coleman-Liau Index and return the grade of a text

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int number_letters();
int number_words();
int number_sentences();

int main(void)
{
    //user input
    string text = get_string("Text: ");


    int letters = number_letters(text);
    int words = number_words(text);
    int sentences = number_sentences(text);


    //average number of letters per 100 words in the text
    float L = letters * 100 / (float)words;
    //average number of sentences per 100 words in the text.
    float S = sentences * 100 / (float)words;
    //Coleman-Liau Index -> index = 0.0588 * L - 0.296 * S - 15.8
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

//get number of letters in a string
int number_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        char letter_upper = toupper(text[i]);
        if (letter_upper >= 65 && letter_upper <= 90)
        {
            letters += 1;
        }
    }
    return letters;
}
//get number of words in a string
int number_words(string text)
{
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 32)
        {
            words += 1;
        }
    }
    return words;
}
//get number of sentences in a string
int number_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 33 || text[i] == 63 || text[i] == 46)
        {
            sentences += 1;
        }
    }
    return sentences;
}