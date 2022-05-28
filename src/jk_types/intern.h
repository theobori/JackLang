#ifndef __JK_TYPES_INTERN_H__
    #define __JK_TYPES_INTERN_H__

    #include <stddef.h>
    #include "../jk_types.h"
    #include "utils/memory.h"
    #include "utils/string.h"

    #define MAX_TYPE_LENGTH 32

typedef struct type_def_s {
    size_t size;
    char str_name[MAX_TYPE_LENGTH];
} typedef_t;

typedef_t TYPEDEF[UNKNOWN];

#endif