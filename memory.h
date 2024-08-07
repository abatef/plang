#ifndef MEMORY_H
#define MEMORY_H
#include "common.h"

#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity) * 2)
#define GROW_ARRAY(type, pointer, old, new)                                                        \
    (type *) reallocate(pointer, sizeof(type) * old, sizeof(type) * new)

#define FREE_ARRAY(type, pointer, oldCount) reallocate(pointer, sizeof(type) * (oldCount), 0)
void *reallocate(void *pointer, size_t oldSize, size_t newSize);

#endif // MEMORY_H
