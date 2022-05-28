#ifndef __JK_PARSING_INTERN_H__
    #define __JK_PARSING_INTERN_H__

    #include <stddef.h>
    #include "jk_func.h"

typedef struct tree_s tree_t;
typedef struct children_list_s children_list_t;
typedef struct func_list_s func_list_t;
typedef struct parsing_s parsing_t;

struct func_list_s {
    func_t *func;
    func_list_t *next;
};

struct children_list_s {
    tree_t *child;
    children_list_t *next;
};

struct tree_s {
    children_list_t *children;
    func_list_t *funcs;
};

struct parsing_s {
    tree_t *tree;
    tree_t *head;
    size_t y, x;
    void (*add_func)(func_t *);
};

parsing_t TREE;

#endif