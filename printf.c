#include "main.h"
#include <stdio.h>

/**
* _printf - produces output according to a format
* @format: format specifier
* Return: number of chars printed excluding null byte
*/

int _printf(const char *format, ...)
{
	va_list args;
	int i;
	char *str;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					_writechar((char)va_arg(args, int));
					break;
				case 'd':
				case 'i':
					print_number(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char *);
					print_string(str);
					break;
				default:
					_writechar('%');
					_writechar(format[i]);
					break;
			}
		}
		else
		{
			_writechar(format[i]);
		}

		i++;
	}

	va_end(args);
	return (i);
}

/**
* print_number - prints integer values
* @n: integer to print to std-out
*/

void print_number(int n)
{
	unsigned int number;

	if (n < 0)
	{
		number = -n;
		_writechar('-');
	}
	else
	{
		number = n;
	}

	if (number / 10)
		print_number(number / 10);

	_writechar('0' + (number % 10));
}

/**
* print_string - prints a string
* @str: string to print
*/

void print_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_writechar(str[i]);
}
