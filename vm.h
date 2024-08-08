#ifndef VM_H
#define VM_H

#include "chunk.h"
#include "value.h"
#include "object.h"

#define STACK_MAX 256

typedef struct {
    Chunk *chunk;
    uint8_t *ip;
    Value *stack;
    int stackCapacity;
    int stackCount;
    Obj *objects;
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
