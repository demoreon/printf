#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#define PRINT(a) _putchar(a)

void _putchar(char c);
int _printf(const char *format, ...);
int print_str(char *c, int len);

#endif /* MAIN_H */
