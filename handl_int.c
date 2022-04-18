#include "main.h"

/**
 * handl_int - prints an integer
 *
 * @args: arguments
 * @buf: buffer pointer
 * @ibuf: index for the buffer
 *
 * Return: number of chars printed
 */
int handl_int(va_list args, char *buf, unsigned int ibuf)
{
	int input;
	unsigned int abs, count, i, d, isneg;

	input = va_arg(args, int);
	isneg = 0;
	if (input < 0)
	{
		abs = input * -1;
		ibuf = handl_buf(buf, '-', ibuf);
		isneg = 1;
	}
	else
	{
		abs = input;
	}

	d = abs, count = 1;
	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (i = 0; count >= 1; count /= 10, i++)
		ibuf = handl_buf(buf, ((abs / count) % 10) + '0', ibuf);

	return (i + isneg);
}

