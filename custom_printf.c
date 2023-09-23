#include <stdio.h>
#include "main.h"

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

	int count, num_int;	/* num_int is number as an integer */
	unsigned int num_un; /* num_un is a number as an unsigned integer */
	void *ptr;
	char *str;

	char buffer[1024]; /* Local buffer for write */
	char character;

	char *str_buffer = buffer; /* Pointer to buffer for string handling */

	va_start(args, format); /* Initialize the va_list */

	if (format == NULL)
		return (-1); /* Return error, it a null*/

	count = 0;
	while (*format)
	{
		if (*format == '\0') /* Break immediately you meet a null */
			break;

		if (*format != '%')
		{
			write(1, format, BYTE);
			count += BYTE;
		}
		else
		{
			 /* Move past '%' check the next character to determine how to format */
			format++;
			switch (*format) /* Handle format specifier */
			{
			case 'b':
				/* Handle binary conversion */
				num_un = va_arg(args, unsigned int);
				count += handle_binary(num_un);
				break;

			case 'c':
				/* Handle character conversion */
				character = va_arg(args, int);
				count += handle_char(character);
				break;

			case 'd':
			case 'i':
				/* Handle decimal and integer conversion */
				num_int = va_arg(args, int);
				count += handle_integers(num_int);
				break;

			case 'u':
				/* Handle unsigned integer conversion */
				num_un = va_arg(args, unsigned int);
				count += handle_unsigned_integers(num_un);
				break;

			case 'o':
				/* Handle octal conversion */
				num_un = va_arg(args, unsigned int);
				count += handle_octal(num_un);
				break;

			case 'x':
				/* Handle lowercase hexadecimal conversion */
				num_un = va_arg(args, unsigned int);
				count += handle_lowerCase_hexadecimal(num_un);
				break;

			case 'X':
				/* Handle uppercase hexadecimal conversion */
				num_un = va_arg(args, unsigned int);
				count += handle_upperCase_hexadecimal(num_un);
				break;

			case 'p':
				/* Handle pointer conversion */
				ptr = va_arg(args, void *);
				count += handle_pointer(ptr);
				break;

			case 's':
				/* Handle string conversion */
				str_buffer = va_arg(args, char *);
				count += handle_string(str_buffer);
				break;

      case 'S':
          str_buffer = va_arg(args, char *);
          count += handle_upperCase_S(str_buffer);
          break;

			case '%':

				count += handle_percent(*format);
				break;

			case 'r':
				/* Handle reversed string conversion */
				str = va_arg(args, char *);
				count += handle_reverse_string(str);
				break;

			case 'R':
				/* Handle rot13'ed string conversion */
				str = va_arg(args, char *);
				count += handle_rot13(str);
				break;

			default:
				/* Handle unsupported format specifier */
				write(1, "%", 1);
				write(1, format, 1);
				count += 2;
				break;
			}
		}
		format++; /* Move to the next character in the format string */
	}
	va_end(args); /* Clean up the va_list */

	return (count);
}
