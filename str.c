#include "str.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

static StrOps str_ops = {
    .type = object_type,
    .dtor = str_del,
    .val = str_val,
    .set = str_setval
};

void str_init(Str *obj, StrOps *ops)
{
    object_init(&obj->parent, NULL);
    obj->parent.type = 44;

    if (!ops) obj->ops = &str_ops;
    else obj->ops = ops;

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
    assert(this->parent.type == 44);
    return this->val;
}

void str_setval(Object *obj, char *val)
{
    Str *this = (Str*)obj;
    assert(this->parent.type == 44);
    this->val = val;
}

void str_del(Object *obj) {
    (void)obj;

    Str *this = (Str*)obj;
    printf("STR DTOR\n");

    this->parent.ops->dtor(obj);
}
