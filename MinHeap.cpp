#include "MinHeap.h"

MinHeap::MinHeap(): thisSize(0)
{
}

bool MinHeap::heapIsEmpty() const
{
    return thisSize == 0;
}

void MinHeap::insert(int newItem)
{
    if (thisSize < MIN_ARR_SIZE) {
        array[thisSize] = newItem;

        int place = thisSize;
        int parent = (place - 1) / 2;
        while (place > 0 && (array[place] < array[parent])) {
            int temp = array[parent];
            array[parent] = array[place];
            array[place] = temp;

            place = parent;
            parent = (place - 1) / 2;
        }
        ++thisSize;
    }
}

int MinHeap::peek()
{
    return array[0];
}

int MinHeap::extractMin()
{
    int item;
    item = 0;
    heapDelete(item);
    return item;
}

int MinHeap::size()
{
    return thisSize;
}

bool MinHeap::heapDelete(int & rootItem)
{
    if (heapIsEmpty()) {
        return false;
    }
    rootItem = array[0];
    array[0] = array[--thisSize];
    heapRebuild(0);
    return true;
}

void MinHeap::display()
{
    for (int i = 0; i < thisSize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void MinHeap::heapRebuild(int root)
{
    int leftChild = 2 * root + 1;
    if (leftChild < thisSize) {
        int rightChild = leftChild + 1;

        if (rightChild < thisSize && (array[rightChild] < array[leftChild])) {
            leftChild = rightChild;
        }

        if (array[root] > array[leftChild]) {
            int temp = array[root];
            array[root] = array[leftChild];
            array[leftChild] = temp;

            heapRebuild(leftChild);
        }
    }
}
