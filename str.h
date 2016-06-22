#ifndef STR_H
#define STR_H

#include "object.h"

struct _Str;
typedef struct _Str Str;

typedef struct _StrOps {
    //ObjectOps *parent;
    int (*type)(Object *);
    char *(*val)(Str *);
    void (*set)(Str *, char *);
} StrOps;

typedef struct _Str {
    Object parent;
    StrOps *ops;
    char *val;
} Str;

Str *str_new();
void str_init(Str *);
char *str_val(Str *);
void str_setval(Str *, char *);

#endif
