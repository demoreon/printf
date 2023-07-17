#include "main.h"

/**
 * p_int_helper - This handles the %d and %i output
 * @num: The integer to print
 * @len: The current len
 * Return: Updated len
 */

int p_int_helper(long num, int len)
{
	if (num == 0)
		return (len);
	len = p_int_helper(num / 10, len);
	PRINT(num % 10 + 48);

	return (++len);
}

/**
 * p_int - This handles the %d and %i output
 * @args: The integer to print
 * @len: The current len
 * Return: Updated len
 */

int p_int(va_list *args, int len)
{
	long num = va_arg(*args, int);
	if (len >= 2999 && num >= 0)
	{
		PRINT('+');
		len++;
	}
	else if (len >= 1999 && num >= 0)
	{
		PRINT(' ');
		len++;
	}
	if (len >= 2999)
		len -= 3000;
	else if (len >= 2499)
		len -= 2500;
	else if (len >= 1999)
		len -= 2000;
	if (num == 0)
	{
		PRINT('0');
		return (++len);
	}
	if (num < 0)
	{
		PRINT('-');
		len++;
		num = -num;
	}
	len = p_int_helper(num, len);
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
		if (len >= 1999)
		{
			if (*s < 32 || *s >= 127)
			{
				PRINT('\\');
				PRINT('x');
				if (*s < 16)
					PRINT('0'), len++;
				len = p_hex_helper(*s, len);
				len += 2, s++;
			}
			else
			{
				PRINT(*s);
				s++, len++;
			}
		}
		else
		{
			if (c == BUF_MAX)
				c = buffer_pro(buf, c);
			buf[c] = *s;
			c++;
			s++, len++;
		}
	}
	buf[c] = '\0';
	if (c) /* Check buffer not empty */
		buffer_pro(buf, c);
	return (len >= 1999 ? len - 2000 : len);
}
