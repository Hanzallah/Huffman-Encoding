#pragma once
#include <iostream>
#include "MinHeapNode.h"

const int HUFFMAN_ARR_SIZE = 1000;

class HuffmanHeap {
    public:
        HuffmanHeap();
        ~HuffmanHeap();

        bool heapIsEmpty() const;
        void insert(MinHeapNode* node); // inserts integer into heap
        MinHeapNode* peek(); // returns the value of the min element
        MinHeapNode* extractMin(); // retrieves and removes the min element
        int size(); // returns the number of elements in the heap
        bool heapDelete(MinHeapNode*& node);
        void display();

    protected:
        void heapRebuild(int root);

    private:
        MinHeapNode* array[HUFFMAN_ARR_SIZE];
        int thisSize;
};