#include <stddef.h>
typedef unsigned int uint;

void find_multiples(uint integer, uint limit, size_t *count, uint multiples[]) {
    size_t i;
    *count = 0;
    for (i = 0; i < limit / integer; i++) {
        multiples[i] = integer * (i + 1);
        (*count)++;
    }
}