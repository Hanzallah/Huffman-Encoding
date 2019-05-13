#pragma once
#include "HuffmanHeap.h"
#include "MinHeapNode.h"

class HuffmanQueue {
    public:
        HuffmanQueue();
        int size();
        bool isEmpty() const;
        void enqueue(MinHeapNode* newItem);
        bool dequeue();
        bool dequeue(MinHeapNode*& item);
        MinHeapNode* getFront();
        void display();
    private:
        HuffmanHeap h;
};