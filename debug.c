#include "debug.h"
#include "chunk.h"
#include <stdio.h>

static int testInst(int offset, const char *mnemonic)
{
    printf("%s\n", mnemonic);
    return offset + 1;
}

static int simpleInstruction(const char *name, int offset)
{
    printf("%s\n", name);
    return offset + 1;
}

static int constantInstruction(const char *name, Chunk *chunk, int offset)
{
    uint8_t constant = chunk->code[offset + 1];
    printf("%-10s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;
}

static int longConstantInstruction(const char *name, Chunk *chunk, int offset)
{
    uint32_t constant =
        chunk->code[offset + 1] | (chunk->code[offset + 2] << 8) | (chunk->code[offset + 3] << 16);
    printf("%-10s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 4;
}

void disassembleChunk(Chunk *chunk, const char *name)
{
    printf("== %s ==\n", name);
    int offset;
    for (offset = 0; offset < chunk->count;) {
        offset = disassembleInstr(chunk, offset);
    }
}

int disassembleInstr(Chunk *chunk, int offset)
{
    printf("[+] %04d  ", offset);
    int line = getLine(chunk, offset);
    if (offset > 0 && line == getLine(chunk, offset - 1)) {
        printf("    | ");
    } else {
        printf(" %04d ", line);
    }

    uint8_t inst = chunk->code[offset];

    switch (inst) {
        case OP_RET :
            return testInst(offset, "OP_RET");
            break;
        case OP_CONST :
            return constantInstruction("OP_CNST", chunk, offset);
        case OP_CONST_LONG :
            return longConstantInstruction("OP_LCNST", chunk, offset);
        case OP_NEG :
            return simpleInstruction("OP_NEG", offset);
        case OP_ADD :
            return simpleInstruction("OP_ADD", offset);
        case OP_SUB :
            return simpleInstruction("OP_SUB", offset);
        case OP_MUL :
            return simpleInstruction("OP_MUL", offset);
        case OP_DIV :
            return simpleInstruction("OP_DIV", offset);
        case OP_NIL :
            return simpleInstruction("OP_NIL", offset);
        case OP_FALSE :
            return simpleInstruction("OP_FLSE", offset);
        case OP_TRUE :
            return simpleInstruction("OP_TRUE", offset);
        case OP_NOT :
            return simpleInstruction("OP_NOT", offset);
        case OP_EQUAL :
            return simpleInstruction("OP_EQUL", offset);
        case OP_GREATER :
            return simpleInstruction("OP_GRTR", offset);
        case OP_LESS :
            return simpleInstruction("OP_LESS", offset);
        default :
            printf("[+] unknown instruction\n");
            return offset + 1;
    }
}
