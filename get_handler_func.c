#include "main.h"

int (*get_handler_func(const char *s, int index ))(va_list, char *, unsigned int)
{
	handler_t hn[] = {
		{"c", handle_ch},
		{"s", handle_str},
		{NULL, NULL},
	}
	int i = 0;

	while (hn[i].specifier)
		if (s[index] == pr[i].specifier[0])
			return (pr[i].fn);
}
