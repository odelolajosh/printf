#include "main.h"

/**
 * handl_bnr - prints decimal in binary
 *
 * @args: arguments
 * @buf: buffer
 * @ibuf: buffer index
 *
 * Return: number of chars printed
 */
int handl_bnr(va_list args, char *buf, unsigned int ibuf)
{
	int input, count, i, first_one, isneg = 0;
	char *binary;

	input = va_arg(args, int);
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
	first_one = 0;

	for (count = i = 0; binary[i]; i++)
	{
		if (first_one == 0 && binary[i] == '1')
			first_one = 1;
		if (first_one == 1)
		{
			ibuf = handl_buf(buf, binary[i], ibuf);
			count++;
		}
	}
	free(binary);
	return (count);
}
