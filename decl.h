#ifndef DECL_H
#define DECL_H

#include "type.h"
#include "stmt.h"
#include "expr.h"

struct decl *program;

struct decl {
    char *name;
    struct type *type;
    struct expr *value;
    struct stmt *code;
    struct symbol *symbol;
    struct decl *next;
};

struct decl *decl_create(char *name, struct type *t, struct expr *v, struct stmt *c, struct decl *next );
struct decl *decl_list_prepend(struct decl *first, struct decl *rest);
void decl_print(struct decl *d, int indent);

// name resolution
void decl_resolve(struct decl *d, int *which, int param_count);

// type checking
void decl_typecheck(struct decl *d);
void decl_typecheck_individual(struct decl *d);

// codegen
extern int label_count;
void decl_codegen(struct decl *d, FILE *file);
void decl_codegen_individual(struct decl *d, FILE *file);

#endif
