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

	if (num == 0)
	{
		PRINT('0');
		len++;
		return (len);
	}
	if (num == INT_MIN)
	{
		PRINT('-');
		PRINT('2');
		len += 2;
		num = 147483648;
	} else if (num < 0)
	{
		PRINT('-');
		len++;
		num = -num;
	}
	while (num / div >= 10) /* scale div to the dividend value */
		div *= 10;
	while (div > 0)
	{
		PRINT(num / div + 48);
		num %= div;
		div /= 10;
		len++;
	}
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
	int i = 0;

	s = va_arg(*args, char *); /* add va_arg here */
	if (s == NULL)
		s = "(null)";
	while (s[i] != '\0' && i <= 1024)
	{
		i++;
		len++;
	}
	write(STDOUT_FILENO, s, i);
	return (len);
}
