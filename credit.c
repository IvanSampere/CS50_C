// Program command-line to verificate a credit card
#include <stdio.h>
#include <cs50.h>
#include <string.h>

//Prototype
long verification_operations();
void get_verification_card();

int main(void)
{
    //Prompt credit card
    long card = get_long("Credit card: ");

    long sum_verification_card = verification_operations(card);

    if (sum_verification_card % 10 == 0)
    {
        get_verification_card(card);
    }
    else
    {
        printf("INVALID\n");
    }
}

long verification_operations(long card)
{
    //variable auxiliary for keep the sum
    long card_digit_verification = 0;

    //Using auxiliary variables and a while loop to get the second-to-last digit.
    long aux_card = card / 10;
    while (aux_card > 0)
    {
        long operation_value = (aux_card % 10) * 2;
        //if the value of the operation is more than 10 split the value and adds them
        if (operation_value > 9)
        {
            operation_value = (operation_value % 10) + (operation_value / 10);
        }
        card_digit_verification = card_digit_verification + operation_value;
        aux_card = aux_card / 100;
    }
    //Using auxiliary variables and a while loop to get the one-to-last digit.
    long aux_card2 = card;
    while (aux_card2 > 0)
    {
        long operation_value = aux_card2 % 10;
        card_digit_verification = card_digit_verification + operation_value;
        aux_card2 = aux_card2 / 100;
    }
    //printf("aux = %li\n", card_digit_verification);
    return card_digit_verification;
}

void get_verification_card(long card)
{
    // AMEX 15 digits
    long amex = 10000000000000;
    //MasterCard 16 digits
    long masterCard = 100000000000000;
    //VISA 13 or 16 digits
    long visa = 1000000000000;

    if (card / amex == 34 || card / amex == 37)
    {
        printf("AMEX\n");
    }
    else if (card / masterCard == 51 || card / masterCard == 52 ||
             card / masterCard == 53 || card / masterCard == 54 ||
             card / masterCard == 55)
    {
        printf("MASTERCARD\n");
    }
    else if (card / visa == 4 || card / (visa * 10) == 4 ||
             card / (visa * 100) == 4 || card / (visa * 1000) == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}