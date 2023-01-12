//
// Created by YANG QI on 5/10/22. Redo assignment 4
//

#ifndef MALLOCREPLACE_MYMALLOC_H
#define MALLOCREPLACE_MYMALLOC_H
#include <stdio.h>
#include <vector>

class MyMalloc {
public:
    MyMalloc(size_t size);
    ~MyMalloc();

    void* allocate(size_t bytes);
    void deallocate(void* ptr);

    struct TableEntry {
        void* pointer;
        size_t size;
    };

    int hashTableSize = 0;
    size_t hashTableCapacity;
    TableEntry *hashTable;

    void tableInsert(void *ptr, size_t size, size_t index);
    void growTable();
    void printHashTable();
};


#endif //MALLOCREPLACE_MYMALLOC_H
