#include "my_lib.h"

/*
**
** QWASAR.IO -- my_array_uniq
**
** @param {integer_array*} param_1
**
** @return {integer_array*}
**
*/
#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

int check_doubles(integer_array* param_1, int position, int number)
{
 	int index = 0;
  	while (index < position)
    {
    	if (param_1->array[index] == number)
        {
         	return 1; 
        }
      	index++;
    }
  	return 0;
}

integer_array* my_array_uniq(integer_array* param_1)
{
	integer_array* my_array = malloc(sizeof(integer_array));
    int index;
    int my_index;
    index = 0;
    my_index = 0;
    int new_size = param_1->size;
    my_array->size = param_1->size;
    my_array->array = param_1->array;
    while (index < param_1->size || my_index < new_size)
    {        
        if (check_doubles(param_1, index, param_1->array[index]) == 1)
        {
            printf("func: check_doubles = %d with %d and index %d\n", check_doubles(param_1, index, param_1->array[index]), param_1->array[index], index);
            index++;
            new_size--;
        }
        else
        {
            printf("here\n");
            printf("my_index %d and index %d\n", my_index, index);
            my_array->array[my_index] = param_1->array[index];
            index++;
            my_index++;
        }
    }
    my_array->size = new_size;
    printf("func: size AFTER %d\n", my_array->size);
    printf("func: AFTER [%d, ", my_array->array[0]);
    printf("%d, ", my_array->array[1]);
    printf("%d, ", my_array->array[2]);
    printf("%d\n", my_array->array[3]);
  	return my_array;
}

int main()
{
    int size = 4;
    int array[4] = {0, 6, 6, 8};
    struct s_integer_array my_array = {size, array};

    printf("my_array BEFORE 2 [%d]\n", my_array.array[2]);
    integer_array* my_new = my_array_uniq(&my_array);
    printf("main: size is %d\n", my_new->size);
    printf("my new array AFTER [%d, ", my_new->array[0]);
    printf("%d, ", my_new->array[1]);
    printf("%d, ", my_new->array[2]);
    printf("%d\n", my_new->array[3]);
    return 0;
}