#ifndef CHUNK_H
#define CHUNK_H

#include "common.h"
#include "value.h"

typedef enum { OP_RET, OP_CONST, OP_CONST_LONG, OP_NEG, OP_ADD, OP_SUB, OP_MUL, OP_DIV } Opcode;

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
