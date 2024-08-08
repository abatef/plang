#include "object.h"
#include "memory.h"
#include "value.h"
#include "vm.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

static Obj *allocateObj(size_t size, ObjType type)
{
    Obj *obj = (Obj *) reallocate(NULL, 0, size);
    obj->type = type;
    obj->next = vm.objects;
    vm.objects = obj;
}

#define ALLOCATE_OBJ(type, objType) (type *) allocateObj(sizeof(type), objType)

static ObjString *allocateString(char *chars, int length)
{
    ObjString *string = ALLOCATE_OBJ(ObjString, OBJ_STRING);
    string->length = length;
    string->chars = chars;
    return string;
}

ObjString *copyString(const char *chars, int length)
{
    char *heap = ALLOCATE(char, length);
    memcpy(heap, chars, length);
    heap[length] = '\0';
    return allocateString(heap, length);
}

void printObject(Value value)
{
    switch (OBJ_TYPE(value)) {
        case OBJ_STRING :
            printf("%s", AS_CSTRING(value));
            break;
    }
}

ObjString *takeString(char *chars, int length)
{
    return allocateString(chars, length);
}