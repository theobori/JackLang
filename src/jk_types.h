#ifndef __JK_TYPES_H__
    #define __JK_TYPES_H__

typedef enum TYPES_E {
    _int,
    UNKNOWN
} TYPES_T;

typedef struct jk_types {
    TYPES_T (*is)(const char *);
} jk_types_t;

jk_types_t JK_TYPE;

void init_types();

#endif