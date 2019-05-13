#include "HuffmanQueue.h"

HuffmanQueue::HuffmanQueue()
{
}

int HuffmanQueue::size()
{
    return h.size();
}

bool HuffmanQueue::isEmpty() const
{
    return h.heapIsEmpty();
}

void HuffmanQueue::enqueue(MinHeapNode * newItem)
{
    h.insert(newItem);
}

bool HuffmanQueue::dequeue()
{
    h.extractMin();
    return true;
}

bool HuffmanQueue::dequeue(MinHeapNode *& item)
{
    item =  h.extractMin();
    return true;
}

MinHeapNode * HuffmanQueue::getFront()
{
    return h.peek();
}

void HuffmanQueue::display()
{
    h.display();
}
