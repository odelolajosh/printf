#include "main.h"

/**
 * handl_oct - prints decimal number in octal
 *
 * @args: arguments
 * @buf: buffer pointer
 * @ibuf: index for buffer
 *
 * Return: number of chars printed
 */
int handl_oct(va_list args, char *buf, unsigned int ibuf)
{
	int input, i, isneg, count, first_digit;
	char *octal, *binary;

	input = va_arg(args, int);
	isneg = 0;
	if (input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (input < 0)
	{
		input = (input * -1) - 1;
		isneg = 1;
	}
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_decimal_to_binary(binary, input, isneg, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = fill_binary_to_oct(binary, octal);

	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handl_buf(buf, octal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count);
}

