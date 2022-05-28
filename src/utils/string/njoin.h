#ifndef __STRING_NJOIN_H__
    #define __STRING_NJOIN_H__

    #include <stddef.h>
    #include "utils/memory.h"
    #include "strcat.h"
    #include "strlen.h"

char *njoin(const char **arr, const char *sep, size_t n);

#endif