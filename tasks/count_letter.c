#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* int_to_str(int number) 
{   
    int len = 0;
    int n;
    int end;
    n = number;
    while (n > 0)
    {
        n = n / 10;
        len++;
    }
    end = len;
    char* str = malloc(sizeof(char) * (len + 1));
    str[end] = '\0';
    if (number == 0) {
        str[0] = '0';
        return str;
    }
    while (len > 0)
    {
        len--;
        str[len] = number % 10 + '0';
        number = number / 10;
    }
    return str;
}

//string without trash
char* pure_str(char* str)
{
    char* my_str;
    my_str = malloc(sizeof(char) * strlen(str));
    int index;
    int my_index;
    char kk ;
    index = 0;
    my_index = 0;
    while (str[index] != '\0')
    {
        if (str[index] >= 'A' && str[index] <= 'Z')
        {
            my_str[my_index] = str[index] + 32;
            my_index++;
            index++;
            continue;
        }
        else if (str[index] < 'a' || str[index] > 'z')
        {
            index += 1;
            continue;
        }
        my_str[my_index] = str[index];
        index += 1;
        my_index += 1;
    }
    my_str[my_index] = '\0';
    return my_str;
}

// put index for every letter for putting it to the list
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

// count how many letters will be in the end, or count how many letters the list has
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

// create list with letters, if it has several same letters - the value is incrementing
// should take pure str without trash
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

int check_doubles(char* str, char letter, int index)
{
    int str_index;
    str_index = 0;
    while (str_index < index)
    {
        if (str[str_index] == letter)
        {
            return 1;
        }
        str_index++;
    }
    return 0;
}

char* ones_letter_str(char* str)
{
    char* my_str;
    my_str = malloc(sizeof(char) * (strlen(str) + 1));
    int index;
    int my_index;
    index = 0;
    my_index = 0;
    while (str[index] != '\0')
    {
        if (check_doubles(str, str[index], index) == 0)
        {
            my_str[my_index] = str[index];
            my_index++;
        }
        index++;
    }
    my_str[my_index] = '\0';
    return my_str;
}

char* one_cycle(char letter, char* nb)
{
    char* my_str = malloc(sizeof(char) * 10);
    int my_index;
    int index;
    index = 0;
    my_index = 0;
    while (nb[index] != '\0')
    {
        my_str[my_index] = nb[index];
        index++;
        my_index++;
    }
    my_str[my_index] = letter;
    my_index++;
    my_str[my_index] = '\0';
    return my_str;
}

// print list, which print counts of letter from pure string for letter from string with single letters
char* count_letter(char* param_1)
{
    char* my_str;
    int index;
    int my_index;
    int nb_index;
    char* str_nb;
    char* my_cycle;
    char* clear_str = pure_str(param_1);
    char* this_ones_letter_str = ones_letter_str(clear_str);
    int* list = create_list(clear_str);
    my_str = malloc(sizeof(char) * (strlen(this_ones_letter_str) * 3 * 3));
    index = 0;
    my_index = 0;
    while (this_ones_letter_str[index] != '\0')
    {
        str_nb = int_to_str(list[get_letter_index(this_ones_letter_str[index])]);
        my_cycle = one_cycle(this_ones_letter_str[index], str_nb);
        
        //printf("my_cycle is %s\n", my_cycle);
        //my_str[my_index] = this_ones_letter_str[index];
        //my_index++;
        //index++;
        nb_index = 0;
        while (my_cycle[nb_index] != '\0')
        {
            my_str[my_index] = my_cycle[nb_index];
            my_index++;
            nb_index++;
        }
        printf("next index %c\n", this_ones_letter_str[index + 1]);
        if (this_ones_letter_str[index+1] != '\0')
        {
            my_str[my_index] = ',';
            my_index++;
            my_str[my_index] = ' ';
            my_index++;
        }
        //printf("list [%c] %s\n", this_ones_letter_str[index], str_nb);
        index++;
    }
    my_str[my_index] = '\0';
    return my_str;
}

int main()
{
    char* str = "pp d8989..ccFa";
    char* new_str = pure_str(str);
    char* new_str2 = ones_letter_str(new_str);
    char* my_func = count_letter(str);
    printf("original str %s\n", str);
    printf("pure str %s\n", new_str);
    printf("ones letters str %s\n", new_str2);
    printf("len of ones letters str %ld\n", strlen(new_str2));
    printf("my count letter func str %s\n", my_func);
    //printf("int to str %s\n", intToStr(34));
    return 0;
}