#include "func.h"

int is_func(const char *str)
{
    for (size_t i = 0; str[i]; i++) {
        if (str[i] == '(') {
            return (1);
        }
    }
    return (0);
}