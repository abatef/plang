#ifndef VM_H
#define VM_H

#include "chunk.h"
#include "object.h"
#include "table.h"
#include "value.h"
#include <stdint.h>

#define FRAME_MAX 64
#define STACK_MAX (UINT8_COUNT * FRAME_MAX)

typedef struct {
    ObjFunction *function;
    uint8_t *ip;
    Value *slots;
} CallFrame;

typedef struct {
    CallFrame frames[FRAME_MAX];
    int frameCount;
    Chunk *chunk;
    uint8_t *ip;
    Value *stack;
    int stackCapacity;
    int stackCount;
    Obj *objects;
    Table strings;
    Table globals;
} VM;

extern VM vm;

typedef enum { INTERPRET_OK, INTERPRET_COMPILE_ERROR, INTERPRET_RUNTIME_ERROR } InterpretResult;

void initVM();
void freeVM();
void push(Value);
Value pop();
Value peek(int dist);

void runtimeError(const char *format, ...);

InterpretResult interpret(const char *);

#endif // VM_H
