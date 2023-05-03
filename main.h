#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define PRINT(a) _putchar(a)

/**
 * struct func_int - Handles integers
 *@c: The char to search for
 *@func: The function to call
 *
 */

typedef struct func_int
{
	const char *c;
	int (*func)(va_list *, int);
} find_spec;

void _putchar(char c);
int _printf(const char *, ...);
int print_char(va_list *, int);
int print_str(va_list *, int);
int print_int(va_list *, int);
int print_percent(va_list *, int);
int get_specifier(const char *, va_list *, int);
#endif /* MAIN_H */
