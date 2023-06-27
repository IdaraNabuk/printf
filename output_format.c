#include "main.h"

int _printf(const char *format, ...);

/**
 * main - Entry point to the program.
 *
 *Return: 0
 */

int main(void)
{
	_printf("Hello, %s! The answer is %d%c\n", "world", 42, '%');
	return (0);
}

/**
 *  _printf - Produces output according to a format.
 *  @format: Character string containing zero or more directives.
 *
 *  Return: Number of characters printed (excluding the null byte).
 */

int _printf(const char *format, ...)
{
	va_list items;
	int count = 0;

	va_start(items, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
				{
					/* Fetch the character argument using va_arg */
					int c = va_arg(items, int);

					putchar(c);
					count++;
					break;
				}
				case 's':
				{
					/* Fetch the string argument using va_arg */
					char *s = va_arg(items, char *);

					while (*s != '\0')
					{
						putchar(*s);
						s++;
						count++;
					}
					break;
				}
				case '%':
				{
					putchar('%');
					count++;
					break;
				}
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}

		format++;
	}

	va_end(items);
	return (count);
}
