//
// Created by YANG QI on 5/10/22.
//

#ifndef MALLOC_MYMALLOC_H
#define MALLOC_MYMALLOC_H

#include <stdio.h>
#include "HashTable.h"

class MyMalloc {
public:

    //Constructor
    MyMalloc();

    //Destructor
    ~MyMalloc();

    void* allocate(size_t bytesToAllocate);

    void deallocate(void* ptr);

    //hash table insert, delete, grow
    HashTable getTable();

private:
    size_t pageSize; // to keep track page size
    HashTable table; // to keep track table

};

#endif //MALLOC_MYMALLOC_H
