#include "main.h"
#include <stdio.h>

/**
 * _printf - produces output according to a format
 *
 * @format: given string
 *
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	unsigned int len = 0, i = 0, ibuf;
	char *buffer;
	int (*handler)(va_list, char *, unsigned int);
	va_list args;

	va_start(args, format), buffer = malloc(sizeof(char) * 1024);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				print_buf(buffer, ibuf), free(buffer), va_end(args);
				return (-1);
			}
			else if (format[i] == '%')
				handl_buf(buffer, format[i], ibuf), len++;
			else
			{
				handler = get_handl_func(format, i);
				if (handler == NULL)
				{
					handl_buf(buffer, format[i], ibuf);
					len++, i--;
				}
				else
					len += handler(args, buffer, ibuf);
			}
		}
		else
		handl_buf(buffer, format[i], ibuf), len++;
		i++, ibuf = len;
		while (ibuf > 1024)
			ibuf -= 1024;
	}
	print_buf(buffer, ibuf), free(buffer), va_end(args);
	return (len);
}
