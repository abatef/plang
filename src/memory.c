#include "memory.h"
#include "chunk.h"
#include "object.h"
#include "value.h"
#include "vm.h"
#include <stdlib.h>

void *reallocate(void *pointer, size_t old, size_t new) {
    if (new == 0) {
        free(pointer);
        return NULL;
    }

    void *result = realloc(pointer, new);
    if (result == NULL)
        exit(1);
    return result;
}

static void freeObject(Obj *obj) {
    switch (obj->type) {
    case OBJ_STRING: {
        ObjString *string = (ObjString *)obj;
        FREE_ARRAY(char, string->chars, string->length + 1);
        FREE(ObjString, obj);
        break;
    }
    case OBJ_FUNCTION: {
        ObjFunction *function = (ObjFunction *)obj;
        freeChunk(&function->chunk);
        FREE(ObjFunction, obj);
        break;
    }
    case OBJ_NATIVE:
        FREE(ObjNative, obj);
        break;
    }
}

void freeObjects() {
    Obj *obj = vm.objects;
    while (obj != NULL) {
        Obj *next = obj->next;
        freeObject(obj);
        obj = next;
    }
}