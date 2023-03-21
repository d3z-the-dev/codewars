#include <stddef.h>
typedef unsigned int uint;

void find_multiples(uint integer, uint limit, size_t *count, uint multiples[]) {
    for (uint i = integer + (*count = 0); i <= limit; i += integer) multiples[(*count)++] = i;
}