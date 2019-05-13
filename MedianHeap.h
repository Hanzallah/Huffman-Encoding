#pragma once
#include "MaxHeap.h"
#include "MinHeap.h"

class MedianHeap {
    public:
        MedianHeap();
        void insert(int value); // inserts an element into MedianHeap
        int findMedian(); // returns the value of the median
    private:
        MaxHeap maxHeap;
        MinHeap minHeap;
        int median;
};