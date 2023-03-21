#include <stddef.h>

void find_multiples (int integer, int limit, size_t *count, int multiples[])
{
    int i;
    for (i = 1; integer * i <= limit; i++) multiples[i - 1] = integer * i;
    *count = i - 1;
}