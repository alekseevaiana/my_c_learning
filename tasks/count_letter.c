#include <stdio.h>
#include <stdlib.h>

int get_letter_index(char letter)
{
    int index;
    if (letter >= 'a' && letter <= 'z')
    {
        index = letter - 97;
    }
    else if (letter >= 'A' && letter <= 'Z')
    {
        index = letter - 65;
    }
    return index;
}

int count_ones(int* list)
{
    int index;
    int count;
    index = 0;
    count = 0;
    while (index < 26)
    {
        if (list[index] > 0)
        {
            count += 1;
        }
        index += 1;
    }
    return count;
}

int* create_list(char* param_1)
{
    int* list = malloc(sizeof(int) * 26);
    int index_list;
    index_list = 0;
    while (index_list < 26)
    {
        list[index_list] = 0;
        index_list += 1;
    }
    int index;
    index = 0;
    while (param_1[index] != '\0')
    {
        list[get_letter_index(param_1[index])]++;
        index++;
    }
    return list;
}

char first_letter(char letter, int* list)
{
    int index;
    index = 0;
    while (index < 26)
    {
        if (list[get_letter_index(letter)] >= 1)
        {
            return letter;
        }
        index += 1;
    }
    return 0;
}


int check_doubles(char* str, char letter, int index)
{
    int str_index;
    str_index = 0;
   // printf("index %d\n", index);
    //printf("str 1 %c\n", str[1]);
    //printf("letter %c\n", letter);
    while (str_index < index)
    {
        //printf("str i %c\n", str[str_index]);
        if (str[str_index] == letter)
        {
            //printf("str i %c\n", str[str_index]);
            return 1;
        }
        str_index++;
    }
    return 0;
}
char* count_letter(char* param_1)
{
    int index;
    int* list = create_list(param_1);

    printf("%d\n", count_ones(list));
    printf("list c %d\n", list[get_letter_index(param_1[1])]);

    char* str;
    index = 0;
    while (param_1[index] != '\0')
    {
        if (check_doubles(param_1, param_1[index], index) == 0)
        {
            printf("%c\n", param_1[index]);
        }
        index++;
    }
    return str;
}

int main()
{
    char* str = "bcdccaa";
    count_letter(str);
    return 0;
}