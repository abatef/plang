#include "debug.h"
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
            return testInst(offset, "RETURN");
            break;
        case OP_CONST :
            return constantInstruction("CONST", chunk, offset);
        case OP_CONST_LONG :
            return longConstantInstruction("CONST_LONG", chunk, offset);
        case OP_NEG :
            return simpleInstruction("NEGATE", offset);
        case OP_ADD :
            return simpleInstruction("ADD", offset);
        case OP_SUB :
            return simpleInstruction("SUBTRACT", offset);
        case OP_MUL :
            return simpleInstruction("MULTIPLY", offset);
        case OP_DIV :
            return simpleInstruction("DIVIDE", offset);
        default :
            printf("[+] unknown instruction\n");
            return offset + 1;
    }
}
