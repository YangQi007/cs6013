//
// Created by YANG QI on 5/10/22.
//

#ifndef MALLOC_HASHTABLE_H
#define MALLOC_HASHTABLE_H


#include <stdio.h>

class TableEntry {
public:
    void* pointer;
    size_t size;
    int flag; // to indicate if the part of memory is free or not;0 means memory is available 1 means in use

    //Constructor
    TableEntry(void* pointer, size_t size){
        this->pointer = pointer;
        this->size = size;
        flag = 0;
    }
};


class HashTable {

public:
    HashTable(); // constructor
    ~HashTable(); // destructor

//    hash table insert, delete
                // Map<Key, Value>
    void insert(void* pointer, size_t memorySize); // put a pointer and memory size

    void remove(void* pointer); // define the pointer and delete directly

    //to access the value directly by using the pointer:
    size_t get(void* pointer);

    // keep track of the HashTable:
    size_t getSize();

private:
    TableEntry* table;
    size_t capacity;
    size_t size;

    // if size is equal to the capacity,increase the capacity of the table
    void grow();

    int hash(void* pointer); //hash a pointer

};

#endif //MALLOC_HASHTABLE_H
