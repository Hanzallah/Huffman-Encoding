#include <iostream>
#include <fstream>
#include "MaxHeap.h"
#include "MinHeap.h"
#include "MedianHeap.h"
#include "MinHeapNode.h"
#include "HuffmanQueue.h"
#include "HuffmanCode.h"

int main() {
    HuffmanQueue q;
    HuffmanCode c;
    char* arr = new char[256];

    std::string inputFile, outputFile;

    std::cout << "Enter Input File Name: " << std::endl;
    std::cin >> inputFile;

    std::cout << "Enter Output File Name: " << std::endl;
    std::cin >> outputFile;

    std::ifstream input(inputFile);
    std::ofstream output(outputFile);

    int index = 0;
    if (input.is_open() && output.is_open()) {
        std::string word;
        std::string freq;
        int count = -1;
        while (input >> freq) {
            ++count;
            if (count == 0) {
                word = freq;
                arr[index++] = word[0];
            }
            if (count == 1) {
                count = -1;
                int frequency = std::atoi(freq.c_str());
                char character = word[0];
                MinHeapNode* node = new MinHeapNode(character, frequency);
                q.enqueue(node);
            }
        }
    }

    c.createHuffmanTree(q);
    for (int i = 0; i < index; i++) {
        std::string code = "";
        bool checkVal = false;
        c.getCode(arr[i], q.getFront(), code, checkVal);
        output << arr[i] << " " << code << " ";
    }

    input.close();
    output.close();

    delete[] arr;
    return 0;
}

/*MaxHeap maxHeap;
    MinHeap minHeap;
    MedianHeap medHeap;

    std::cout << "----------------------------------------------------------------------------------" << std::endl;
    medHeap.insert(6);
    medHeap.insert(12);
    medHeap.insert(4);
    medHeap.insert(5);
    medHeap.insert(3);
    medHeap.insert(8);
    medHeap.insert(7);
    medHeap.insert(9);
    medHeap.insert(1);

    std::cout << medHeap.findMedian() << std::endl;

    std::cout << "----------------------------------------------------------------------------------" << std::endl;
    minHeap.insert(6);
    minHeap.insert(12);
    minHeap.insert(4);
    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(8);
    minHeap.insert(7);

    minHeap.display();


    std::cout << "----------------------------------------------------------------------------------" << std::endl;
    maxHeap.insert(6);
    maxHeap.insert(12);
    maxHeap.insert(4);
    maxHeap.insert(5);
    maxHeap.insert(3);
    maxHeap.insert(8);
    maxHeap.insert(7);

    maxHeap.display();

    std::cout << "----------------------------------------------------------------------------------" << std::endl;
    HuffmanQueue hq;
    MinHeapNode* m1 = new MinHeapNode('a', 45, nullptr, nullptr);
    MinHeapNode* m2 = new MinHeapNode('b', 13, nullptr, nullptr);
    MinHeapNode* m3 = new MinHeapNode('c', 12, nullptr, nullptr);
    MinHeapNode* m4 = new MinHeapNode('d', 16, nullptr, nullptr);
    MinHeapNode* m5 = new MinHeapNode('e', 9, nullptr, nullptr);
    MinHeapNode* m6 = new MinHeapNode('f', 5, nullptr, nullptr);

    hq.enqueue(m1);
    hq.enqueue(m2);
    hq.enqueue(m3);
    hq.enqueue(m4);
    hq.enqueue(m5);
    hq.enqueue(m6);

    hq.display();

    HuffmanCode c;
    c.createHuffmanTree(hq);

    std::string str = "";
    bool b = false;
    c.getCode('a', hq.getFront(), str, b);
    std::cout << str << std::endl;

    b = false;
    str = "";
    c.getCode('b', hq.getFront(), str, b);
    std::cout << str << std::endl;

    b = false;
    str = "";
    c.getCode('c', hq.getFront(), str, b);
    std::cout << str << std::endl;

    b = false;
    str = "";
    c.getCode('d', hq.getFront(), str, b);
    std::cout <<  str << std::endl;

    b = false;
    str = "";
    c.getCode('e', hq.getFront(), str, b);
    std::cout << str << std::endl;

    b = false;
    str = "";
    c.getCode('f', hq.getFront(), str, b);
    std::cout << str << std::endl;*/