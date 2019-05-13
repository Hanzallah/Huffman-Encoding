#include "MaxHeap.h"

MaxHeap::MaxHeap(): thisSize(0)
{
}

bool MaxHeap::heapIsEmpty() const
{
    return thisSize == 0;
}

void MaxHeap::insert(int newItem)
{
    if (thisSize < MAX_ARR_SIZE) {
        array[thisSize] = newItem;

        int place = thisSize;
        int parent = (place - 1) / 2;
        while (place > 0 && (array[place] > array[parent])) {
            int temp = array[parent];
            array[parent] = array[place];
            array[place] = temp;

            place = parent;
            parent = (place - 1) / 2;
        }
        ++thisSize;
    }
}

int MaxHeap::peek()
{
    return array[0];
}

int MaxHeap::extractMax()
{
    int item;
    item = 0;
    heapDelete(item);
    return item;
}

int MaxHeap::size()
{
    return thisSize;
}

bool MaxHeap::heapDelete(int & rootItem)
{
    if (heapIsEmpty()) {
        return false;
    }
    rootItem = array[0];
    array[0] = array[--thisSize];
    heapRebuild(0);
    return true;
}

void MaxHeap::display()
{
    for (int i = 0; i < thisSize; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void MaxHeap::heapRebuild(int root)
{
    int leftChild = 2 * root + 1;
    if (leftChild < thisSize) {
        int rightChild = leftChild + 1;

        if (rightChild < thisSize && (array[rightChild] > array[leftChild])) {
            leftChild = rightChild;
        }

        if (array[root] < array[leftChild]) {
            int temp = array[root];
            array[root] = array[leftChild];
            array[leftChild] = temp;

            heapRebuild(leftChild);
        }
    }
}
