#include "object.h"
#include <stdlib.h>

static ObjectOps obj_ops = {
    .type = object_type
};

Object *object_new()
{
    Object *tmp = calloc(1, sizeof(Object));
    tmp->ops = &obj_ops;
    tmp->type = 42;
    return tmp;
}

int object_type(Object *obj)
{
    return obj->type;
}
