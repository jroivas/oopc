#include <stdio.h>
#include "object.h"
#include "str.h"

int main() {
    Object *obj = object_new();

    printf("%d\n", obj->ops->type((Object*)obj));
    printf("%d\n", obj->_(type)((Object*)obj));

    Str *st = str_new();
    printf("%s\n", st->ops->val(st));
    printf("%s\n", st->_(val)(st));

    st->_(set)(st, "tst1");
    printf("%s\n", st->ops->val(st));
    printf("%s\n", st->_(val)(st));
    printf("%d\n", st->_(type)((Object*)st));

    // Should fail
    //st->_(set)((Str*)obj, "tst1");

    // Destructors
    st->_(dtor)(st);

    obj->_(dtor)(obj);

    return 0;
}
