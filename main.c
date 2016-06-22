#include <stdio.h>
#include "object.h"
#include "str.h"

int main() {
    Object *obj = object_new();

    printf("%d\n", obj->ops->type(obj));
    printf("%d\n", obj->_(type)(obj));

    Str *st = str_new();
    printf("%s\n", st->ops->val(st));
    printf("%s\n", st->_(val)(st));

    st->_(set)(st, "tst1");
    printf("%s\n", st->ops->val(st));
    printf("%s\n", st->_(val)(st));
    printf("%d\n", st->_(type)((Object*)st));

    return 0;
}
