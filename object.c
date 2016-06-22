#include "object.h"
#include <stdlib.h>
#include <stdio.h>

static ObjectOps obj_ops = {
    .dtor = object_del,
    .type = object_type
};

void object_init(Object *obj, ObjectOps *ops)
{
    if (!ops) obj->ops = &obj_ops;
    else obj->ops = ops;
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

void object_del(Object *obj)
{
    (void)obj;
    printf("OBJ DTOR\n");
    free(obj);
}
