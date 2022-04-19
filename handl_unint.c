#include "main.h"

/**
 * handl_unint - prints an unsigned int
 *
 * @args: arguments
 * @buf: buffer
 * @ibuf: buffer index
 *
 * Return: number of chars printed
 */
int handl_unint(va_list args, char *buf, unsigned int ibuf)
{
	unsigned int input, d, i, count;

	input = va_arg(args, unsigned int);
	d = input, count = 1;
	while (d > 9)
		d /= 10, count *= 10;

	for (i = 0; count >= 1; count /= 10, i++)
		ibuf = handl_buf(buf, ((input / count) % 10) + '0', ibuf);

	return (i);
}

