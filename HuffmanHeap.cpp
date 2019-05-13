#include "HuffmanHeap.h"

HuffmanHeap::HuffmanHeap(): thisSize(0)
{
}

HuffmanHeap::~HuffmanHeap()
{
    while (!heapIsEmpty()) {
        delete extractMin();
    }
}

bool HuffmanHeap::heapIsEmpty() const
{
    return thisSize == 0;
}

void HuffmanHeap::insert(MinHeapNode * node)
{
    if (thisSize < HUFFMAN_ARR_SIZE) {
        array[thisSize] = node;

        int place = thisSize;
        int parent = (place - 1) / 2;
        while (place > 0 && (array[place]->freq < array[parent]->freq)) {
            MinHeapNode* temp = array[parent];
            array[parent] = array[place];
            array[place] = temp;

            place = parent;
            parent = (place - 1) / 2;
        }
        ++thisSize;
    }
}

MinHeapNode* HuffmanHeap::peek()
{
    return array[0];
}

MinHeapNode* HuffmanHeap::extractMin()
{
    MinHeapNode* item;
    item = nullptr;
    heapDelete(item);
    return item;
}

int HuffmanHeap::size()
{
    return thisSize;
}

bool HuffmanHeap::heapDelete(MinHeapNode *& node)
{
    if (heapIsEmpty()) {
        return false;
    }
    node = array[0];
    array[0] = array[--thisSize];
    heapRebuild(0);
    return true;
}

void HuffmanHeap::display()
{
    for (int i = 0; i < thisSize; i++) {
        std::cout << array[i]->freq << " ";
    }
    std::cout << std::endl;
}

void HuffmanHeap::heapRebuild(int root)
{
    int leftChild = 2 * root + 1;
    if (leftChild < thisSize) {
        int rightChild = leftChild + 1;

        if (rightChild < thisSize && (array[rightChild]->freq < array[leftChild]->freq)) {
            leftChild = rightChild;
        }

        if (array[root]->freq > array[leftChild]->freq) {
            MinHeapNode* temp = array[root];
            array[root] = array[leftChild];
            array[leftChild] = temp;

            heapRebuild(leftChild);
        }
    }
}
