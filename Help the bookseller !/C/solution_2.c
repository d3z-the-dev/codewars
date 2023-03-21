#include <stdlib.h>
#include <string.h>

char *stockSummary(
    const char *const books[], size_t nb_books,
    const char *const categories[], size_t nb_categories) {
    if (nb_books == 0 || nb_categories == 0)
        return strdup("");
    int quantities['Z' + 1] = {0};
    for (size_t i = 0; i < nb_books; ++i) {
        const char *book = books[i];
        size_t j = 0;
        while (book[j] != ' ') ++j;
        quantities[book[0]] += atoi(book + j + 1);
    }
    char *result = calloc(1024, sizeof(char));
    for (size_t i = 0; i < nb_categories; ++i) {
        int len = snprintf(result + strlen(result), 1024 - strlen(result),
    "%s(%c : %d)", i == 0 ? "" : " - ", categories[i][0], quantities[(int)categories[i][0]]);
    }
    return result;
}