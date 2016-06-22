#include <stdio.h>
#include "object.h"
#include "str.h"

int main() {
    Object *obj = object_new();

    printf("%d\n", obj->ops->type((Object*)obj));
    printf("%d\n", obj->_(type)((Object*)obj));

    Str *st = str_new();
    printf("%s\n", st->ops->val((Object*)st));
    printf("%s\n", st->_(val)((Object*)st));

    st->_(set)((Object*)st, "tst1");
    printf("%s\n", st->ops->val((Object*)st));
    printf("%s\n", st->_(val)((Object*)st));
    printf("%d\n", st->_(type)((Object*)st));

    // Should fail
    //st->_(set)((Object*)obj, "tst1");

    // Destructors
    st->_(dtor)((Object*)st);

    obj->_(dtor)((Object*)obj);

    return 0;
}
