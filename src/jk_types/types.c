#include "types.h"

TYPES_T is_type(const char *type)
{
    for (size_t i = 0; TYPEDEF[i].size; i++) {
        if (strcmp(TYPEDEF[i].str_name, type)) {
            return ((TYPES_T)i);
        }
    }
    return (UNKNOWN);
}