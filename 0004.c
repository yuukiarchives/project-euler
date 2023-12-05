/**
 * @file
 * Largest palindromic number that is the product of two 3-digit positive
 * integers.
 */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_palindromic(const long);
void reverse_string(char *);

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
    char n_str[21];
    sprintf(n_str, "%ld", n);

    /* Duplicates and reverses the string. */
    char reversed[21];
    strcpy(reversed, n_str);

    reverse_string(reversed);

    /* Returns whether the reversal of `n` is equal to `n`. */
    return strcmp(reversed, n_str) == 0;
}

/**
 * Reverses a string.
 */
void reverse_string(char *str) {
    int i;
    int j;
    char tmp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
    }
}
