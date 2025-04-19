// Author: realyoavperetz@gmail.com

#pragma once

#include <iostream> // Include for std::ostream and std::endl

namespace operators {

class SquareMat {
private:
    double** data; // 2D dynamic array holding matrix elements
    int size;      // Number of rows = columns (square matrix)

    // Helper to allocate a size x size matrix
    void allocate(int newSize);

    // Helper to deallocate current matrix
    void deallocate();

public:
    // --- Constructors and Destructor ---

    /**
     * Constructs a square matrix with the specified size.
     * All elements are initialized to zero.
     * @param size The number of rows/columns in the matrix
     * @throws std::invalid_argument if size is not positive
     */
    SquareMat(int size);

    /**
     * Copy constructor - creates a deep copy of another matrix
     * @param other The matrix to copy
     */
    SquareMat(const SquareMat& other);

    /**
     * Destructor - frees all allocated memory
     */
    ~SquareMat();

    /**
     * Assignment operator - replaces the contents with a copy of another matrix
     * @param other The matrix to copy
     * @return Reference to this matrix
     */
    SquareMat& operator=(const SquareMat& other);

    // --- Access and Print ---

    /**
     * Accessor for matrix rows that allows writing elements
     * @param index The row index
     * @return Pointer to the row's data
     * @throws std::out_of_range if index is invalid
     */
    double* operator[](int index);

    /**
     * Const accessor for matrix rows that allows reading elements
     * @param index The row index
     * @return Const pointer to the row's data
     * @throws std::out_of_range if index is invalid
     */
    const double* operator[](int index) const;

    // --- Arithmetic Operators ---

    /**
     * Adds this matrix with another matrix element-by-element
     * @param other Matrix to add
     * @return New matrix containing the sum
     * @throws std::invalid_argument if matrices have different sizes
     */
    SquareMat operator+(const SquareMat& other) const;

    /**
     * Subtracts another matrix from this matrix element-by-element
     * @param other Matrix to subtract
     * @return New matrix containing the difference
     * @throws std::invalid_argument if matrices have different sizes
     */
    SquareMat operator-(const SquareMat& other) const;

    /**
     * Multiplies this matrix with another matrix using matrix multiplication
     * @param other Matrix to multiply with
     * @return New matrix containing the product
     * @throws std::invalid_argument if matrices have different sizes
     */
    SquareMat operator*(const SquareMat& other) const;

    /**
     * Element-wise multiplication of two matrices (Hadamard product)
     * @param other Matrix to multiply with element-by-element
     * @return New matrix with each element being the product of corresponding elements
     * @throws std::invalid_argument if matrices have different sizes
     */
    SquareMat operator%(const SquareMat& other) const;

    // --- Scalar Operations ---

    /**
     * Multiplies each element in the matrix by a scalar
     * @param scalar The value to multiply by
     * @return New matrix with scaled elements
     */
    SquareMat operator*(double scalar) const;

    /**
     * Divides each element in the matrix by a scalar
     * @param scalar The value to divide by
     * @return New matrix with divided elements
     * @throws std::invalid_argument if scalar is zero
     */
    SquareMat operator/(double scalar) const;

    /**
     * Applies modulo operation to each element in the matrix
     * @param scalar The modulo value (integer)
     * @return New matrix with modulo applied to each element
     * @throws std::invalid_argument if scalar is zero
     */
    SquareMat operator%(int scalar) const;

    // --- Unary and Binary Operators ---

    /**
     * Negates all elements in the matrix
     * @return New matrix with negated elements
     */
    SquareMat operator-() const;

    /**
     * Transposes the matrix (rows become columns and vice versa)
     * @return New transposed matrix
     */
    SquareMat operator~() const;

    /**
     * Raises the matrix to a power
     * @param power The exponent (non-negative integer)
     * @return New matrix representing this matrix raised to the power
     * @throws std::invalid_argument if power is negative
     */
    SquareMat operator^(int power) const;

    /**
     * Pre-increment operator: adds 1 to all elements
     * @return Reference to this matrix after incrementing
     */
    SquareMat& operator++();

