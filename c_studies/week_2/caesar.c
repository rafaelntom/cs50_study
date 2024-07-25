#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string key);
string encrypt_text(string text, int key);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar, make sure to provide only 1 argument.\n");
        return 1;
    }

    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");
    string ciphertext = encrypt_text(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);
}

bool only_digits(string key)
{
    bool all_digits = true;

    for (int i = 0, length = strlen(key); i < length; i++)
    {
        if (!isdigit(key[i]))
        {
            all_digits = false;
        }
    }

    return all_digits;
}

string encrypt_text(string text, int key)
{
    int length = strlen(text);

    string new_text = text;

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            char offset = isupper(text[i]) ? 'A' : 'a';

            new_text[i] = (text[i] - offset + key) % 26 + offset;
        }
        else
        {
            new_text[i] = text[i];
        }
    }

    return new_text;
}