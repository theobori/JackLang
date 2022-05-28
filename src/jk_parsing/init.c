#include "init.h"

static void init_tree()
{
    TREE.tree = malloc(sizeof(tree_t));
    TREE.head = TREE.tree;
    TREE.x = 0;
    TREE.y = 0;
    TREE.tree->funcs = NULL;
    TREE.tree->children = NULL;
    TREE.add_func = &tree_add_func;
}

void init_parsing()
{
    init_types();
    init_tree();
    init_func();

    PARSING.start = &parse_file;
}