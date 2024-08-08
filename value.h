#ifndef VALUE_H
#define VALUE_H

#include <stdbool.h>
typedef enum { VAL_NUM, VAL_NIL, VAL_BOOL, VAL_OBJ } ValueType;

typedef struct Obj Obj;
typedef struct ObjString ObjString;

typedef struct {
    ValueType type;
    union {
        bool boolean;
        double number;
        Obj *obj;
    } as;
} Value;

#define NUM_VAL(value) ((Value) {VAL_NUM, {.number = value}})
#define NIL_VAL ((Value) {VAL_NIL, {.number = 0}})
#define BOOL_VAL(value) ((Value) {VAL_BOOL, {.boolean = value}})
#define OBJ_VAL(object) ((Value) {VAL_OBJ, {.obj = (Obj *) (object)}})

#define AS_BOOL(value) ((value).as.boolean)
#define AS_NUMBER(value) ((value).as.number)
#define AS_OBJ(value) ((value).as.obj)

#define IS_NUM(value) ((value).type == VAL_NUM)
#define IS_NIL(value) ((value).type == VAL_NIL)
#define IS_OBJ(value) ((value).type == VAL_OBJ)
#define IS_BOOL(value) ((value).type == VAL_BOOL)

typedef struct {
    int capacity;
    int count;
    Value *values;
} ValueArray;

void initValueArray(ValueArray *);
void writeValueArray(ValueArray *, Value);
void freeValueArray(ValueArray *);
void printValue(Value);
bool valueEqual(Value a, Value b);
#endif // VALUE_H
