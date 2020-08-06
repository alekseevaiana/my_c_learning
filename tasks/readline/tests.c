#include "lib.h"

void test_0()
{
    int fd;
    char* str;

    printf("<0>\n");
    system("echo 'line1' > file.txt");
    fd = open("file.txt", O_RDONLY);

    while ((str = my_readline(fd)) != NULL)
    {
        printf("my_readline: [%s]\n", str);
        free(str);
    }
    close(fd);
    printf("Output should be line1\n");
    printf("</0>\n");
}

void test_1()
{
    int fd;
    char* str;

    printf("<1>\n");
    system("echo 'line1' > file.txt");
    system("echo 'line2' >> file.txt");
    system("echo 'line3' >> file.txt");
    system("echo 'line4' >> file.txt");
    system("echo 'line5' >> file.txt");
    system("echo 'line6' >> file.txt");
    system("echo 'line7' >> file.txt");

    fd = open("file.txt", O_RDONLY);
    while ((str = my_readline(fd)) != NULL)
    {
        printf("my_readline: [%s]\n", str);
        free(str);
    }
    close(fd);
    printf("Output should be line1 -> line7\n");
    printf("</1>\n");
}

void test_2()
{
    char* str;

    printf("<2>\n");
    while ((str = my_readline(-1)) != NULL)
    {
        printf("my_readline: [%s]\n", str);
    }
    printf("Output should be nothing\n");
    printf("</2>\n");
}

void test_3()
{
    char* str;

    printf("<3>\n");
    while ((str = my_readline(239)) != NULL)
    {
        printf("my_readline: [%s]\n", str);
    }
    printf("Output should be nothing\n");
    printf("</3>\n");
}

void test_4()
{
    int fd;
    char* str;

    printf("<4>\n");
    system("echo 'line1' > file.txt");
    system("echo 'line2' >> file.txt");
    system("echo 'line3' >> file.txt");
    system("echo 'line4' >> file.txt");
    system("echo 'line5' >> file.txt");
    system("echo 'line6' >> file.txt");
    system("echo 'line7' >> file.txt");
    system("echo '' >> file.txt");
    system("echo '' >> file.txt");
    system("echo '' >> file.txt");
    system("echo '' >> file.txt");
    system("echo '' >> file.txt");
    fd = open("file.txt", O_RDONLY);

    while ((str = my_readline(fd)) != NULL)
    {
        printf("my_readline: [%s]\n", str);
    }
    close(fd);
    printf("Output should be line1 -> line7 and 5 empty lines\n");
    printf("</4>\n");
}

void test_5()
{
    char* str;

    printf("<5>\n");
    printf("enter string: \n");
    str = my_readline(0);
    printf("my_readline: [%s]\n", str);
    printf("Output should be the entered string\n");
    printf("</5>\n");
}