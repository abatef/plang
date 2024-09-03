#ifndef TABLE_H
#define TABLE_H

#include "common.h"
#include "value.h"
#include <stdbool.h>

#define TABLE_MAX_LOAD 0.75

typedef struct Entry {
    ObjString *key;
    Value value;
} Entry;

typedef struct Table {
    int count;
    int capacity;
    Entry *entries;
} Table;

void initTable(Table *table);
void freeTable(Table *table);
bool tableSet(Table *table, ObjString *key, Value value);
bool tableGet(Table *table, ObjString *key, Value *value);
bool tableDelete(Table *table, ObjString *key);
void tableAddAll(Table *from, Table *to);
ObjString *tableFindString(Table *Table, const char *chars, int length, uint32_t hash);
#endif