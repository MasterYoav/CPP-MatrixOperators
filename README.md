# Matrix Operators Task

**Author:** realyoavperetz@gmail.com  
**Course:** System Programming 2  
**Topic:** Operator Overloading & Square Matrix Implementation

---

##  Project Description

This project implements a `SquareMatrix` class for real-valued **square matrices**, showcasing deep understanding of:

- **Operator Overloading** – Arithmetic, unary, comparison, compound assignment, and access
- **The Rule of Three** – Copy constructor, assignment operator, and destructor
- **Dynamic Memory Management** – Using raw `new`/`delete` (no STL containers)

The class supports intuitive usage like:
```cpp
SquareMat A(3), B(3);
A[1][2] = 4.5;
SquareMat C = A + B;
```

- **Unit Testing:** Built using [doctest](https://github.com/doctest/doctest)
- **Memory Management:** Fully manual (`new`, `delete`), validated using **Valgrind**
- **STL-Free:** No use of STL containers like `vector`, `array`, or `map`

---

##  Folder Structure
```plaintext
.
├── include/          # Header files (.h/.hpp)
│   └── doctest.h
    └── SquareMatrix.hpp
│
├── source/           # Implementation files (.cpp)
│   └── SquareMatrix.cpp
│
├── tests/            # Unit test file (doctest-based)
│   └── test.cpp
│
├── main.cpp          # Interactive demo and examples
├── Makefile          # Program builder 
└── README.md         # This file
```
---
## Operators

The `SquareMat` class supports the following matrix operators:

- **Arithmetic Operators**:
  - `+` : Matrix addition
  - `-` : Matrix subtraction
  - `*` : Matrix multiplication
  - `*` : Scalar multiplication
  - `/` : Scalar division
  - `%` : Scalar modulo

- **Unary Operators**:
  - `-` : Unary negation (negates all elements)
  - `~` : Transpose (swaps rows and columns)

- **Power Operator**:
  - `^` : Matrix exponentiation (raises matrix to a power)

- **Comparison Operators**:
  - `==` : Checks if two matrices are equal (based on sum of elements)
  - `!=` : Checks if two matrices are not equal
  - `<` : Less than (based on sum of elements)
  - `>` : Greater than (based on sum of elements)
  - `<=` : Less than or equal to
  - `>=` : Greater than or equal to

- **Determinant Operator**:
  - `!` : Calculates the determinant of the matrix

- **Output Operator**:
  - `>>` : Outputs the matrix to an output stream

---

##  Build Instructions

###  Build the main demo
To compile and run the main program:
```bash
make Main
```

###  Run tests
To compile and run the unit tests:
```bash
make test
```

###  Run memory checks with Valgrind
To check for memory leaks:
```bash
make valgrind
```

###  Clean build files
To remove all executables and object files:
```bash
make clean
```
