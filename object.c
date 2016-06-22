#include "object.h"
#include <stdlib.h>

static ObjectOps obj_ops = {
    .type = object_type
};

void object_init(Object *obj, ObjectOps *ops)
{
    obj->ops = ops;
    obj->type = 42;
}

Object *object_new()
{
    Object *tmp = calloc(1, sizeof(Object));
    object_init(tmp, &obj_ops);
    return tmp;
}

int object_type(Object *obj)
{
    return obj->type;
}
