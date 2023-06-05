#include "main.h"

/**
 * p_int - This handles the %d and %i output
 * @args: The integer to print
 * @len: The current len
 * Return: Updated len
 */

int p_int(va_list *args, int len)
{
	int num = va_arg(*args, int);
	int div = 1;
	char buf[BUF_MAX];
	int c = 0; /* buffer index tracker */

	if (num == 0)
	{
		PRINT('0');
		len++;
		return (len);
	}
	if (num == INT_MIN)
	{
		buf[c] = '-';
		c++;
		buf[c] = '2';
		c++, len += 2;
		num = 147483648;

	} else if (num < 0)
	{
		buf[c] = '-';
		num = -num;
	}
	while (num / div >= 10) /* scale div to the dividend value */
		div *= 10;
	while (div > 0)
	{
		if (c == BUF_MAX)
			c = buffer_pro(buf, c);
		buf[c] = num / div + 48;
		num %= div;
		div /= 10;
		len++, c++;
	}
	buf[c] = '\0';
	if (c) /* Check buffer not empty */
		buffer_pro(buf, c);
	return (len);
}

/**
 * _putchar - prints a character literal
 * @c: The argument to print
 */

void _putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

/**
 * p_char - prints a character literal
 * @args: The integer to print
 * @len: The current len of characters
 * Return: Returns the len
 */

int p_char(va_list *args, int len)
{
	/* (void)args; */
	PRINT(va_arg(*args, int));
	len++;
	return (len);
}

/**
 * p_percent - prints a percent sign
 * @args: The integer to print
 * @len: The current len of characters
 * Return: Returns the len
 */

int p_percent(va_list *args, int len)
{
	(void)args; /* suppress "unused parameter" warning by casting to void */
	PRINT('%');
	len++;
	return (len);
}

/**
 * p_str - prints an array of character literal
 * @args: The string  to print
 * @len: The current len of characters
 * Return: Returns the len
 */

int p_str(va_list *args, int len)
{
	char *s;
	char buf[BUF_MAX];
	int c = 0; /* buffer index tracker */

	s = va_arg(*args, char *);
	if (s == NULL)
		s = "(null)";
	while (*s != '\0')
	{
		if (c == BUF_MAX)
			c = buffer_pro(buf, c);
		buf[c] = *s;
		c++;
		s++;
		len++;
	}
	buf[c] = '\0';

	if (c) /* Check buffer not empty */
		buffer_pro(buf, c);

	return (len);
}
