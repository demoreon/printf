#include "main.h"

/**
 * _write_string - writes a string to stdout
 * @str: the string to write
 *
 * Return: the number of characters written
 */
int _write_string(char *str)
{
	char *start = str; /* pointer to the start of the string */

	while (*str)
		_putchar(*str++); /* write each character to stdout */
	return (str - start); /* return the number of characters written */
}

/**
 * _putchar - writes the character c to stdout
 * @c: the character to write
 *
 * Return: On success 1, on error -1 is returned and errno is set as required
 */
int _putchar(int c)
{
	static int index = 0; /* index of next available position in buffer */
	static char buffer[OUTPUT_BUFFER_SIZE]; /* buffer to store characters */

	if (c == FLUSH_BUFFER || index >= OUTPUT_BUFFER_SIZE)
	{
		write(STDOUT_FILENO, buffer, index); /* write the buffer to stdout */
		index = 0; /* reset the buffer index */
	}
	if (c != FLUSH_BUFFER)
		buffer[index++] = c; /* add the character to the buffer */
	return (1);
}
