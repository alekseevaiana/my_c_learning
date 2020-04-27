#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

enum Direction { NORTH = 1, EAST, SOUTH, WEST};

typedef struct s_position {
    int x;
    int y;
    enum Direction direction;
} positions;

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int findLen(char* str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char* intToStr(int number) 
{   
    int len = 0;
    int isNegative = 0;
    int n;
    int end;
    if (number < 0) {
        len = len + 1;
        n = number * -1;
        isNegative = 1;
    } 
    else
        n = number;
    while (n > 0)
    {
        n = n / 10;
        len++;
    }
    end = len;
    char* str = malloc(sizeof(char) * (len + 1 + isNegative));
    str[end] = '\0';
    
    if (number < 0) {
        number = number * -1;
        while (len > 1) {
            str[0] = '-';
            len--;
            str[len] = number % 10 + '0';
            number = number / 10;
        }
        return str;
    }
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

char* intToDirection(int number) {
    char* str;
    if (number == 1) {
        str = "north";
    }
    else if (number == 2) {
        str = "east";
    }
    else if (number == 3) {
        str = "south";
    }
    else if (number == 3) {
        str = "west";
    }
    return str;
}

void find_positions(positions* strct, char a) {
    if (strct->direction == NORTH && a == 'A') {
        strct->y = strct->y - 1;
    }
    else if (strct->direction == SOUTH && a == 'A') {
        strct->y = strct->y + 1;
    }
    else if (strct->direction == EAST && a == 'A') {
        strct->x = strct->x + 1;
    }
    else if (strct->direction == WEST && a == 'A') {
        strct->x = strct->x - 1;
    }
}

void find_direction(positions* strct, char a) {
    if (strct->direction == NORTH && a == 'R') {
        strct->direction = EAST;
    }
    else if (strct->direction == NORTH && a == 'L') {
        strct->direction = WEST;
    }
    else if (strct->direction == EAST && a == 'R') {
        strct->direction = SOUTH;
    }
    else if (strct->direction == EAST && a == 'L') {
        strct->direction = NORTH;
    }
    else if (strct->direction == SOUTH && a == 'R') {
        strct->direction = WEST;
    }
    else if (strct->direction == SOUTH && a == 'L') {
        strct->direction = EAST;
    }
    else if (strct->direction == WEST && a == 'R') {
        strct->direction = NORTH;
    }
    else if (strct->direction == WEST && a == 'L') {
        strct->direction = SOUTH;
    }
}

char* my_new_str(int x, int y, int direction) {
    char* x_to_str = intToStr(x);
    char* y_to_str = intToStr(y);
    char* direction_to_str = intToDirection(direction);

    int sumLen = 0;
    int countParts = 0;

    char *str[7] = {"{x: ", x_to_str, ", y: ", y_to_str, ", bearing: '", direction_to_str, "'}"};

    while (countParts < 7)
    {
        sumLen = sumLen + findLen(str[countParts]);
        countParts++;
    }
    char* newStr = malloc(sizeof(char) * sumLen + 1);
    int currentLine = 0;
    int currentLineIndex;
    int newStrIndex = 0;
    int currentLen;
    
        while (currentLine < 7)
        {
            currentLineIndex = 0;
            currentLen = findLen(str[currentLine]);
            while (currentLineIndex < currentLen)
            {
                newStr[newStrIndex] = str[currentLine][currentLineIndex];
                currentLineIndex++;
                newStrIndex++;
            }
            currentLine++;
        }
    
    return newStr;
}

char* my_robot_simulator(char* a) {
    int i = 0;

    positions my_positions = {0, 0, NORTH};


    while (a[i] != '\0') {
        find_positions(&my_positions, a[i]);
        find_direction(&my_positions, a[i]);
        i++;
    }

    int len = strlen(my_new_str(my_positions.x, my_positions.y, my_positions.direction));

    char*str = malloc(sizeof(char) * len + 1);

    str = my_new_str(my_positions.x, my_positions.y, my_positions.direction);
    return str;
}

int main() {
    printf("%s\n", my_robot_simulator("RAARA"));
    return 0;
}