    /**
     * Post-increment operator: adds 1 to all elements
     * @return Copy of the matrix before incrementing
     */
    SquareMat operator++(int);

    /**
     * Pre-decrement operator: subtracts 1 from all elements
     * @return Reference to this matrix after decrementing
     */
    SquareMat& operator--();

    /**
     * Post-decrement operator: subtracts 1 from all elements
     * @return Copy of the matrix before decrementing
     */
    SquareMat operator--(int);

    // --- Compound Assignment Operators ---

    /**
     * Adds another matrix to this matrix in-place
     * @param other Matrix to add
     * @return Reference to this matrix after addition
     * @throws std::invalid_argument if matrices have different sizes
     */
    SquareMat& operator+=(const SquareMat& other);

    /**
     * Subtracts another matrix from this matrix in-place
     * @param other Matrix to subtract
     * @return Reference to this matrix after subtraction
     * @throws std::invalid_argument if matrices have different sizes
     */
    SquareMat& operator-=(const SquareMat& other);

    /**
     * Multiplies this matrix by another matrix in-place
     * @param other Matrix to multiply with
     * @return Reference to this matrix after multiplication
     * @throws std::invalid_argument if matrices have different sizes
     */
    SquareMat& operator*=(const SquareMat& other);

    /**
     * Divides all elements by a scalar in-place
     * @param scalar The value to divide by
     * @return Reference to this matrix after division
     * @throws std::invalid_argument if scalar is zero
     */
    SquareMat& operator/=(double scalar);

    /**
     * Applies modulo operation to all elements in-place
     * @param scalar The modulo value
     * @return Reference to this matrix after modulo
     * @throws std::invalid_argument if scalar is zero
     */
    SquareMat& operator%=(int scalar);

    /**
     * Performs element-wise multiplication with another matrix in-place
     * @param other Matrix to multiply with element-by-element
     * @return Reference to this matrix after operation
     * @throws std::invalid_argument if matrices have different sizes
     */
    SquareMat& operator%=(const SquareMat& other);

    // --- Comparison Operators ---

    /**
     * Equality operator - matrices are equal if the sum of their elements is equal
     * @param other Matrix to compare with
     * @return true if matrices have equal sums, false otherwise
     */
    bool operator==(const SquareMat& other) const;

    /**
     * Inequality operator - matrices are unequal if the sum of their elements is not equal
     * @param other Matrix to compare with
     * @return true if matrices have unequal sums, false otherwise
     */
    bool operator!=(const SquareMat& other) const;

    /**
     * Less than operator - compares the sum of elements
     * @param other Matrix to compare with
     * @return true if this matrix's sum is less than other's sum
     */
    bool operator<(const SquareMat& other) const;

    /**
     * Greater than operator - compares the sum of elements
     * @param other Matrix to compare with
     * @return true if this matrix's sum is greater than other's sum
     */
    bool operator>(const SquareMat& other) const;

    /**
     * Less than or equal to operator - compares the sum of elements
     * @param other Matrix to compare with
     * @return true if this matrix's sum is less than or equal to other's sum
     */
    bool operator<=(const SquareMat& other) const;

    /**
     * Greater than or equal to operator - compares the sum of elements
     * @param other Matrix to compare with
     * @return true if this matrix's sum is greater than or equal to other's sum
     */
    bool operator>=(const SquareMat& other) const;

    // --- Friend functions and operators ---

    /**
     * Calculates the sum of all elements in the matrix
     * @param mat Matrix whose elements to sum
     * @return Sum of all elements
     */
    friend double sumElements(const SquareMat& mat);

    /**
     * Determinant operator - calculates the determinant of the matrix
     * @return The determinant value
     */
    double operator!() const;

    /**
     * Output operator - prints the matrix in a formatted way
     * @param os Output stream
     * @param mat Matrix to output
     * @return Reference to the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
};

/**
 * Scalar multiplication operator (scalar * matrix)
 * @param scalar The scalar value
 * @param mat Matrix to multiply
 * @return New matrix with scaled elements
 */
SquareMat operator*(double scalar, const SquareMat& mat);

} // namespace operators
