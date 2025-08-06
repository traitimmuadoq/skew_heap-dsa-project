#ifndef RECORD_SKEW_HEAP_H
#define RECORD_SKEW_HEAP_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <chrono>

// Kiểu con trỏ node
typedef struct Node* ref;

struct Node {
    int key;
    ref left;
    ref right;
};

struct SkewHeap {
    ref root;
    SkewHeap() : root(nullptr) {}
};

// Ghi nhận số lần so sánh và thời gian thực thi (đơn vị: milliseconds)
struct Record {
    long long comparison = 0;
    long long time = 0;
};

// Hàm thao tác chính
bool isEmpty(SkewHeap s);
int getSize(const SkewHeap& s);
int getRoot(SkewHeap s);
void clearHeap(SkewHeap& s);

// Các thao tác có đếm comparison
void merge(SkewHeap& a, SkewHeap& b, long long& comparison);
void insert(SkewHeap& s, int key, long long& comparison);
void extractMin(SkewHeap& s, long long& comparison);
SkewHeap buildSkewHeap(const std::vector<int>& items, long long& comparison);

// Hàm đo thời gian và số lần so sánh
Record getRecord(void (*operation)(SkewHeap&, long long&), SkewHeap& s);

#endif
