#include "main.h"

/**
 * handl_ch - handles writing character to stdout
 *
 * @args: arguments
 * @buf: buffer pointer
 * @bufferIndex: index for buffer pointer
 *
 * Return: length of char addition
 */
int handl_ch(va_list args, char *buf, unsigned int bufferIndex)
{
	char c;

	c = va_arg(args, int);
	handl_buf(buf, c, bufferIndex);

	return (1);
}

