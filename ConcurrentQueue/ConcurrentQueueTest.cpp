//
// Created by YANG QI on 5/14/22.
//

#include <vector>
#include <thread>
#include <iostream>
#include "ConcurrentQueue.h"

void Enqueue(ConcurrentQueue<int>& concurrentQueue, int& num_ints){
    for(int i = 0; i < num_ints; i++){
        concurrentQueue.enqueue(i);
    }
}

void Dequeue(ConcurrentQueue<int>& concurrentQueue, int& num_ints) {

    for (int i = 0; i < num_ints; i++) {
        int num = 0;
        concurrentQueue.dequeue(num);
    }
}

bool testQueue(int num_Producers, int num_Consumers, int num_ints){
    std::vector<std::thread> threads;
    ConcurrentQueue<int> concurrentQueue;

    for(int i = 0; i < num_Producers; i++){
        std::thread currentThread(&Enqueue, std::ref(concurrentQueue), std::ref(num_ints));
        threads.push_back(std::move(currentThread));
    }

    for(int i = 0; i < num_Consumers; i++){

        std::thread currentThread(&Dequeue, std::ref(concurrentQueue), std::ref(num_ints));
        threads.push_back(std::move(currentThread));
    }

    for(auto &thread : threads){
        thread.join();
    }

    if(concurrentQueue.size() == (num_Producers - num_Consumers)*num_ints){
        std::cout << "The concurrent queue size is :" << concurrentQueue.size() << "\n";
        return true;
    }else{
        std::cout << concurrentQueue.size() << "\n";
        return false;
    }
}

int main(int argc, char* argv[]) {

    // Test in terminal : ./yourprogram 4 3 10
    // The expected result is : 10
    std::cout << "ConcurrentQueue test result:\n";
    testQueue(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
}