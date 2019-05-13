#pragma once
#include <string>
#include "HuffmanQueue.h"
#include "MinHeapNode.h"

class HuffmanCode {
    public:
        MinHeapNode* createHuffmanTree(HuffmanQueue& queue);
        void getCode(char c, MinHeapNode* root, std::string& str, bool &b);
};