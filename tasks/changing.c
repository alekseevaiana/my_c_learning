#include "my_lib.h"

char* changing(char* str)
{
    // make space to your new str
    char* new_str = malloc(sizeof(char*) * (strlen(str) + 1));
    // strting the loop, your index = 0 (str[index] now is str[0] - 0 letter in old str)
    // your new_str is empty
    int index = 0;
    // go through starting with 0 letter to the last
    while (str[index] != '\0')
    {
        // if current letter >= some big letter, you make the letter in your new_str smaller
        if (str[index] >= 'A' && str[index] <= 'Z')
        {
            new_str[index] = str[index] + 32;
        }
        else if (str[index] >= 'a' && str[index] <= 'z')
        {
            new_str[index] = str[index] - 32;
        }
        else
        {
            // otherwise the letter in your new_str equel to the old letter in old str
            new_str[index] = str[index];
        }
        // increment to the next letter
        index++;
    }
    return new_str;
}

int main(int ac, char** av)
{
    if (ac > 1)
    {
        printf("changing func is [%s] (was [%s]), changed to small letters\n", changing(av[1]), av[1]);
    }
    return 0;
}