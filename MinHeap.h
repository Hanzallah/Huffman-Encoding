#pragma once
#include <iostream>

const int MIN_ARR_SIZE = 1000;

class MinHeap {
public:
    MinHeap();

    bool heapIsEmpty() const;
    void insert(int value); // inserts integer into heap
    int peek(); // returns the value of the min element
    int extractMin(); // retrieves and removes the min element
    int size(); // returns the number of elements in the heap
    bool heapDelete(int & rootItem);
    void display();

protected:
    void heapRebuild(int root);
private:
    int array[MIN_ARR_SIZE];
    int thisSize;
};