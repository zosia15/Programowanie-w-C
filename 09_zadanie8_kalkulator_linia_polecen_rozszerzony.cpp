#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void print_usage(const char *program_name) {
    printf("Usage: %s number1 operation number2\n", program_name);
    printf("Available operations:\n");
    printf("\tadd\n");
}

/*
 * Parse `text` as a decimal integer and store the result via `out`.
 * Returns 0 on success, -1 on failure (invalid input or out-of-range value).
 *
 * Why not atoi? atoi("abc") silently returns 0, so the caller cannot tell
 * a real "0" from a parse error. strtol gives us proper diagnostics:
 *
 *   - `end` is set by strtol to the first character it could NOT parse.
 *     If `end == text`, no digits were consumed (e.g. text was "abc" or "").
 *     If `*end != '\0'`, there is trailing garbage (e.g. "12x").
 *   - `errno` is set to ERANGE if the value overflows `long`. We must
 *     reset errno to 0 before the call, because strtol does not clear it
 *     on success.
 *   - strtol returns `long`, which may be wider than `int`, so we also
 *     range-check against INT_MIN / INT_MAX before narrowing.
 *
 * The out-parameter + int return code is a common C idiom for functions
 * that need to report both a value and a success/failure status, since C
 * has no tuples or exceptions.
 */
static int parse_int(const char *text, int *out) {
    char *end;
    errno = 0;
    long value = strtol(text, &end, 10);
    if (end == text || *end != '\0') return -1;
    if (errno == ERANGE || value < INT_MIN || value > INT_MAX) return -1;
    *out = (int)value;
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return 1;
    }

    int number1;
    int number2;
    if (parse_int(argv[1], &number1) != 0) {
        fprintf(stderr, "Error: '%s' is not a valid integer\n", argv[1]);
        return 1;
    }
    if (parse_int(argv[3], &number2) != 0) {
        fprintf(stderr, "Error: '%s' is not a valid integer\n", argv[3]);
        return 1;
    }

    const char *operation = argv[2];

    if (strcmp(operation, "add") == 0) {
        printf("%d + %d = %d\n", number1, number2, number1 + number2);
        return 0;
    }

    fprintf(stderr, "Error: unknown operation '%s'\n", operation);
    print_usage(argv[0]);
    return 1;
}