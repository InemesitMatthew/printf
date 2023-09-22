#ifndef SPECIFIERS_NON_CUSTOM_H
#define SPECIFIERS_NON_CUSTOM_H

#include <stdarg.h> // Include necessary headers
#include <stddef.h>
#include <stdarg.h>

// Function prototypes
size_t handle_precision(va_list args, char format, char *result, size_t result_size);
int handle_zero_flag(va_list args, char format, char *result, size_t result_size);
int handle_minus_flag(va_list args, char format, char *result, size_t result_size);

#endif /* SPECIFIERS_NON_CUSTOM_H */
