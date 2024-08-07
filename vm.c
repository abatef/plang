#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "memory.h"
#include "vm.h"
#include "compiler.h"

#include <stdio.h>

VM vm;

static InterpretResult run()
{
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
#define BINARY_OP(op)                                                                              \
    do {                                                                                           \
        double b = pop();                                                                          \
        double a = pop();                                                                          \
        push(a op b);                                                                              \
    } while (false)

    for (;;) {
#ifdef DEBUG_TRACE_EXECUTION
        printf("          ");
        for (Value *slot = vm.stack; slot < vm.stack + vm.stackCount; slot++) {
            printf("[ ");
            printValue(*slot);
            printf(" ]");
        }
        printf("\n");
        disassembleInstr(vm.chunk, (int) (vm.ip - vm.chunk->code));
#endif
        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_RET :
                {
                    printValue(pop());
                    printf("\n");
                    return INTERPRET_OK;
                }
            case OP_CONST :
                {
                    Value constant = READ_CONSTANT();
                    push(constant);
                    break;
                }
            case OP_NEG :
                vm.stack[vm.stackCount - 1] = -vm.stack[vm.stackCount - 1];
                break;
            case OP_ADD :
                BINARY_OP(+);
                break;
            case OP_SUB :
                BINARY_OP(-);
                break;
            case OP_MUL :
                BINARY_OP(*);
                break;
            case OP_DIV :
                BINARY_OP(/);
                break;
        }
    }
#undef READ_BYTE
#undef READ_CONSTANT
#undef BINARY_OP
}

static void resetStack()
{
    vm.stackCount = 0;
}

void initVM()
{
    vm.stack = NULL;
    vm.stackCapacity = 0;
    resetStack();
}

InterpretResult interpret(const char *source)
{
    Chunk chunk;
    initChunk(&chunk);

    if (!compile(source, &chunk)) {
        freeChunk(&chunk);
        return INTERPRET_COMPILE_ERROR;
    }

    vm.chunk = &chunk;
    vm.ip = vm.chunk->code;

    InterpretResult result = run();

    freeChunk(&chunk);
    return result;
}

void freeVM() {}

void push(Value value)
{
    if (vm.stackCount + 1 >= vm.stackCapacity) {
        int oldCapacity = vm.stackCapacity;
        vm.stackCapacity = GROW_CAPACITY(oldCapacity);
        vm.stack = GROW_ARRAY(Value, vm.stack, oldCapacity, vm.stackCapacity);
    }
    vm.stack[vm.stackCount++] = value;
}

Value pop()
{
    return vm.stack[--vm.stackCount];
}
