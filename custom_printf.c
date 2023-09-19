#include "main.h"
#include <stdarg.h>
#include <unistd.h> /* For write */

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Variable number of arguments
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0; /* Initialize the character count */
	int character; /* Variable to store a character from va_arg */

	va_start(args, format); /* Initialize the va_list */

	while (format && *format)
	{
		if (*format == '%')
		{
			format++; /* Move past '%' */

			/* Handle format specifiers */
			if (*format == 'c')
			{
				character = va_arg(args, int);
				write(1, &character, 1); /* Print character */
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str)
				{
					while (*str)
					{
						write(1, str, 1);
						/**
						 * Print each character
						 * of the string
						 */
						str++;
						count++;
					}
				}
				else
				{
					/* Handle NULL string */
					write(1, "(null)", 6);
					count += 6;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				/**
				 * Print percent sign
				 */
				count++;
			}
		}
		else
		{
			write(1, format, 1);
			/**
			 * Print non-format specifier character
			 */
			count++;
		}
		format++; /* Move to the next character in the format string */
	}

	va_end(args); /* Clean up the va_list */

	return (count);
}

/** To test
*int main(void)
*{
*	int len;
*
*	len = _printf("Characters: %c\n", 'A');
*	_printf("Length: %d\n", len);
*
*	len = _printf("Strings: %s\n", "Hello World!");
*	_printf("Length: %d\n", len);
*
*	len = _printf("Percent: %%\n");
*	_printf("Length: %d\n", len);
*
*	return (0);
*}
*/
