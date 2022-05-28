#ifndef __JK_FUNC_H__
    #define __JK_FUNC_H__

    #include <stddef.h>
    #include "jk_types.h"
    #include "jk_vars.h"

typedef struct arg_s {
    TYPES_T type;
    char *name;
    struct arg_s *next;
} arg_t;

typedef struct func_s {
    char *name;
    arg_t *args;
    TYPES_T ret_type;
} func_t;

typedef struct jk_func_s {
    int (*is)(const char *);
    func_t *(*create)(const TYPES_T ret_type, const char *, const jk_vars_t *);
} jk_func_t;

jk_func_t JK_FUNC;

void init_func();

#endif