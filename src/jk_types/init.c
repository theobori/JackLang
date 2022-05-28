#include "init.h"

static void init_type(TYPES_T type, size_t size, const char *name)
{
    TYPEDEF[type].size = size;
    memset(TYPEDEF[type].str_name, 0, MAX_TYPE_LENGTH);
    strcpy(TYPEDEF[type].str_name, name);
}

void init_types()
{
    init_type(_int, 4, "int");
    init_type(UNKNOWN, 0, "unknown");

    JK_TYPE.is = &is_type;
};