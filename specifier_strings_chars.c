#include <stdio.h>
#include "main.h"

/**
 * handle_char - handles format specifier c "%c"
 * to print character
 *
 * @character: character from the argument
 * @countByte: keeps count of the number of character printed in bytes
 *
 * Return: void (Nothing)
 */
void handle_char(char character, int *countByte)
{
	write(1, &character, BYTE);
	*countByte += BYTE;
}

/**
 * handle_string - handles format specifier s "%s"
 * to print stirng
 *
 * @str_buffer: string from the argument
 * @countByte: keeps count of the number of characters printed in bytes
 *
 * Return: void (Nothing)
 */
void handle_string(char *str_buffer, int *countByte)
{
	if (str_buffer != NULL)
	{
		write(1, str_buffer, strlen(str_buffer));

		*countByte += strlen(str_buffer);
	}
	else
	{
		write(1, "(null)", 6);
		*countByte += 6;
	}
}

/**
 * handle_percent - handles the format specifier % "%%"
 * to print percent sign
 *
 * @character: character from the argument
 * @countByte: keeps count of the number of character printed in bytes
 *
 * Return: void (Nothing)
 */
void handle_percent(char character, int *countByte)
{
	write(1, &character, BYTE);
	*countByte += BYTE;
}

/**
 * handle_reverse_string - handles the format specifier r "%r"
 * to print string reverse
 *
 * @str_buffer: string from argument
 * @countByte: keeps count of the number of characters printed out in bytes
 *
 * Return: void (Nothing)
 */
void handle_reverse_string(char *str_buffer, int *countByte)
{
	int length, i;

	i = 0;
	length = 0;

  /*not a null*/
	if (str_buffer != NULL)
	{

    /*get the length and minus by 1 to get the index*/
		i = strlen(str_buffer) - 1;

		while (i >= 0)
		{
			write(1, &str_buffer[i], BYTE); /*print from the last idex*/
			*countByte += BYTE;
			i--;
		}
	}
	else
	{
		write(1, "(null)", NULL_BYTE); /*a null to print*/
		*countByte += NULL_BYTE;
	}
}
