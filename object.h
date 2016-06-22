#ifndef OBJECT_H
#define OBJECT_H

struct _Object;
typedef struct _Object Object;

typedef struct _ObjectOps {
    int (*type)(Object *);
} ObjectOps;

typedef struct _Object {
    ObjectOps *ops;
    int type;
} Object;

Object *object_new();
int object_type(Object *);

#endif
