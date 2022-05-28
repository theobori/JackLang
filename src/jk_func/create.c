#include "create.h"

func_t *create_func(const TYPES_T ret_type, const char *name, const jk_vars_t *vars)
{
    func_t *func = malloc(sizeof(func_t));
    arg_t *args = NULL;
    arg_t *head = args;

    for (size_t i = 0; vars[i].name; i++) {
        // printf("%s\n", vars[i].name);
        printf("ok\n");
        args = malloc(sizeof(arg_t));
        args->type = vars[i].type;
        args->name = strdup(vars[i].name);
        args = args->next;
    }
    args = NULL;
    arg_t *temp = head;
    printf("START\n");
    for (size_t i = 0; temp->next; temp = temp->next) {
        printf("%s\n", temp->name);
    }
    printf("END\n");
    func->ret_type = ret_type;
    func->name = strdup(name);
    func->args = head;
    return (func);
}