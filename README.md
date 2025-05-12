
# AVL Tree Rotations in C++

## Overview

This project implements an AVL Tree in C++, focusing on insertion with automatic self-balancing through rotations (LL, RR, LR, RL). It includes theoretical complexity analysis, empirical benchmarking, and real-world applications in in-memory database indexing.

## Features

- Insertion with balancing
- All four rotation types: LL, RR, LR, RL
- In-order traversal
- Runtime benchmarking using `chrono`
- Clean and modular C++ design

## Setup

### Requirements

- C++11 or higher
- Standard C++ compiler (e.g., g++, clang++)
- Python or gnuplot (optional, for plotting benchmarks)

### Compilation

```bash
g++ -std=c++11 avl_tree.cpp -o avl_tree
```

### Run

```bash
./avl_tree
```

The program will:
1. Insert a small set of values and print in-order traversal.
2. Benchmark insertion performance for 100, 1,000, 10,000, and 100,000 elements.

## Example Output

```
In-order traversal of AVL Tree:
5 10 20 25 30 35 40 50

Benchmarking performance:
Inserted 100 nodes in 0.0003 seconds
Inserted 1000 nodes in 0.0020 seconds
Inserted 10000 nodes in 0.0150 seconds
Inserted 100000 nodes in 0.1300 seconds
```

## File Structure

```
/AVL-Trees/
├── code/
│   └── avl_tree.cpp
├── docs/
│   ├── steps.md
│   └── complexity.md
├── README.md
├── REPORT.pdf
```

## Real-World Application

AVL Trees are commonly used in database indexing and memory-resident data structures that require predictable and fast read times. This project focuses on their role in in-memory databases like SQLite and Redis.

## License

This project is provided for academic purposes.
