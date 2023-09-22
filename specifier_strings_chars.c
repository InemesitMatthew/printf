#include "main.h"

/**
 * handle_char - handles format specifier c "%c"
 * to print character
 *
 * @character: character from the argument
 *
 * Return: void (Nothing)
 */
int handle_char(char character)
{
	write(1, &character, BYTE);

	return (BYTE);
}

/**
 * handle_string - handles format specifier s "%s"
 * to print stirng
 *
 * @str_buffer: string from the argument
 *
 * Return: void (Nothing)
 */
int handle_string(char *str_buffer)
{
	int length;

	length = strlen(str_buffer);
	if (str_buffer != NULL)
	{
		write(1, str_buffer, length);

		return (length);
	}
	else
	{
		write(1, "(null)", NULL_BYTE);

		return (NULL_BYTE);
	}
}

/**
 * handle_percent - handles the format specifier % "%%"
 * to print percent sign
 *
 * @character: character from the argument
 *
 * Return: void (Nothing)
 */
int handle_percent(char character)
{
	write(1, &character, BYTE);

	return (BYTE);
}

/**
 * handle_reverse_string - handles the format specifier r "%r"
 * to print string reverse
 *
 * @str_buffer: string from argument
 *
 * Return: void (Nothing)
 */
int handle_reverse_string(char *str_buffer)
{
	int i, countByte;

	i = 0;

	/*not a null*/
	if (str_buffer != NULL)
	{

		/*get the length and minus by 1 to get the index*/
		i = strlen(str_buffer) - 1;

		while (i >= 0)
		{
			write(1, &str_buffer[i], BYTE); /*print from the last idex*/
			countByte += BYTE;
			i--;
		}

		return (countByte);
	}
	else
	{
		write(1, "(null)", NULL_BYTE); /*a null to print*/

		return (NULL_BYTE);
	}
}
