#include "main.h"

/**
 * get_handl_func - map specifier with appropriate function
 *
 * @s: specifier
 * @index: index for argument identifier
 *
 * Return: pointer to function
 */
int (*get_handl_func(const char *s, int index))(va_list, char *, unsigned int)
{
	handl_t hn[] = {
		{"c", handl_ch},
		{"s", handl_str},
		{NULL, NULL},
	};
	int i = 0;

	for (; hn[i].specifier; i++)
		if (s[index] == hn[i].specifier[0])
			return (hn[i].f);

	return (NULL);
}
