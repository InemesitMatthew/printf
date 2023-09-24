#include "main.h"

struct specifierHandlers specifierHandlers[]
	= {{'b', handle_binary},
	   {'c', handle_char},
	   {'d', handle_integers},
	   {'i', handle_integers},
	   {'u', handle_unsigned_integers},
	   {'o', handle_octal},
	   {'x', handle_lowerCase_hexadecimal},
	   {'X', handle_upperCase_hexadecimal},
	   {'p', handle_pointer},
	   {'s', handle_string},
	   {'S', handle_upperCase_S},
	   {'%', handle_percent},
	   {'r', handle_reverse_string},
	   {'R', handle_rot13}};

/**
 * _printf - Custom printf function
 *
 * @format: The format string
 * @...: Variable number of arguments
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;

	count = 0;

	va_start(args, format); /* Initialize the va_list */

	count += handle_format_string(format, args);

	va_end(args); /* Clean up the va_list */
	return (count);
}

/**
 * handle_format_string - Processes a format string,
 * prints it out, replacing format specifiers with
 * values from the argument list.
 *
 * @format: The format string, may contain zero or more
 * format specifiers.
 * @args: A va_list containing arguments to replace the
 * format specifiers.
 *
 * Return: The number of characters printed, excluding
 * the null byte.
 */
int handle_format_string(const char *format, va_list args)
{
	int count, i, size;
	bool match_found;

	count = 0, match_found = false;
	size = sizeof(specifierHandlers) / sizeof(specifierHandlers[0]);

	if (format == NULL)
		return (-1); /* Error */

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, BYTE);
			count++;
		}
		else
		{
			format++; /* Move past '%' to the next character */
			for (i = 0; i < size; i++)
			{
				/* Check if the format matches any specifier from the array */
				if (specifierHandlers[i].specifier == *format)
				{
					count += specifierHandlers[i].handler(args);
					match_found = true;
					break; /* Move to the next format */
				}
			}
			/* No match after loop, so execute */
			if (!match_found)
			{
				write(1, "%", BYTE);
				write(1, format, BYTE);
				count += (BYTE + BYTE);
			}
		}
		format++;
	}
	return (count);
}
