#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define READLINE_READ_SIZE 400

char *my_readline(int fd);
int my_strlen(char* str);
char* my_strcpy(char* dst, char* str);
void test_0();
void test_1();
void test_2();
void test_3();
void test_4();
void test_5();