#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

void my_putchar(char c) {
    write(1, &c, 1);
}

void print_str(char* str) {
    while(*str) {
        my_putchar(*str);
        str++;
    }
}

void decimalToStr(int nb) {
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
	if(nb >= 10)
	{
		decimalToStr(nb / 10);
		decimalToStr(nb % 10);
	}
	else
		my_putchar(nb + 48);
}

void uDecimalToStr(unsigned int nb) {
	if(nb >= 10)
	{
		uDecimalToStr(nb / 10);
		uDecimalToStr(nb % 10);
	}
	else
		my_putchar(nb + 48);
}

void toOctalStr(unsigned int nb) {
    if (nb >= 8)
	{
		toOctalStr(nb / 8);
		toOctalStr(nb % 8);
	}
    else
		my_putchar(nb + 48);
}

void toHexadecimal(unsigned long int nb) {
    if (nb >= 16)
	{
		toHexadecimal(nb / 16);
		toHexadecimal(nb % 16);
	}
    else if (nb >=10 && nb < 16) {
        if (nb == 10) {
            my_putchar('a');
        }
        else if (nb == 11) {
            my_putchar('b');
        }
        else if (nb == 12) {
            my_putchar('c');
        }
        else if (nb == 13) {
            my_putchar('d');
        }
        else if (nb == 14) {
            my_putchar('e');
        }
        else if (nb == 15) {
            my_putchar('f');
        }
    }
    else
		my_putchar(nb + 48);
}

int my_printf(char* fmt, ...) {
    va_list ap;
    char* p;
    char* sval;
    int ival;
    unsigned int uival;
    intptr_t ptr;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            my_putchar(*p);
            continue;
        }
        switch (*++p) {
        case 'c':
            ival = va_arg(ap, int);
            my_putchar(ival);
            break;
        case 's':
            sval = va_arg(ap, char*);
            print_str(sval);
            break;
        case 'd':
            ival = va_arg(ap, int);
            decimalToStr(ival);
            break;
        case 'u':
            uival = va_arg(ap, unsigned int); 
            uDecimalToStr(uival);
            break;
        case 'o':
            uival = va_arg(ap, unsigned int);
            toOctalStr(uival);
            break;
        case 'x':
            ptr = va_arg(ap, intptr_t);
            toHexadecimal(uival);
            break;
        case 'p':
            ptr = va_arg(ap, intptr_t);
            print_str("0x");
            toHexadecimal(ptr);
            break;
        default:
            my_putchar(*p);
            break;
        }
    }
    va_end(ap);
    return 0;
}

int main() {
    char* lStr = "Hello";
    char letter = 'a';
    // printf("%c\n", letter);
    // printf("printf %%p %p\n", lStr);
    // my_printf("my putchar %c\n", letter);
    // my_printf("my to str %s is %c number %d\n", "letter", letter, -014);
    // printf("printf %s is %c x number %x\n", "letter", letter, 351);
    // my_printf("my_printf %s is %c x number %x\n", "letter", letter, 351);
    my_printf("my_printf %x\n", 351);
    my_printf("my_printf %x\n", 351);
    printf("printf %%p %p\n", lStr);
    my_printf("my_printf %p\n", lStr);
    return 0;
}
