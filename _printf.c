#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 *
 * @format: given string
 *
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	unsigned int len = 0, i = 0;
	char* out_string;
	va_list args;
	va_start(args, format);

	while (format && format[i])
	{
		++i; ++len;
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				out_string[i] = '%';
				continue;
			}
			else if (format[i + 1] == 'c')
			{
				char c = va_args(args, char);
				out_string[i];
			}
		}
		out_string[i] = format[i];
	}
	return (len);
}
