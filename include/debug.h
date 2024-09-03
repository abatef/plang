#ifndef DEBUG_H
#define DEBUG_H

#include "chunk.h"

void disassembleChunk(Chunk *, const char *);
int disassembleInstr(Chunk *, int);

#endif // DEBUG_H
