#include <stdio.h>
#include "lib.h"

char* copy_to_rest(char* buf, char* prev_rest, int size, int rest_index)
{
    char* rest;
    rest = malloc(sizeof(char) * (size + rest_index) + 1);

    if (prev_rest != NULL)
    {
        my_strcpy(rest, prev_rest);
    }
    int buf_index;

    buf_index = 0;
    while (buf_index < size)
    {
        rest[rest_index] = buf[buf_index];
        rest_index++;
        buf_index++;
    }
    rest[rest_index] = '\0';
    return rest;
}

char* cp_to_output(char* rest, int size)
{
    char* output;
    int index;

    output = malloc(sizeof(char) * size + 1);

    index = 0;
    while (rest[index] != '\n' && rest[index] != '\0')
    {
        output[index] = rest[index];
        index++;
    }
    output[index] = '\0';

    return output;
}

char* my_readline(int fd)
{
    static char* rest_str;
    char* temp;
    char* output;
    int rest_start_index;
    int rest_size;
    int buf_size;
    int read_size;

    // 1. copy read buffer to rest_str
    char buff[READLINE_READ_SIZE];
    buf_size = 0;
    read_size = 0;

    while ((buf_size = read(fd, buff, READLINE_READ_SIZE)) > 0)
    {
        rest_str = copy_to_rest(buff, rest_str, buf_size, read_size);
        read_size += buf_size;
    }

    if (rest_str == NULL)
    {
        return NULL;
    }
    // 2. copy from rest_str to current output
    else if (rest_str != NULL)
    {
        output = cp_to_output(rest_str, read_size);
        rest_start_index = my_strlen(output) + 1;
    }    

    // 3. if something was left, copy it to static rest_str
    if (rest_start_index < my_strlen(rest_str))
    {
        rest_size = my_strlen(rest_str + rest_start_index);

        temp = copy_to_rest(rest_str + rest_start_index,
                            rest_str + rest_start_index, rest_size, 0);
        free(rest_str);
        rest_str = temp;
    }
    else
    {
        rest_str = NULL;
    }
    return output;
}