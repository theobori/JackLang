#ifndef __JK_PARSE_H__
    #define __JK_PARSE_H__

    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include "utils/string.h"
    #include "intern.h"
    #include "../jk_func.h"
    #include "jk_types.h"
    #include "jk_vars.h"
    #include "func/gets.h"

void parse_file(const char *file_content);

#endif