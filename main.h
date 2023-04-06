#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUFFER_SIZE 1024
#define FLUSH_BUFFER -1

#define FIELD_BUFFER_SIZE 50

#define NULL_STR "(null)"

#define PARAMETER_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CV_LCASE	1
#define CV_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: f if unsigned value
 *
 * @plus_f: on if plus_f specified
 * @space_f: on if hashtag_f specified
 * @hashtag_f: on if _f specified
 * @zero_f: on if _f specified
 * @minus_f: on if _f specified
 *
 * @width: field width specified
 * @prec: field precision specified
 *
 * @h_mod: on if h_mod is specified
 * @l_mod: on if l_mod is specified
 *
 */

typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_f		: 1;
	unsigned int space_f		: 1;
	unsigned int hashtag_f	: 1;
	unsigned int zero_f		: 1;
	unsigned int minus_f		: 1;

	unsigned int width;
	unsigned int prec;

	unsigned int h_mod		: 1;
	unsigned int l_mod		: 1;
} parameters_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, parameters_t *);
} spec_t;

/* _put.c module */
int _write_string(char *str);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list arg_list, parameters_t *p);
int print_int(va_list arg_list, parameters_t *p);
int print_string(va_list arg_list, parameters_t *p);
int print_percent(va_list arg_list, parameters_t *p);
int print_S(va_list arg_list, parameters_t *p);

/* number.c module */
char *convert(long int num, int base, int fs, parameters_t *p);
int print_unsigned(va_list arg_list, parameters_t *p);
int print_address(va_list arg_list, parameters_t *p);

/* specifier.c module */
int (*get_specifier(char *s))(va_list arg_list, parameters_t *p);
int get_print_func(char *s, va_list arg_list, parameters_t *p);
int get_f(char *s, parameters_t *p);
int get_modifier(char *s, parameters_t *p);
char *get_width(char *s, parameters_t *p, va_list arg_list);

/* convert_number.c module */
int print_hex(va_list arg_list, parameters_t *p);
int print_HEX(va_list arg_list, parameters_t *p);
int print_binary(va_list arg_list, parameters_t *p);
int print_octal(va_list arg_list, parameters_t *p);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list arg_list, parameters_t *p);
int print_rot13(va_list arg_list, parameters_t *p);

/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, parameters_t *p);
int print_number_right_shift(char *str, parameters_t *p);
int print_number_left_shift(char *str, parameters_t *p);

/* p.c module */
void init_p(parameters_t *p, va_list arg_list);

/* string_fields.c modoule */
char *get_precision(char *s, parameters_t *p, va_list arg_list);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif /*_PRINTF_H_*/
