#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iterator.h>

void print()
{
    sl_iterator_t *it = sl_new_iterator("Test");
    while (sl_it_is_valid(it))
    {
        printf("%s", it->current_char);
        sl_next(it);
    }
    printf("\n");
}

sl_iterator_t *sl_new_iterator(const char *str)
{
    sl_iterator_t *it = (sl_iterator_t *)malloc(sizeof(sl_iterator_t));
    if (it == NULL)
        return NULL;

    it->idx = 0;
    it->len = strlen(str);
    it->current_char[0] = str[0];
    it->current_char[1] = 0;
    it->str = (char *)calloc(it->len, sizeof(char));
    if (it->str == NULL)
    {
        free(it);
        return NULL;
    }
    // copy
    for (size_t i = 0; i < it->len; ++i)
        it->str[i] = str[i];

    return it;
}

void sl_next(sl_iterator_t *it)
{
    ++(it->idx);
    it->current_char[0] = it->str[it->idx];
}

int sl_it_is_valid(sl_iterator_t *it)
{
    return !(it->len == it->idx);
}
