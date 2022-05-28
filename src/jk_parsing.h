#ifndef __JK_PARSING_H__
    #define __JK_PARSING_H__

typedef struct jk_parsing_s {
    void (*start)(const char *);
    void (*add_args)();
} jk_parsing_t;

jk_parsing_t PARSING;

void init_parsing();

#endif