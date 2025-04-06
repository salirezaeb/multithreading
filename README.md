
# 🔢 Parallel and Serial Vector Addition & Matrix Multiplication in C++

This project benchmarks **multi-threaded vs serial implementations** of vector addition and matrix multiplication using C++.

---

## 🎯 Objective

To evaluate the performance benefits of parallel computation using threads in C++, comparing against traditional serial computation.

---

## 🔁 Implemented Versions

### 1. Vector Addition
- **Serial Version**: Performs sum of two arrays element-by-element using a single loop.
- **Parallel Version**: Divides work across `n` threads, each computing a chunk of the array.

### 2. Matrix Multiplication
- **Serial Version**: Not explicitly listed but used for baseline measurements.
- **Parallel Version**: Assigns each matrix row to a thread. Threads compute `C[i][j] = Σ A[i][k] × B[k][j]`.

---

## 🧠 Algorithm Overview

### Vector Addition (Length: 1000)
- Arrays `array1[]` and `array2[]` are filled with random values.
- The result `sum[]` is stored in a third array.
- `usleep(10000)` adds a delay to simulate computation.

### Matrix Multiplication (8×8)
- Classical triple-loop matrix multiplication.
- Multi-threaded version uses `step_i++` to assign rows to threads.
- Synchronization is handled via `std::thread::join()`.

---

## 🔧 Technologies

- Language: C++
- Libraries: `<thread>`, `<unistd.h>`, `<ctime>`
- Compilation: `g++ -pthread`
- Thread Count: Based on manual set (e.g., 8 cores)

---

## 📈 Performance Summary

### Vector Addition (1000 elements)
| Version     | Time (ms) | Speedup |
|-------------|-----------|---------|
| Serial      | ~17.5     | 1×      |
| Parallel(2) | ~9.7      | 1.77×   |

### Matrix Multiplication (8x8)
| Version      | Time (ms) | Speedup |
|--------------|-----------|---------|
| Serial       | ~17.6     | 1×      |
| Parallel(10) | ~1.6      | 9.65×   |

---

## 📤 Outputs

- Print arrays `array1`, `array2`, and their element-wise sum
- Print matrices A, B, and result C
- Number of threads used is also displayed

---

## 🚀 How to Run

### Compile:
```bash
g++ -std=c++11 -pthread vector_add_serial.cpp -o vec_serial
g++ -std=c++11 -pthread vector_add_parallel.cpp -o vec_parallel
g++ -std=c++11 -pthread matrix_mult_parallel.cpp -o mat_parallel
```

### Execute:
```bash
./vec_serial
./vec_parallel
./mat_parallel
```

---

## 📄 License

This repository is shared under the MIT License for educational and benchmarking purposes.

---

## 👨‍💻 Author

Developed for coursework on multithreaded computing and C++ concurrency.
