#include <iostream>
#include <stack>
#include <queue>
#include <vector>
typedef struct Node *ref;
struct Node
{
    int key;
    ref left;
    ref right;
};

struct SkewHeap
{
    ref root;
    SkewHeap() : root(NULL) {};
};

//1.Test whether a heap is empty.
bool isEmpty(SkewHeap s) {
    return s.root == nullptr;
}

//2.Get the number of items in the heap

//2.1Recursion
int sizeOfTree(ref root) {
    if (!root) return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

int getSize(const SkewHeap& s) {
    return sizeOfTree(s.root);
}


//2.2Non-recursion
int getSizeNonRecursion(SkewHeap s) {
    if(isEmpty(s)) return 0;

    ref root = s.root;

    std::queue<ref> q;
    q.push(root);
    int count = 0;

    while(!q.empty()) {
        ref cur = q.front();
        q.pop();
        count++;

        if(cur->left) 
            q.push(cur->left);
        if(cur->right) 
            q.push(cur->right);
    }

    return count;
}

//3. Return the item at the root of the heap
int getRoot(SkewHeap s) {
    if(isEmpty(s)) return 0;
    return s.root->key;
}

//4. Remove all items from the heap

//4.1 Recursion
void clearTree(ref &root) {
    if (!root) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
    root = nullptr;
}

void clearHeap(SkewHeap &s) {
    clearTree(s.root);
}

//4.2 Non-Recursion
void clearHeapNonRecursion(SkewHeap &s) {
    if(isEmpty(s)) return;

    ref root = s.root;
    std::queue<ref> q;
    q.push(root);

    while(!q.empty()) {
        ref cur = q.front();
        q.pop();

        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);

        delete cur;
    }

    s.root = nullptr;
}
// Merge Function - heart of SkewHeap

//recursion
ref Merge(ref &a, ref &b)
{
    if (!b)
        return a;
    if (!a)
        return b;
    if (a->key > b->key)
        std::swap(a, b);
    a->right = Merge(a->right, b);
    ref p = a->right;
    a->right = a->left;
    a->left = p;
    return a;
}


//Non-recursion
void nonRecursionMerge(ref &a, ref &b)
{
    if (!a)
    {
        a = b;
        b = NULL;
        return;
    }
    if (!b)
        return;

    std::stack<ref> Store;
    ref prev = NULL, Cur = NULL, temp = NULL;
    ref p = a;
    ref q = b;

    while (p && q)
    {
        if (p->key > q->key)
        {
            Store.push(q);
            q = q->right;
        }
        else
        {
            Store.push(p);
            p = p->right;
        }
    }

    if (p)
        prev = p;
    else
        prev = q;

    while (!Store.empty())
    {
        Cur = Store.top();
        Store.pop();
        Cur->right = prev;
        temp = Cur->right;
        Cur->right = Cur->left;
        Cur->left = temp;
        prev = Cur;
    }
    a = prev;
    b = NULL;
}

//5. Insert a new item into the heap.
void insert(SkewHeap &s, int key)
{
    ref p = new Node{key, NULL, NULL};

    if (!s.root)
        s.root = p;
    else
        nonRecursionMerge(s.root, p);
}


//6. Remove an item from the heap
void extractMin(SkewHeap &s)
{
    if (!s.root)
        return;

    ref p = s.root;
    ref leftSub = p->left;
    ref rightSub = p->right;

    nonRecursionMerge(leftSub, rightSub);

    s.root = leftSub;

    delete p;
}


//7. Build a heap from given items
SkewHeap buildSkewHeap(std::vector<int> items)
{
    std::queue<ref> store;
    ref p = NULL, q = NULL;
    int n = items.size();
    for (int i = 0; i < n; i += 2)
    {
        p = new Node{items[i], NULL, NULL};
        if (i + 1 == n)
            q = NULL;
        else
            q = new Node{items[i + 1], NULL, NULL};
        if (q)
            nonRecursionMerge(p, q);
        store.push(p);
    }
    
    while (store.size() > 1)
    {
        int sz = store.size();
        int m = sz / 2;
        for (int i = 0; i < m; ++i)
        {
            p = store.front(); store.pop();
            q = store.front(); store.pop();
            nonRecursionMerge(p, q);
            store.push(p);
        }
        if (sz % 2 == 1)
        {
            p = store.front();
            store.pop();
            store.push(p);
        }
    }
    p = store.front();
    SkewHeap s;
    s.root = p;
    return s;
}

//Duyệt cây
void LNR(Node *root)
{
    if (!root)
        return;
    LNR(root->left);
    std::cout << root->key << " ";
    LNR(root->right);
}

void LRN(Node *root)
{
    if (!root)
        return;
    LRN(root->left);
    LRN(root->right);
    std::cout << root->key << " ";
}

void NLR(Node *root)
{
    if (!root)
        return;
    std::cout << root->key << " ";
    NLR(root->left);
    NLR(root->right);
}

void LevelOrder(Node *root)
{
    std::queue<Node *> s;
    s.push(root);
    std::cout << root->key << " ";
    while (!s.empty())
    {
        Node *p = s.front();
        s.pop();
        if (p->left)
        {
            std::cout << p->left->key << " ";
            s.push(p->left);
        }
        if (p->right)
        {
            std::cout << p->right->key << " ";
            s.push(p->right);
        }
    }
}

int main() {
    SkewHeap s;

    std::vector<int> values = {30, 20, 40, 10, 25, 50, 15}; 

    std::cout << "=== Inserting elements ===\n";
    for (int i = 0; i < 6; ++i) { 
        std::cout << "Insert: " << values[i] << "\n";
        insert(s, values[i]);
    }

    std::cout << "\nTree traversal (NLR - Preorder) after inserting 6 elements:\n";
    NLR(s.root);
    std::cout << "\n";

    std::cout << "\nInsert one more element: " << values[6] << "\n";
    insert(s, values[6]);

    std::cout << "\nTree traversal (Level-Order) after inserting 7 elements:\n";
    LevelOrder(s.root);
    std::cout << "\n";

    std::cout << "\nExtracting min (remove root): " << getRoot(s) << "\n";
    extractMin(s);

    std::cout << "\nTree traversal (Level-Order) after extractMin:\n";
    LevelOrder(s.root);
    std::cout << "\n";

    return 0;
}



