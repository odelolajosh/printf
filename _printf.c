#include "main.h"
#include <stdio.h>

/**
 * _format - replaces format specifiers with arguments
 *
 * @format: given string
 * @args: arguments
 *
 * Return: number of chars printed
 */
int _format(const char *format, va_list args)
{
	unsigned int len = 0, i = 0, ibuf = 0;
	char *buffer;
	int (*handler)(va_list, char *, unsigned int);

	buffer = malloc(sizeof(char) * 1024);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				handl_buf(buffer, format[i], ibuf), len++;
			else if (format[i] == '\0')
			{
				print_buf(buffer, ibuf), free(buffer);
				return (-1);
			}
			else
			{
				handler = get_handl_func(format, i);
				if (handler == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					len++, i--, handl_buf(buffer, format[i], ibuf);
				}
				else
					len += handler(args, buffer, ibuf);
			}
		}
		else
			handl_buf(buffer, format[i], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	}
	print_buf(buffer, ibuf), free(buffer);
	return (len);
}


/**
 * _printf - produces output according to a format
 *
 * @format: given string
 *
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	unsigned int len = 0;
	va_list args;

	va_start(args, format);
	len = _format(format, args);
	va_end(args);
	return (len);
}
