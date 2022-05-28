#include "add_func.h"

void tree_add_func(func_t *func)
{
    if (!TREE.tree->funcs) {
        TREE.tree->funcs = malloc(sizeof(func_list_t));
        TREE.tree->funcs->func = func;
        TREE.tree->funcs->next = NULL;
    } else {
        func_list_t *head = TREE.tree->funcs;
        while (head->next)
            head = head->next;
        head->next = malloc(sizeof(func_list_t));
        head->func = func;
        head->next = NULL;
    }
}