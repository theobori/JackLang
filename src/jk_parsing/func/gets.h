#ifndef __PARSING_FUNC_GET_H__
    #define __PARSING_FUNC_GET_H__

    #include "jk_vars.h"
    #include "jk_types.h"
    #include <stddef.h>
    #include <stdio.h>
    #include "../intern.h"
    #include "utils/string.h"
    #include "utils/memory.h"

extern char **lines;

char *get_func_name(const char *str);
jk_vars_t *get_func_args();

#endif
