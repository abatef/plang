#ifndef CHUNK_H
#define CHUNK_H

#include "common.h"
#include "value.h"

typedef enum {
    OP_RET,
    OP_CONST,
    OP_CONST_LONG,
    OP_NEG,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_FALSE,
    OP_TRUE,
    OP_NIL,
    OP_NOT,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_PRINT,
    OP_POP,
    OP_DEFINE_GLOBAL,
    OP_GET_GLOBAL,
    OP_SET_GLOBAL,
    OP_GET_LOCAL,
    OP_SET_LOCAL
} Opcode;

typedef struct {
    int offset;
    int line;
} LineStart;

typedef struct {
    int count;
    int capacity;
    uint8_t *code;
    int lineCapacity;
    int lineCount;
    LineStart *lines;
    ValueArray constants;
} Chunk;

void initChunk(Chunk *);
void writeChunk(Chunk *, uint8_t, int);
void writeConstant(Chunk *, Value, int);
void freeChunk(Chunk *);
int addConstant(Chunk *, Value);
int getLine(Chunk *, int);
#endif // CHUNK_H
