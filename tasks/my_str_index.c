#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

char* my_string_index(char* str1, int index)
{
    str1 = &str1[index];
    return str1;
}

char* inter(char* param_1, char* param_2)
{
    int len1 = strlen(param_1);
    int len2 = strlen(param_2);
    char* strnew;
    //int count[20];
    strnew = (char*)malloc(sizeof(char) * len1 + 1); // was mistake
    int i = 0;
    int j = 0;
    //int k = 0;
    //char s;
    for (i = 0; i < len1; i++) 
    {
        for (j = 0; j < len2; j++)
        { // printf("%c",param_1[i]);
            if(param_1[i] == param_2[j])
            {
                strnew = my_string_index(param_1, i);
            }
        }
    }
    return strnew;
}
int main(int ac,char** av)
{
    if (ac > 2)
    {
        printf("%s\n", inter(av[1], av[2]));
    }
    
    return 0;
}