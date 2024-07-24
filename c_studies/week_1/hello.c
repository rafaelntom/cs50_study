#include <stdio.h>

int main(void)
{
    // Get user name
    string name = get_string("What's your name: ");

    // Prints "Hello" + User name
    printf("hello, %s\n", name);
}