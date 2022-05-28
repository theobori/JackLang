#ifndef __JK_FUNC_CREATE_H__
    #define __JK_FUNC_CREATE_H__

    #include "jk_func.h"
    #include "utils/string.h"
    #include "jk_types.h"
    #include <stdio.h>
    #include <stdlib.h>

func_t *create_func(const TYPES_T ret_type, const char *name, const jk_vars_t *vars);

#endif