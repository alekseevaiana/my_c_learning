#include "my_lib.h"

/*
Write a program that takes a string, will perform a transformation and return it.
For each of the letters of the parameter string switch it by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
*/

char change_letter(char letter)
{
    if ((letter >= 'a' && letter < 'z') || (letter >= 'A' && letter < 'Z'))
    {
        letter = letter + 1;
    }
    else if (letter == 'z' || letter == 'Z')
    {
        letter = letter - 25;
    }
    else
    {
        letter = letter;
    }
    return letter;
}

char* rotone(char* param_1)
{
	char* new_str;
    new_str = malloc(sizeof(strlen(param_1)));
    int index;
    index = 0;
    while (param_1[index] != '\0')
    {
        new_str[index] = change_letter(param_1[index]);
        index++;
    }
    return new_str;
}

int main(int ac, char **av)
{
    printf("%c\n", change_letter(av[1][0]));
    printf("%s\n", rotone(av[1]));
    return 0;
}