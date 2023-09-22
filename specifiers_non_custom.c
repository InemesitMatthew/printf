#include "main.h"
#include <stdarg.h>

/**
 * handle_precision - Handles the precision for non-custom conversion specifiers.
 *
 * @args: Arguments list containing the value to be formatted
 * @format: The format specifier character ('d', 'i', 'u', 'o', 'x', 'X')
 *
 * Return: The count of characters printed
 */
int handle_precision(va_list args, char format)
{
    int count = 0;
    char num_buffer[UINT_SIZE]; /* Adjust the buffer size as needed */

    if (format == 'd' || format == 'i')
    {
        int num = va_arg(args, int);
        /* Implement precision handling for 'd' and 'i' format specifiers */
        /* You can use snprintf to format the number with precision and count the characters */
        int length = snprintf(num_buffer, sizeof(num_buffer), "%d", num);
        if (length > 0)
        {
            write(1, num_buffer, length);
            count += length;
        }
    }
    else if (format == 'u' || format == 'o' || format == 'x' || format == 'X')
    {
        unsigned int num = va_arg(args, unsigned int);
        /* Implement precision handling for 'u', 'o', 'x', and 'X' format specifiers */
        /* You can use snprintf to format the number with precision and count the characters */
        int length = snprintf(num_buffer, sizeof(num_buffer), "%u", num);
        if (length > 0)
        {
            write(1, num_buffer, length);
            count += length;
        }
    }

    return count;
}

/**
 * handle_zero_flag - Handles the '0' flag character for non-custom conversion specifiers.
 *
 * @args: Arguments list containing the value to be formatted
 * @format: The format specifier character ('d', 'i', 'u', 'o', 'x', 'X')
 *
 * Return: The count of characters printed
 */
int handle_zero_flag(va_list args, char format)
{
    int count = 0;
    char num_buffer[UINT_SIZE]; /* Adjust the buffer size as needed */

    if (format == 'd' || format == 'i')
    {
        int num = va_arg(args, int);
        /* Implement '0' flag handling for 'd' and 'i' format specifiers */
        /* You can use snprintf to format the number with '0' padding and count the characters */
        int length = snprintf(num_buffer, sizeof(num_buffer), "%d", num);
        if (length > 0)
        {
            write(1, num_buffer, length);
            count += length;
        }
    }
    else if (format == 'u' || format == 'o' || format == 'x' || format == 'X')
    {
        unsigned int num = va_arg(args, unsigned int);
        /* Implement '0' flag handling for 'u', 'o', 'x', and 'X' format specifiers */
        /* You can use snprintf to format the number with '0' padding and count the characters */
        int length = snprintf(num_buffer, sizeof(num_buffer), "%u", num);
        if (length > 0)
        {
            write(1, num_buffer, length);
            count += length;
        }
    }

    return count;
}

/**
 * handle_minus_flag - Handles the '-' flag character for non-custom conversion specifiers.
 *
 * @args: Arguments list containing the value to be formatted
 * @format: The format specifier character ('d', 'i', 'u', 'o', 'x', 'X')
 *
 * Return: The count of characters printed
 */
int handle_minus_flag(va_list args, char format)
{
    int count = 0;
    char num_buffer[UINT_SIZE]; /* Adjust the buffer size as needed */

    if (format == 'd' || format == 'i')
    {
        int num = va_arg(args, int);
        /* Implement '-' flag handling for 'd' and 'i' format specifiers */
        /* You can use snprintf to format the number with left alignment and count the characters */
        int length = snprintf(num_buffer, sizeof(num_buffer), "%d", num);
        if (length > 0)
        {
            write(1, num_buffer, length);
            count += length;
        }
    }
    else if (format == 'u' || format == 'o' || format == 'x' || format == 'X')
    {
        unsigned int num = va_arg(args, unsigned int);
        /* Implement '-' flag handling for 'u', 'o', 'x', and 'X' format specifiers */
        /* You can use snprintf to format the number with left alignment and count the characters */
        int length = snprintf(num_buffer, sizeof(num_buffer), "%u", num);
        if (length > 0)
        {
            write(1, num_buffer, length);
            count += length;
        }
    }

    return count;
}
