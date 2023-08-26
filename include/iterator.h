#ifndef ITERATOR_H
#define ITERATOR_H

#include <stddef.h>

typedef struct sl_iterator_t
{
    char *str;
    size_t len;
    char current_char[2];
    size_t idx;
} sl_iterator_t;

void print();

sl_iterator_t *sl_new_iterator(const char *str);
void sl_next(sl_iterator_t *it);
int sl_it_is_valid(sl_iterator_t *it);

#endif // !ITERATOR_H
