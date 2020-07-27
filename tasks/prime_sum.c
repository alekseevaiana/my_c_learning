#include <stdio.h>

int is_prime(int num)
{
    int index;
    int max_del;
    max_del = num / 2;
    index = 2;
    while (index <= max_del)
    {
        if (num % index == 0)
        {
            return 0;
        }
        index++;
    }
    return 1;
}

int add_prime_sum(int param_1)
{
    int result;
  	int index;
  	if (param_1 <= 1)
    {
    	result = 0;
    }
  	else if (param_1 >= 2)
    {
      	index = 2;
        result = param_1;
     	 while (index <= param_1)
         {
          	if (is_prime(index) == 1)
            {
             	result = result + index; 
            }
           	index++;
         }
    }
  	return result;
}

int main()
{
    printf("%d\n", add_prime_sum(17));
    return 0;
}