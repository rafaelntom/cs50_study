#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level
    int grade_level = round(index);

    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade_level == 6 || grade_level == 7)
    {
        printf("Grade %d\n", grade_level + 1);
    }
    else
    {
        printf("Grade %d\n", grade_level);
    }
}

int count_letters(string text)
{
    // Return the number of letters in text
    int letter_count = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }

    return letter_count;
}

int count_words(string text)
{
    // Return the number of words in text
    int word_count = 0;
    bool is_word = false;
    for (int i = 0, text_length = strlen(text); i < text_length; i++)
    {
        if (isalpha(text[i]))
        {
            if (!is_word)
            {
                is_word = true;
                word_count++;
            }
        }
        else
        {
            is_word = false;
        }
    }

    return word_count;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    int sentence_count = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count++;
        }
    }

    return sentence_count;
}
