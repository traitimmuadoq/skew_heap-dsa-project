#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RecordSkewHeap.h"

// Hàm test insert 10,000 phần tử
void insertOperation(SkewHeap& s, long long& comparison) {
    for (int i = 0; i < 10000; ++i)
        insert(s, rand() % 10000, comparison); // Dữ liệu ngẫu nhiên
}

// Hàm test extractMin 5,000 lần
void extractOperation(SkewHeap& s, long long& comparison) {
    for (int i = 0; i < 5000; ++i)
        extractMin(s, comparison);
}

int main() {
    srand(time(nullptr)); // Khởi tạo seed ngẫu nhiên

    // Test 1: Insert từng phần tử
    std::cout << "===== Test Insert (10,000 elements) =====\n";
    SkewHeap s1;
    Record rInsert = getRecord(insertOperation, s1);
    std::cout << "Comparisons: " << rInsert.comparison << "\n";
    std::cout << "Time (ms): " << rInsert.time << "\n";
    clearHeap(s1); // Giải phóng bộ nhớ

    // Test 2: BuildHeap từ vector
    std::cout << "\n===== Test BuildHeap (10,000 elements) =====\n";
    std::vector<int> items;
    for (int i = 0; i < 10000; ++i)
        items.push_back(rand() % 10000); // Dữ liệu ngẫu nhiên

    long long compBuild = 0;
    auto start = std::chrono::high_resolution_clock::now();
    SkewHeap s2 = buildSkewHeap(items, compBuild);
    auto end = std::chrono::high_resolution_clock::now();
    long long timeBuild = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Comparisons: " << compBuild << "\n";
    std::cout << "Time (ms): " << timeBuild << "\n";

    // Test 3: ExtractMin 5,000 lần
    std::cout << "\n===== Test ExtractMin (5,000 times) =====\n";
    Record rExtract = getRecord(extractOperation, s2);
    std::cout << "Comparisons: " << rExtract.comparison << "\n";
    std::cout << "Time (ms): " << rExtract.time << "\n";

    clearHeap(s2); // Giải phóng bộ nhớ
    return 0;
}

