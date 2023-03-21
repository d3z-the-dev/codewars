#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *stockSummary(
    const char *const books[], size_t nb_books, 
    const char *const categories[], size_t nb_categories) {
    if (nb_books == 0 || nb_categories == 0) {
        return strdup("");
    }
    int quantities['Z' + 1] = {0};
    for (size_t i = 0; i < nb_books; i++) {
        const char *book = books[i];
        const size_t position = strcspn(book, " ") + 1;
        quantities[book[0]] += atoi(book + position);
    }
    char *result = NULL;
    for (size_t i = 0; i < nb_categories; i++) {
        char *category = categories[i];
        char buffer[50];
        int length = sprintf(buffer, "(%c : %d)", category[0], quantities[category[0]]);
        if (result == NULL) {
            result = calloc(length + 1, sizeof(char));
            strcpy(result, buffer);
        } else {
            size_t sum = strlen(result);
            result = realloc(result, sum + length + 4);
            strcat(result, " - ");
            strcat(result, buffer);
        }
    }
    return result;
}