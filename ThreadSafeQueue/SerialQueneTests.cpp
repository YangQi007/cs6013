//
// Created by YANG QI on 5/14/22.
//
#include <iostream>
#include "SerialQueneTests.h"
#include "SerialQueue.h"

void testEnqueue(){
    SerialQueue<int>* serialQueue = new SerialQueue<int>();
    serialQueue->enqueue(1);
    serialQueue->enqueue(2);
    serialQueue->enqueue(3);
    std::cout <<"The size of queue is :" << serialQueue->size() << "\n";
}

void testDequeue(){
    SerialQueue<int>* serialQueue = new SerialQueue<int>();
    serialQueue->enqueue(4);
    serialQueue->enqueue(5);
    serialQueue->enqueue(6);
    serialQueue->enqueue(7);
    std::cout << "The size of queue is :" << serialQueue->size() << "\n";
    int ret;
    serialQueue->dequeue(ret);
    std::cout << "After dequeue,the head node now is :" << ret << "\n";
}

int main() {

    testEnqueue();
    testDequeue();

}




