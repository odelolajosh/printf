#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct handler - Struct handler
 *
 * @spec - Given string
 * @f - handler function
 */
typedef struct handl
{
	char *specifier;
	int (*f)(va_list, char *, unsigned int);
} handl_t;

int _printf(const char *format, ...);
int (*get_handl_func(const char *, int))(va_list, char *, unsigned int);
int print_buf(char *, unsigned int);
unsigned int handl_buf(char *, char, unsigned int);
int handl_ch(va_list, char *, unsigned int);
int handl_str(va_list, char *, unsigned int);
int handl_int(va_list, char *, unsigned int);
int handl_bnr(va_list, char *, unsigned int);
int handl_unint(va_list, char *, unsigned int);
int handl_oct(va_list, char *, unsigned int);
int handl_hex(va_list, char *, unsigned int);
int handl_uppx(va_list, char *, unsigned int);
int handl_S(va_list, char *, unsigned int);
int handl_addr(va_list, char *, unsigned int);
int handl_rev(va_list, char *, unsigned int);
int handl_rot(va_list, char *, unsigned int);

char *fill_decimal_to_binary(char *, long int, int, int);
char *fill_binary_to_oct(char *, char *);
char *fill_binary_to_hex(char *bnr, char *hex, int isupp, int limit);

#endif /* _MAIN_H_ */

