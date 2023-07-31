#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define PRINT(a) _putchar(a)
#define BUF_MAX 1024

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

int buffer_pro(char *buf, int len);
void _putchar(char c);
int _printf(const char *, ...);
int p_char(va_list *, int);
int p_str(va_list *, int);
int p_int(va_list *, int);
int p_lint(va_list *, int);
int p_hint(va_list *, int);
int p_percent(va_list *, int);
int p_binary(va_list *, int);
int p_usigned_int(va_list *, int);
int p_octal(va_list *, int len);
int p_hex(va_list *, int len);
int p_hex_helper(unsigned int, int);
int p_int_helper(long int, int);
int p_addr(va_list *, int len);
int get_flag(const char *chr);
int get_specifier(const char *, va_list *, int);
#endif /* MAIN_H */
