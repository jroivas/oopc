#include "str.h"
#include <stdlib.h>

static StrOps str_ops = {
    .type = object_type,
    .val = str_val,
    .set = str_setval
};

void str_init(Str *obj)
{
    obj->ops = &str_ops;
    obj->val = "";
}

Str *str_new()
{
    Str *tmp = calloc(1, sizeof(Str));
    object_init(&tmp->parent);

    tmp->parent.type = 44;
    str_init(tmp);
    //tmp->ops->parent = tmp->parent.ops;

    return tmp;
}

char *str_val(Str *obj)
{
    return obj->val;
}

void str_setval(Str *obj, char *val)
{
    obj->val = val;
}
