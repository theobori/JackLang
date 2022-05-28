#ifndef __JK_VARS_H__
    #define __JK_VARS_H__

    #include "jk_types.h"
    #include "jk_vars.h"

typedef struct jk_vars_s {
    TYPES_T type;
    char *name;
} jk_vars_t;

void init_vars();

#endif