//
// Created by YANG QI on 5/10/22.
//

#include "MyMalloc.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>


void* MyMalloc::allocate(size_t bytesToAllocate){
    void* pointer =  mmap(NULL, bytesToAllocate, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0); // 0 means file descriptor read, 0 = offset

    if(pointer == MAP_FAILED){
        perror("MMAP Allocation failed");
        exit(1);
    }
    table.insert(pointer, bytesToAllocate);

    return pointer;
}

void MyMalloc::deallocate(void* ptr){
    if(munmap(ptr, table.get(ptr)) != 0)
        table.remove(ptr); // remove pointer from the table
}


//Constructor
MyMalloc::MyMalloc(){
    pageSize = getpagesize();
}

//Destructor
MyMalloc::~MyMalloc(){

}

HashTable MyMalloc::getTable(){

    return table;
}

