#ifndef OBJECT_H
#define OBJECT_H

#include "chunk.h"
#include "common.h"
#include "value.h"

typedef enum { OBJ_STRING, OBJ_FUNCTION, OBJ_NATIVE } ObjType;

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

typedef struct ObjFunction {
    Obj obj;
    int arity;
    Chunk chunk;
    ObjString *name;
} ObjFunction;

typedef Value (*NativeFn)(int argCount, Value *args);

typedef struct {
    Obj obj;
    NativeFn function;
} ObjNative;

ObjNative *newNative(NativeFn function);

static inline bool isObjType(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

ObjString *copyString(const char *chars, int length);

#define OBJ_TYPE(value) (AS_OBJ(value)->type)
#define IS_STRING(value) isObjType(value, OBJ_STRING)
#define AS_STRING(value) ((ObjString *)AS_OBJ(value))
#define AS_CSTRING(value) (((ObjString *)AS_OBJ(value))->chars)
#define IS_FUNCTION(value) isObjType(value, OBJ_FUNCTION)
#define AS_FUNCTION(value) ((ObjFunction *)AS_OBJ(value))
#define IS_NATIVE(value) isObjType(value, OBJ_NATIVE)
#define AS_NATIVE(value) (((ObjNative *)AS_OBJ(value))->function)

void printObject(Value value);
ObjString *takeString(char *chars, int length);

ObjFunction *newFunction();

#endif