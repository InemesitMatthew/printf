#include "specifiers_non_custom.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h> // for size_t

typedef struct {
    char format;
    const char *expected_output;
} TestCase;

void run_test(const char format, const char *expected_output, ...) {
    char result_buffer[512];

    va_list args;
    va_start(args, expected_output); // Start the va_list with the last named argument

    size_t result_length = handle_precision(args, format, result_buffer, sizeof(result_buffer));

    va_end(args); // Clean up the args list

    if (result_length >= sizeof(result_buffer)) {
        // Handle buffer overflow error
        printf("Buffer overflow error!\n");
    } else if (strcmp(result_buffer, expected_output) == 0) {
        // Test passed
        printf("Test passed for format specifier '%c'.\n", format);
    } else {
        // Test failed
        printf("Test failed for format specifier '%c'.\n", format);
    }
}

int main(void) {
    // Initialize test cases
    TestCase testCases[] = {
        {'d', "123"},
        {'i', "-456"},
        {'u', "789"},
        {'o', "123"},
        {'x', "1abc"},
        {'X', "1ABC"}
    };

    // Run tests
    for (size_t i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        char format = testCases[i].format;
        const char *expected_output = testCases[i].expected_output;

        // Pass the format specifier and arguments after it
        if (format == 'd' || format == 'i') {
            int arg = atoi(expected_output); // Convert the expected output to an integer
            run_test(format, expected_output, arg);
        } else if (format == 'u' || format == 'o' || format == 'x' || format == 'X') {
            unsigned int arg = (unsigned int)strtoul(expected_output, NULL, 10); // Convert the expected output to an unsigned int
            run_test(format, expected_output, arg);
        }
    }

    return 0;
}
