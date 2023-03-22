#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *stockSummary(
    const char *const books[], size_t nb_books,
    const char *const categories[], size_t nb_categories) {
    if (nb_books == 0 || nb_categories == 0) {
        return strdup("");
    }
    int stocks['Z' + 1] = {0};
    for (size_t i = 0; i < nb_books; i++) {
        const char *book = books[i];
        int quantity = atoi(strchr(book, ' ') + 1);
        stocks[(int) book[0]] += quantity;
    }
    char *result = malloc(nb_categories * 20 * sizeof(char));
    size_t result_len = 0;
    for (size_t i = 0; i < nb_categories; i++) {
        if (result_len > 0) {
            result[result_len++] = ' ';
            result[result_len++] = '-';
            result[result_len++] = ' ';
        }
        int quantity = stocks[(int) categories[i][0]];
        result_len += sprintf(result + result_len, "(%c : %d)", categories[i][0], quantity);
    }
    result[result_len] = '\0';
    return result;
}