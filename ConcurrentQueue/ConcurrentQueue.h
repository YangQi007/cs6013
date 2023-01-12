//
// Created by YANG QI on 5/14/22.
//

#pragma once

////////////////////////////////////////////////////////////////////////
//
// Author:
// Date:
//
// CS 6013
//
// Outline for SerialQueue class.  Fill in the missing data, comments, etc.
//
////////////////////////////////////////////////////////////////////////

#include <mutex>

template <typename T>
class ConcurrentQueue {
private:

    struct Node {
        T      data;
        Node * next;
    };

    Node * head_;
    Node * tail_;
    int    size_;
    std::mutex mutex_lock;
    std::mutex mutex_lock1;

public:
    ConcurrentQueue() :
    head_( new Node{ T{}, nullptr } ), size_( 0 )
    {
        tail_ = head_;

    }

    void enqueue( const T& x ) {
        // Your code goes here.
        Node* node = new Node();
        node->data = x;
        node->next = nullptr;

        mutex_lock.lock();
        if(size() == 0){
            head_ = node;
            tail_ = node;
        }else{
            tail_->next = node;
            tail_ = node;
        }
        size_++;
        mutex_lock.unlock();
    }

    bool dequeue(T& ret ) {
        // Your code goes here.

        mutex_lock1.lock();
        if(size() == 0){

            mutex_lock1.unlock();
            return dequeue(ret);
        }
        Node* toDequeue = head_;
        head_ = toDequeue->next;
        if(size() != 1){
            ret = head_->data;
        }
        size_--;
        mutex_lock1.unlock();
        return true;
    }

    ~ConcurrentQueue() {

        while( head_ != nullptr ) {
            Node* temp = head_->next;
            delete head_;
            head_ = temp;
        }
    }

    int size() const { return size_; }


};

