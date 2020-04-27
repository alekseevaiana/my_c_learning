#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEV 0

#ifdef DEV
typedef struct s_string_array {
    int size;
    char** array;
 } string_array;
#endif

int size_of_string_array(string_array* a) {
    int len = 0;
    int i = 0;
    while (i < a->size) {
        len = len + strlen(a->array[i]);
        i++; 
    }
    return len;
}

int copy_str(char* target, char* source) {
    int i = 0;
    while(source[i] != '\0') {
        target[i]=source[i];
        i++;
    }
    return i;
}

char* my_join(string_array* a, char* b) {
    if (a->size == 0) {
        return NULL;
    }

    int separators_total_length = strlen(b) * (a->size - 1);
    int total_strings_length = size_of_string_array(a);
    int total_length = separators_total_length + total_strings_length + 1;

    char* str = malloc(sizeof(char) * total_length);
    
    int i = 0;
    int pos = 0;
    while(i < a->size) {
        pos = pos + copy_str(str + pos, a->array[i]);
        if (i < (a->size-1)) {
          pos = pos + copy_str(str + pos, b);
        }
        i++;
    }
    str[pos] = '\0';
    return str;
}

#ifdef DEV
int main() {
    char* foo[] = {};
    string_array my_string_array = {0, foo};
    printf("%s", my_join(&my_string_array, " ")); 
    return 0;
}
#endif

