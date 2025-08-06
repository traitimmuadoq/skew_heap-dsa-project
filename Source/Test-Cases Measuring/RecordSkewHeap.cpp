// RecordSkewHeap.cpp
#include "RecordSkewHeap.h"


bool isEmpty(SkewHeap s) {
    return s.root == nullptr;
}

int getSize(const SkewHeap& s) {
    if (!s.root) return 0;
    std::queue<ref> q;
    q.push(s.root);
    int count = 0;
    while (!q.empty()) {
        ref cur = q.front(); q.pop();
        count++;
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    return count;
}

int getRoot(SkewHeap s) {
    return s.root ? s.root->key : 0;
}

void clearHeap(SkewHeap& s) {
    if (!s.root) return;
    std::queue<ref> q;
    q.push(s.root);
    while (!q.empty()) {
        ref cur = q.front(); q.pop();
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
        delete cur;
    }
    s.root = nullptr;
}

void merge(SkewHeap& a, SkewHeap& b, long long& comparison) {
    ref& p = a.root;
    ref& q = b.root;
    if (!p) { p = q; q = nullptr; return; }
    if (!q) return;

    std::stack<ref> stk;
    while (p && q) {
        comparison++;
        if (p->key > q->key) {
            stk.push(q); q = q->right;
        } else {
            stk.push(p); p = p->right;
        }
    }

    ref prev = p ? p : q;
    while (!stk.empty()) {
        ref cur = stk.top(); stk.pop();
        cur->right = prev;
        std::swap(cur->left, cur->right);
        prev = cur;
    }
    p = prev; q = nullptr;
}

void insert(SkewHeap& s, int key, long long& comparison) {
    SkewHeap tmp;
    tmp.root = new Node{key, nullptr, nullptr};
    merge(s, tmp, comparison);
}

void extractMin(SkewHeap& s, long long& comparison) {
    if (!s.root) return;
    SkewHeap left, right;
    left.root = s.root->left;
    right.root = s.root->right;
    delete s.root;
    s.root = nullptr;
    merge(left, right, comparison);
    s.root = left.root;
}

SkewHeap buildSkewHeap(const std::vector<int>& items, long long& comparison) {
    std::queue<SkewHeap> q;
    for (int i = 0; i < items.size(); ++i) {
        SkewHeap tmp;
        insert(tmp, items[i], comparison);
        q.push(tmp);
    }
    while (q.size() > 1) {
        SkewHeap a = q.front(); q.pop();
        SkewHeap b = q.front(); q.pop();
        merge(a, b, comparison);
        q.push(a);
    }
    return q.front();
}

Record getRecord(void (*operation)(SkewHeap&, long long&), SkewHeap& s) {
    Record r;
    auto start = std::chrono::high_resolution_clock::now();
    operation(s, r.comparison);
    auto end = std::chrono::high_resolution_clock::now();
    r.time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    return r;
}
