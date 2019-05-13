#pragma once
#include <iostream>

const int MAX_ARR_SIZE = 1000;

class MaxHeap {
public:
    MaxHeap();

    bool heapIsEmpty() const;
    void insert(int newItem); // inserts integer into heap
    int peek(); // returns the value of the max element
    int extractMax(); // retrieves and removes the max element
    int size(); // returns the number of elements in the heap
    bool heapDelete(int & rootItem);
    void display();

protected:
    void heapRebuild(int root);
private:
    int array[MAX_ARR_SIZE];
    int thisSize;
};