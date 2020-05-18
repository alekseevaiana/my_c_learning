#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int print_str(char* str)
{
    int i;

    i = 0;
    if (str != NULL)
    {
        while (str[i] != 0)
        {
            my_putchar(str[i]);
            i++;
        }
        return i;
    }
    return 0;
}

int u_decimal_to_str(unsigned int nb)
{
    int i;

    i = 0;
    if (nb >= 10)
    {
        i = i + u_decimal_to_str(nb / 10);
        i = i + u_decimal_to_str(nb % 10);
    }
    else
    {
        my_putchar(nb + '0');
        i++;
    }
    return i;
}

int decimal_to_str(int nb)
{
    int i;

    i = 0;
    if (nb < 0)
    {
        nb = nb * -1;
        my_putchar('-');
        i++;
    }
    i = i + u_decimal_to_str(nb);
    return i;
}

int to_octal_str(unsigned int nb)
{
    int i;

    i = 0;
    if (nb >= 8)
    {
        i = i + to_octal_str(nb / 8);
        i = i + to_octal_str(nb % 8);
    }
    else
    {
        my_putchar(nb + '0');
        i++;
    }
    return i;
}

int to_hexadecimal(unsigned long int nb)
{
    int i;

    i = 0;
    if (nb >= 16)
    {
        i = i + to_hexadecimal(nb / 16);
        i = i + to_hexadecimal(nb % 16);
    }
    else if (nb >= 10 && nb < 16)
    {
        i++;
        if (nb == 10)
        {
            my_putchar('a');
        }
        else if (nb == 11)
        {
            my_putchar('b');
        }
        else if (nb == 12)
        {
            my_putchar('c');
        }
        else if (nb == 13)
        {
            my_putchar('d');
        }
        else if (nb == 14)
        {
            my_putchar('e');
        }
        else if (nb == 15)
        {
            my_putchar('f');
        }
    }
    else
    {
        i++;
        my_putchar(nb + '0');
    }
    return i;
}

int my_printf(char* fmt, ...)
{
    va_list ap;
    char* p;
    char* sval;
    int ival;
    unsigned int uival;
    intptr_t ptr;
    int size;
    int count;

    va_start(ap, fmt);
    count = 0;
    size = 0;
    for (p = fmt; *p; p++)
    {
        if (*p != '%')
        {
            my_putchar(*p);
            count++;
            continue;
        }
        switch (*++p)
        {
            case 'c':
                ival = va_arg(ap, int);
                my_putchar(ival);
                size++;
                break;
            case 's':
                sval = va_arg(ap, char*);
                size = size + print_str(sval);
                break;
            case 'd':
                ival = va_arg(ap, int);
                size = size + decimal_to_str(ival);
                break;
            case 'u':
                uival = va_arg(ap, unsigned int);
                size = size + u_decimal_to_str(uival);
                break;
            case 'o':
                uival = va_arg(ap, unsigned int);
                size = size + to_octal_str(uival);
                break;
            case 'x':
                ptr = va_arg(ap, intptr_t);
                size = size + to_hexadecimal(ptr);
                break;
            case 'p':
                ptr = va_arg(ap, intptr_t);
                size = print_str("0x");
                size = size + to_hexadecimal(ptr);
                break;
            default:
                my_putchar(*p);
                count++;
                break;
        }
    }
    va_end(ap);
    return size + count;
}
