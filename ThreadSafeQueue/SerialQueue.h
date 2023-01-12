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

template <typename T>
class SerialQueue {

public:
   SerialQueue() : head_( new Node{ T{}, nullptr } ), size_( 0 )
   {
      tail_ = head_;
   }

   void enqueue( const T & x ) {
      // Your code goes here.
       Node* node = new Node();
       node->data = x;
       node->next = nullptr;

       if(size() == 0){
           head_ = node;
           tail_ = node;
       }else{
           tail_->next = node;
           tail_ = node;
       }
       size_++;
   }

   bool dequeue(T& ret ) {
      // Your code goes here.
       if(size() == 0){
           return false;
       }
       Node* toDequeue = head_;
       head_ = toDequeue->next;
       if(size() != 1){
           ret = head_->data;
       }
       delete toDequeue;
       size_--;
       return true;
   }

   ~SerialQueue() {

      while( head_ != nullptr ) {
         Node* temp = head_->next;
         delete head_;
         head_ = temp;
      }
   }

   int size() const { return size_; }

private:

   struct Node {
      T      data;
      Node * next;
   };

   Node * head_;
   Node * tail_;
   int    size_;
};
