#pragma once

class MinHeapNode
{
public:
    MinHeapNode(char c = '\0', int freq = 0, MinHeapNode* left = nullptr, MinHeapNode* right = nullptr) {
        this->character = c;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
    ~MinHeapNode() {
        delete left;
        delete right;
        left = nullptr;
        right = nullptr;
    }
    char character; // An input character
    int freq; // Frequency of the character
    MinHeapNode *left, *right; // Left and right child
};

