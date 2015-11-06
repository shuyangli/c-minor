#include <stdlib.h> // malloc
#include <string.h> // memset
#include "symbol.h"

struct symbol *symbol_create(symbol_t kind, struct type *type, char *name) {
    struct symbol *s = (struct symbol *)malloc(sizeof(*s));
    memset(s, 0, sizeof(*s));

    s->kind = kind;
    s->type = type;
    s->name = name;
    return s;
}