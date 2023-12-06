/**
 * @file
 * Largest palindromic number that is the product of two 3-digit positive
 * integers.
 */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_palindromic(const long);
void reverse(char *);

int main(void) {
    long max_palindrome = -1;

    int i;
    int j;
    long product;
    for (i = 100; i <= 999; i++) {
        for (j = 100; j <= 999; j++) {
            product = i * j;
            if (is_palindromic(product) && product > max_palindrome) {
                max_palindrome = product;
            }
        }
    }

    printf("%ld\n", max_palindrome);
    return 0;
}

/**
 * Determines if `n` is palindromic.
 */
bool is_palindromic(const long n) {
    /* Converts `n` to a string. */
    char str[12];
    snprintf(str, 12, "%ld", n);

    /* Duplicates and reverses the string. */
    char reversed[12];
    strcpy(reversed, str);
    reverse(reversed);

    /* Returns whether the reverse of `n` is equal to `n`. */
    return strcmp(reversed, str) == 0;
}

/**
 * Reverses a string in-place.
 */
void reverse(char *str) {
    /* If it is an empty string, does nothing. */
    if (!*str) {
        return;
    }

    const size_t length = strlen(str);
    size_t i;
    size_t j;
    char tmp;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}
