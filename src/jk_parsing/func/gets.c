#include "gets.h"

char *get_func_name(const char *name)
{
    size_t par_index = 0;

    while (name[par_index] != '(')
        par_index++;
    return (strndup(name, par_index));
}

static char *get_all_args()
{
    size_t x = TREE.x, y = TREE.y;
    size_t starting_x = x;

    for (;lines[y][x] != '('; x++);
    starting_x = x;
    x++;
    while (lines[y][x] != ')') {
        x++;
        if (!lines[y][x]) {
            return (NULL);
        }
    }
    return (strndup(&lines[y][starting_x + 1], x - starting_x - 1));
}

static size_t arr_len(const char **arr)
{
    size_t len = 0;

    for (; arr[len]; len++);
    return (len);
}

static int checking_arg_validity(const char *arg)
{
    char **words = split(arg, " ");
    size_t words_len = 0;
    for (; words[words_len]; words_len++);
    if (words_len <= 1)
        return (0);
    char *type = njoin((const char **)words, " ", words_len - 1);
    if (JK_TYPE.is(type) == UNKNOWN) {
        return (0);
    }
    return (1);
}

static void create_arg(jk_vars_t *var, const char *arg)
{
    char **words = split(arg, " ");
    size_t words_len = 0;
    for (; words[words_len]; words_len++);
    char *type = njoin((const char **)words, " ", words_len - 1);
    var->type = JK_TYPE.is(type);
    var->name = strdup(words[words_len - 1]);
}

jk_vars_t *get_func_args()
{
    char *all_args = get_all_args();
    char **splitted_args = split(all_args, ",");

    for (size_t i = 0; splitted_args[i]; i++) {
        if (!checking_arg_validity(splitted_args[i])) {
            return (NULL);
        }
    }
    size_t vars_len = arr_len((const char **)splitted_args);
    jk_vars_t *vars = malloc(sizeof(jk_vars_t) * (vars_len + 1));
    vars[vars_len].name = NULL;
    vars[vars_len].type = UNKNOWN;
    for (size_t i = 0; splitted_args[i]; i++) {
        create_arg(&vars[i], splitted_args[i]);
    }
    return (vars);
}