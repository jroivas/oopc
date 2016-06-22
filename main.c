#include <stdio.h>
#include "object.h"

int main() {
    Object *obj = object_new();

    printf("%d\n", obj->ops->type(obj));

    return 0;
}
