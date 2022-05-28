#include "entry_point.h"

int jacklang_entry(const char *file_content)
{
    init_types();
    init_parsing();
    PARSING.start(file_content);
    return (0);
}
