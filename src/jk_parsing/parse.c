#include "parse.h"

char **lines = NULL;

static size_t count_lines(char **lines)
{
    size_t size = 0;

    while (lines[size])
        size++;
    return (size);
}

static void parse_lines(const char *file_content)
{
    char **file_lines = split(file_content, "\n");
    size_t nb_lines = count_lines(file_lines);
    lines = malloc(sizeof(char **) * (nb_lines + 1));

    lines[nb_lines] = NULL;
    for (size_t i = 0; i < nb_lines; i++) {
        lines[i] = strdup(file_lines[i]);
    }
}

static int done = 0;

static void parse_word(const char *word)
{
    static TYPES_T curr_type = UNKNOWN;

    if (curr_type != UNKNOWN) {
        if (JK_FUNC.is(word)) {
            const char *name = get_func_name(word);
            const jk_vars_t *args = get_func_args();
            const TYPES_T ret_type = curr_type;
            done = 1;
            TREE.add_func(JK_FUNC.create(ret_type, name, args));
        }
        curr_type = UNKNOWN;
    }

    TYPES_T try_type = JK_TYPE.is(word);
    if (try_type != UNKNOWN) {
        curr_type = try_type;
    }
}

void parse_file(const char *file_content)
{
    parse_lines(file_content);

    for (TREE.y = 0; lines[TREE.y]; TREE.y++) {
        char **words = split(lines[TREE.y], " ");
        for (TREE.x = 0; words[TREE.x]; TREE.x++) {
            parse_word(words[TREE.x]);
        }
    }
    arg_t *temp = TREE.head->funcs->func->args;
    for (; temp->next->type != UNKNOWN; temp = temp->next) {
        printf("%s\n", temp->name);
    }
}
