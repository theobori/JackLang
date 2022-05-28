#include "init.h"

void init_func()
{
    JK_FUNC.is = &is_func;
    JK_FUNC.create = &create_func;
}