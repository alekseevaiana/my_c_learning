int my_strlen(char* str)
{
    int index;
    index = 0;
    while (str[index] != '\0')
    {
        index++;
    }
    return index;
}

char* my_strcpy(char* dst, char* str)
{
    int index;
    index = 0;
    while (str[index] != '\0')
    {
        dst[index] = str[index];
        index++;
    }
    dst[index] = '\0';
    return dst;
}