#ifndef PRINTF
#define PRINTF

/*programs macros*/
#define NULL_BYTE 6
#define UINT_SIZE 32
#define BYTE 1

/*system headers*/
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int _printf(const char *format, ...);

/**
 * handle_char - handles format specifier c "%c"
 * to print character
 *
 * @character: character from the argument
 * @countByte: keeps count of the number of character printed in bytes
 *
 * Return: void (Nothing)
 */
void handle_char(char character, int *countByte);

/**
 * handle_string - handles format specifier s "%s"
 * to print stirng
 *
 * @str_buffer: string from the argument
 * @countByte: keeps count of the number of characters printed in bytes
 *
 * Return: void (Nothing)
 */
void handle_string(char *str_buffer, int *countByte);

/**
 * handle_percent - handles the format specifier % "%%"
 * to print percent sign
 *
 * @character: character from the argument
 * @countByte: keeps count of the number of character printed in bytes
 *
 * Return: void (Nothing)
 */
void handle_percent(char character, int *countByte);

/**
 * handle_reverse_string - handles the format specifier r "%r"
 * to print string reverse
 *
 * @str_buffer: string from argument
 * @countByte: keeps count of the number of characters printed out in bytes
 *
 * Return: void (Nothing)
 */
void handle_reverse_string(char *str_buffer, int *countByte);

/**
 * handle_integers - handles the format specifier d and i "%d", "%i"
 * to print integers
 *
 * @number: number from the argument
 * @countByte: keeps count of the numbers of each digit, printed in bytes
 *
 * Return: void (Nothing)
 */
void handle_integers(int number, int *countByte);

/**
 * handle_binary - handle the format specifier b "%b"
 *
 * @number: number from the argument
 * @countByte: keeps count of the binary number of each digit
 * printed int bytes
 *
 * Return: void (Nothing);
 */
void handle_binary(int number, int *countByte);

/**
 * handle_unsigned_integers - handles the format specifier u "%u"
 * to print unsigned integers
 *
 * @number: unsigned integer from argument
 * @countByte: keeps count of the number of each digit, printed in bytes
 *
 * Return: void (Nothing)
 */
void handle_unsigned_integers(unsigned int number, int *countByte);

#endif /* PRINTF */
