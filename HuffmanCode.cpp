#include "HuffmanCode.h"

MinHeapNode* HuffmanCode::createHuffmanTree(HuffmanQueue & queue)
{
    int n = queue.size();
    for (int i = 1 ; i <= n-1; i++) {
        MinHeapNode* z = new MinHeapNode();

        MinHeapNode* left;
        queue.dequeue(left);
        z->left = left;

        MinHeapNode* right;
        queue.dequeue(right);
        z->right = right;

        z->character = '\0';
        z->freq = left->freq + right->freq;
        queue.enqueue(z);
    }
    return queue.getFront();
}

void HuffmanCode::getCode(char c, MinHeapNode * root, std::string& str, bool &b)
{
    if (!b && root->left) {
        str.append("0");
        getCode(c, root->left, str, b);
    }
    if (!b && root->right) {
        str.append("1");
        getCode(c, root->right, str, b);
    }

    if (root->character == c) {
        b = true;
    }

    if (!b && str.length() > 0) {
        str.erase(str.length() - 1, str.length());
    }
}
