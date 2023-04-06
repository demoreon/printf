#include "main.h"

/**
 * _printf - prints and input into the standard output
 * @format: the format string
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)

{
	int sum = 0;
	va_list arg_list;
	char *p, *start;

	parameters_t p = PARAMETER_INIT;

	va_start(arg_list, format);

	if (!format || (format[0] == '%' && !format[1]))/* checking for NULL char */
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&p, arg_list);
		if (*p != '%')/*checking for the % specifier*/
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &p)) /* while char at p is flag character */
		{
			p++; /* next character */
		}
		p = get_width(p, &p, arg_list);
		p = get_precision(p, &p, arg_list);
		if (get_modifier(p, &p))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
					p.l_mod || p.h_mod ? p - 1 : 0);
		else
			sum += get_print_func(p, arg_list, &p);
	}
	_putchar(FLUSH_BUFFER);
	va_end(arg_list);
	return (sum);
}
