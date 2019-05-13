#include "MedianHeap.h"

MedianHeap::MedianHeap(): median(0)
{
}

void MedianHeap::insert(int value)
{
    if (value < median) {
        maxHeap.insert(value);
        
    }
    else {
        minHeap.insert(value);
        
    }

    if (minHeap.size() - maxHeap.size() > 1) {
        int item = minHeap.extractMin();
        maxHeap.insert(item);
    }
    else if(maxHeap.size() - minHeap.size() > 1) {
        int item = maxHeap.extractMax();
        minHeap.insert(item);
    }

    findMedian();
}

int MedianHeap::findMedian()
{
    if (minHeap.size() >= maxHeap.size()) {
        median =  minHeap.peek();
    }
    else {
        median = maxHeap.peek();
    }
    return median;
}
