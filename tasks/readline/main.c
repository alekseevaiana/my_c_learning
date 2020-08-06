#include <stdio.h>
#include <unistd.h>
#include "lib.h"

int main(int ac, char **av)
{
    //test_0();
    //test_1();
    //test_2();
    //test_3();
    //test_4();
    //test_5();
    
    
    if (ac > 1)

    {
        int flags = O_RDONLY;
        int fd = open(av[1], flags);
        char* my_readline_str = my_readline(fd);
        char* my_readline_str2 = my_readline(fd);
        char* my_readline_str3 = my_readline(fd);
        char* my_readline_str4 = my_readline(fd);
        printf("first: %s\n", my_readline_str);
        free(my_readline_str);
        printf("second: %s\n", my_readline_str2);
        free(my_readline_str2);
        printf("third: %s\n", my_readline_str3);
        free(my_readline_str3);
        printf("fourth: %s\n", my_readline_str4);
        free(my_readline_str4);

        close(fd);
    }
    
    return 0;
}