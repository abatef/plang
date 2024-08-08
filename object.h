#ifndef OBJECT_H
#define OBJECT_H

#include "common.h"
#include "value.h"

typedef enum { OBJ_STRING } ObjType;

typedef struct Obj {
    ObjType type;
    struct Obj *next;
} Obj;

typedef struct ObjString {
    Obj obj;
    int length;
    char *chars;
    uint32_t hash;
} ObjString;

static inline bool isObjType(Value value, ObjType type)
{
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

ObjString *copyString(const char *chars, int length);

#define OBJ_TYPE(value) (AS_OBJ(value)->type)
#define IS_STRING(value) isObjType(value, OBJ_STRING)
#define AS_STRING(value) ((ObjString *) AS_OBJ(value))
#define AS_CSTRING(value) (((ObjString *) AS_OBJ(value))->chars)

void printObject(Value value);
ObjString *takeString(char *chars, int length);

#endif