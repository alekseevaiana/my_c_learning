#include "lib.h"

char* copy_to_rest(char* buf, char* prev_rest, int size, int rest_index)
{
    char* rest;
    rest = prev_rest;
    //rest = malloc(sizeof(char) * 100);

    int buf_index;

    buf_index = 0;
    //rest_index = 0;

    while (buf_index < size)
    {
        //printf("letter in rest %c, index is %d\n", buf[buf_index], buf_index);
        rest[rest_index] = buf[buf_index];
        //printf("letter in rest %c, index is %d\n", rest[rest_index], rest_index);
        rest_index++;
        buf_index++;
    }
    
    //rest[rest_index + 1] = '\0';
    //printf("last in rest %c\n", rest[rest_index]);
    return rest;
}

char *my_readline(int fd)
{
    static char* rest_str;
    char* output;
    int output_size;
    int rest_start_index;
    int rest_size;
    int buf_size;

    rest_str =  malloc(sizeof(char) * 20);

        char buff[READLINE_READ_SIZE];
        int read_size = 0;
        buf_size = 0;
        while ((buf_size = read(fd, buff, READLINE_READ_SIZE)) > 0)
        {
            rest_str = copy_to_rest(buff, rest_str, buf_size, read_size); // read_size 0 // read size 2
            printf("rest str in loop %s\n", rest_str);
            read_size += buf_size;
            printf("read size is %d\n", read_size);
        }
        //buf_size = read(fd, buff, READLINE_READ_SIZE);
        //rest_str = copy_to_rest(buff, buf_size); // ok

    

    output = strdup(rest_str);
    printf("\n");
    return output;
}

int main(int ac, char** av)
{
    if (ac > 1)
    {
        int flags = O_RDONLY;
        int fd = open(av[1], flags);
        //lseek(fd, 2, SEEK_CUR);
        char* my_readline_str = my_readline(fd);
        printf("first: %s\n", my_readline_str);
        close(fd);
    }
    return 0;
}