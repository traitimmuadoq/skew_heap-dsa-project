# Skew Heap - Data Structures and Algorithms Project

A comprehensive implementation and analysis of Skew Heap data structure, developed as part of the Data Structures and Algorithms coursework at the University of Science, VNU-HCM.

## 📋 Project Overview

This project provides a complete study of **Skew Heap**, a self-adjusting heap data structure that focuses on optimizing merge operations. Unlike traditional heaps, Skew Heap maintains heap properties without structural constraints, relying on unconditional child swapping to ensure efficiency.

### Key Features
- 🔄 **Efficient Merge Operations**: O(log n) amortized time complexity
- 🏗️ **Self-Adjusting Structure**: No additional structural properties required
- 📊 **Comprehensive Analysis**: Includes best-case, worst-case, and amortized complexity analysis
- 🔍 **Performance Comparison**: Detailed comparison with Binary Heap and Leftist Heap
- 💻 **Complete Implementation**: Both recursive and iterative merge algorithms

## 👥 Team Members

| Name | Student ID | Role |
|------|------------|------|
| Nguyen Dinh Le Vu | 24120016 | Report: Overview, Basic Operations, Merge Complexity Analysis |
| Nguyen Phuoc Khang | 24120189 | Report: Implementation & Complexity, Programming; Source Code: Merge, Insert, ExtractMin, Build Operations |
| Pham Minh Dat | 24120174 | Report: Heap Comparison Analysis; Source Code: Utility functions |

## 🏗️ Project Structure
```
skew-heap-project/
├── src/
│ ├── SkewHeap.cpp # Core Skew Heap implementation
│ ├── RecordSkewHeap.cpp # Extended version with performance tracking
│ ├── RecordSkewHeap.h # Header file with declarations
│ └── Main.cpp # Main program with test cases
├── docs/
│ └── report.pdf # Comprehensive 35-page technical report
├── README.md # This file
└── skew_heap.exe # Compiled executable
```

## 🚀 Getting Started

### Prerequisites
- C++ compiler with C++11 support (GCC recommended)
- Minimum stack size of 16MB for recursive operations

### Compilation
```
cd project-directory
g++ -std=c++11 --stack=16777216 *.cpp -o skew_heap
```

### Running the Program
```
./skew_heap
```

## 🔧 Core Operations

### 1. Merge Operation
The fundamental operation that combines two Skew Heaps while maintaining heap properties.

**Time Complexity:**
- Best Case: O(1)
- Worst Case: O(n)
- Amortized: O(log n)

### 2. Insert Operation
Inserts a new element by creating a single-node heap and merging with existing heap.

**Time Complexity:** Same as merge operation

### 3. Extract Minimum
Removes and returns the minimum element (root) by merging left and right subtrees.

**Time Complexity:** Same as merge operation

## 📊 Performance Analysis

### Amortized Analysis
Our implementation achieves **O(log n) amortized time complexity** for all major operations using potential function analysis. The potential function Φ(H) is defined as the number of heavy right nodes in heap H.

### Comparison with Other Heaps

| Operation | Binary Heap | Leftist Heap | Skew Heap |
|-----------|-------------|--------------|-----------|
| Insert | O(log n) | O(log n) | O(log n)* |
| Extract Min | O(log n) | O(log n) | O(log n)* |
| Merge | O(n) | O(log n) | O(log n)* |
| Find Min | O(1) | O(1) | O(1) |

*Amortized complexity; worst-case may be O(n)

## 🎯 Key Contributions

1. **Theoretical Analysis**: Complete mathematical proof of O(log n) amortized complexity
2. **Implementation Variants**: Both recursive and non-recursive merge algorithms
3. **Performance Tracking**: Built-in comparison counting and timing mechanisms
4. **Comprehensive Testing**: Multiple test cases covering edge cases and performance scenarios
5. **Educational Value**: Detailed explanations and visualizations for learning purposes

## 📈 Applications

- **Priority Queues**: Efficient mergeable priority queue implementation
- **Graph Algorithms**: Suitable for algorithms requiring frequent merge operations
- **Functional Programming**: Simple structure ideal for functional language implementations
- **Parallel Processing**: Merge capability useful in parallel and distributed systems

## 🔬 Research Insights

Our analysis reveals that while Skew Heap may have O(n) worst-case performance, its amortized O(log n) complexity makes it practically efficient. The unconditional swapping strategy eliminates the need for maintaining additional structural information (like NPL in Leftist Heaps), resulting in simpler implementation with comparable performance.

## 📚 Documentation

For detailed theoretical analysis, proofs, and extensive examples, please refer to our [comprehensive technical report](docs/report.pdf) (35 pages, in Vietnamese).

## 🎓 Academic Context

This project was completed as part of:
- **Course**: Data Structures and Algorithms
- **Institution**: Faculty of Information Technology, University of Science, VNU-HCM
- **Instructors**: Dr. Nguyen Thanh Phuong, Dr. Nguyen Thanh Tinh
- **Date**: May 25, 2025

## 📝 License

This project is developed for educational purposes. The LaTeX template used in the report is provided under GNU General Public License v3.0.

## 🤝 Contributing

As this is an academic project, contributions are limited to the original team members. However, feedback and suggestions for improvement are welcome for future iterations.

## 📞 Contact

For questions about this implementation or the theoretical analysis, please contact the team members through their university email addresses.

---

**Note**: This implementation is designed primarily for educational and research purposes. For production use, consider additional optimizations and error handling mechanisms.
