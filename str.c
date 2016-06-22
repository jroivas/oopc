#include "str.h"
#include <stdlib.h>

static StrOps str_ops = {
    .type = object_type,
    .val = str_val,
    .set = str_setval
};

void str_init(Str *obj, StrOps *ops)
{
    object_init((Object*)obj, (ObjectOps*)ops);
    obj->parent.type = 44;

    obj->ops = ops;
    obj->val = "";
}

Str *str_new()
{
    Str *tmp = calloc(1, sizeof(Str));
    str_init(tmp, &str_ops);

    return tmp;
}

char *str_val(Object *obj)
{
    Str *this = (Str*)obj;
    return this->val;
}

void str_setval(Object *obj, char *val)
{
    Str *this = (Str*)obj;
    this->val = val;
}
