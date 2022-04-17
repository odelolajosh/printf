#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>

/**
 * struct handler - Struct handler
 *
 * @spec - Given string
 * @f - handler function
 */
typedef struct handler
{
	char *specifier;
	int (*f)(va_list, char *, unsigned int);
} handler_t

int _printf(const char *format, ...);

#endif /* _MAIN_H_ */
