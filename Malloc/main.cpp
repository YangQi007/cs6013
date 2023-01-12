#include <iostream>
#include <string.h>
#include "MyMalloc.h"

int main(int argc, const char * argv[]) {

    std::chrono::time_point<std::chrono::system_clock> start, end; // timing start to end
    std::chrono::duration<double> durations; // to time a period of time


    MyMalloc mymalloc;
    const char *test = "This is my Malloc Replacement";

    start = std::chrono::system_clock::now();// initialize starting time

    char *testPtr = (char *) mymalloc.allocate(sizeof(test));
    strcpy(testPtr, test);
    std::cout << testPtr << std::endl;
    mymalloc.deallocate(testPtr);

    end = std::chrono::system_clock::now();// initialize end time
    durations = end - start;
    std::cout<< "My own malloc replacement running time: " << durations.count() <<std::endl; // to get malloc running time

    std::cout<< "******************************************************************************" << std::endl;

    start = std::chrono::system_clock::now();// initialize starting time

    char *testPtr_ = (char *) malloc(sizeof(test));
    strcpy(testPtr_, test);
    std::cout << testPtr_ << std::endl;
    free(testPtr_);

    end = std::chrono::system_clock::now();// initialize end time
    durations = end - start;
    std::cout<< "Built_in malloc running time: " << durations.count() <<std::endl; // to get malloc running time


    return 0;

}