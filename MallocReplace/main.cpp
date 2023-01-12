#include <iostream>
#include "myMalloc.h"


void test_InitializeTable_Allocate_Deallocate(){
    MyMalloc m(5);
    std::cout << "Initialize a hashTable:" << "\n";
    m.printHashTable();
    std::cout << "****************************************************************"<< std::endl;
    std::cout << "Allocate a memory :" << "\n";
    void* ptr = m.allocate(10);
    m.printHashTable();//print allocated memory address
    m.deallocate(ptr);
    std::cout << "****************************************************************"<< std::endl;
    std::cout <<"Deallocate the memory :" << "\n";
    m.printHashTable();//print allocated memory address

}

void test_growTable(){
    MyMalloc m(10);
    std::cout << "Initialize a hashTable :" << "\n";
    m.printHashTable();
    std::cout << "****************************************************************"<< std::endl;
    std::cout << "\n";
    m.allocate(5);
    m.allocate(5);
    m.allocate(5);
    m.allocate(5);
    m.allocate(5);
    std::cout << "Allocate 5 elements in a hashTable :" << "\n";
    m.printHashTable();
    std::cout << "****************************************************************"<< std::endl;

    m.allocate(5);

    std::cout << "Table doubled after 6th element is added in original table :" << std::endl;
    m.printHashTable();
    std::cout << "****************************************************************"<< std::endl;

}

void compare_Allocator_BuiltInMalloc(){
    std::chrono::time_point<std::chrono::system_clock> start, end; // timing start to end
    std::chrono::duration<double> durations; // to time a period of time


    MyMalloc m(15);
    const char *testString = "Hello, this is my malloc replacement test";

    start = std::chrono::system_clock::now();// initialize start time

    char *testPtr = (char *) m.allocate(sizeof(testString));
    strcpy(testPtr, testString);
    std::cout << "Allocate memory for a string :" << testPtr << std::endl;
    m.deallocate(testPtr);

    end = std::chrono::system_clock::now();// initialize end time
    durations = end - start;
    std::cout<< "My own malloc replacement running time :" << durations.count() <<std::endl; // to get malloc running time

    std::cout<< "******************************************************************************" << std::endl;

    start = std::chrono::system_clock::now();// initialize start time

    char *testPtr1 = (char *) malloc(sizeof(testString));
    strcpy(testPtr1, testString);
    std::cout << "Allocate memory for a string :" << testPtr1 << std::endl;
    free(testPtr1);

    end = std::chrono::system_clock::now();// initialize end time
    durations = end - start;
    std::cout<< "Built_in malloc running time :" << durations.count() <<std::endl; // to get malloc running time

}


int main(int argc, const char * argv[]) {

    std::cout << "****************************************************************"<< std::endl;
    test_InitializeTable_Allocate_Deallocate();
    std::cout << "****************************************************************"<< std::endl;

    std::cout << "****************************************************************"<< std::endl;
    test_growTable();
    //std::cout << "****************************************************************"<< std::endl;

    std::cout << "****************************************************************"<< std::endl;
    compare_Allocator_BuiltInMalloc();
    std::cout << "****************************************************************"<< std::endl;
    // From the test we can know that built_in Malloc is much faster than MyMalloc

    return 0;
}
