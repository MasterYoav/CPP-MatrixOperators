// Author: realyoavperetz@gmail.com

#include "SquareMatrix.hpp"
#include <stdexcept> 

namespace operators {

// Allocate memory for a size x size matrix
void SquareMat::allocate(int newSize) {
    size = newSize;
    data = new double*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size](); // initialize row with zeros
    }
}

// Deallocate memory
void SquareMat::deallocate() {
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;
    data = nullptr;
    size = 0;
}

// Constructor with size
SquareMat::SquareMat(int newSize) {
    if (newSize <= 0)
        throw std::invalid_argument("Matrix size must be positive");
    allocate(newSize);
}

// Copy constructor
SquareMat::SquareMat(const SquareMat& other) {
    allocate(other.size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] = other.data[i][j];
}

// Destructor
SquareMat::~SquareMat() {
    deallocate();
}

// Assignment operator
SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this != &other) {
        deallocate();
        allocate(other.size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                data[i][j] = other.data[i][j];
    }
    return *this;
}

// Row accessor (non-const)
double* SquareMat::operator[](int index) {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of bounds");
    return data[index];
}

// Row accessor (const version)
const double* SquareMat::operator[](int index) const {
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of bounds");
    return data[index];
}

// Addition operator
SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] + other[i][j];
        }
    }
    return result;
}

// Subtraction operator
SquareMat SquareMat::operator-(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] - other[i][j];
        }
    }
    return result;
}

// Multiplication operator
SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += data[i][k] * other[k][j];
            }
        }
    }
    return result;
}

// Element-wise multiplication operator (Hadamard product)
SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] * other[i][j];
        }
    }
    return result;
}

// Scalar multiplication operator
SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

// Scalar multiplication operator (from left)
SquareMat operator*(double scalar, const SquareMat& mat) {
    return mat * scalar; // Reuse the existing method
}

// Scalar division operator
SquareMat SquareMat::operator/(double scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] / scalar;
        }
    }
    return result;
}

// Scalar modulo operator
SquareMat SquareMat::operator%(int scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Modulo by zero");
    }
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = static_cast<int>(data[i][j]) % scalar;
        }
    }
    return result;
}

// Unary minus operator
SquareMat SquareMat::operator-() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = -data[i][j];
        }
    }
    return result;
}

// Transpose operator
SquareMat SquareMat::operator~() const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[j][i];
        }
    }
    return result;
}

// Power operator
SquareMat SquareMat::operator^(int power) const {
    if (power < 0) {
        throw std::invalid_argument("Negative powers are not supported");
    }
    SquareMat result(size);
    SquareMat base(*this);
    // Initialize result as identity matrix
    for (int i = 0; i < size; ++i) {
        result[i][i] = 1;
    }
    while (power) {
        if (power % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        power /= 2;
    }
    return result;
}

// Pre-increment operator
SquareMat& SquareMat::operator++() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] += 1;
        }
    }
    return *this;
}

// Post-increment operator
SquareMat SquareMat::operator++(int) {
    SquareMat temp(*this); // Save current state
    ++(*this);             // Call pre-increment
    return temp;           // Return saved state
}

// Pre-decrement operator
SquareMat& SquareMat::operator--() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] -= 1;
        }
    }
    return *this;
}

// Post-decrement operator
SquareMat SquareMat::operator--(int) {
    SquareMat temp(*this); // Save current state
    --(*this);             // Call pre-decrement
    return temp;           // Return saved state
}

// Compound assignment: Addition
SquareMat& SquareMat::operator+=(const SquareMat& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size");
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] += other[i][j];
        }
    }
    return *this;
}

// Compound assignment: Subtraction
SquareMat& SquareMat::operator-=(const SquareMat& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size");
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] -= other[i][j];
        }
    }
    return *this;
}

// Compound assignment: Matrix multiplication
SquareMat& SquareMat::operator*=(const SquareMat& other) {
    *this = *this * other; // Reuse the existing multiplication operator
    return *this;
}

// Compound assignment: Division by scalar
SquareMat& SquareMat::operator/=(double scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero");
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] /= scalar;
        }
    }
    return *this;
}

// Compound assignment: Modulo by scalar
SquareMat& SquareMat::operator%=(int scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Modulo by zero");
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = static_cast<int>(data[i][j]) % scalar;
        }
    }
    return *this;
}

// Compound assignment: Element-wise multiplication
SquareMat& SquareMat::operator%=(const SquareMat& other) {
    if (size != other.size) {
        throw std::invalid_argument("Matrices must be of the same size");
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] *= other[i][j];
        }
    }
    return *this;
}

// Helper function to calculate the sum of all elements in the matrix
inline double sumElements(const SquareMat& mat) {
    double sum = 0;
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            sum += mat[i][j];
        }
    }
    return sum;
}

// Equality operator
bool SquareMat::operator==(const SquareMat& other) const {
    return sumElements(*this) == sumElements(other);
}

// Inequality operator
bool SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);
}

// Less than operator
bool SquareMat::operator<(const SquareMat& other) const {
    return sumElements(*this) < sumElements(other);
}

// Greater than operator
bool SquareMat::operator>(const SquareMat& other) const {
    return sumElements(*this) > sumElements(other);
}

// Less than or equal to operator
bool SquareMat::operator<=(const SquareMat& other) const {
    return !(*this > other);
}

// Greater than or equal to operator
bool SquareMat::operator>=(const SquareMat& other) const {
    return !(*this < other);
}

// Helper function to calculate the determinant of a matrix
static double determinant(double** matrix, int n) {
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    double det = 0;
    double** submatrix = new double*[n-1];
    for (int i = 0; i < n-1; ++i) {
        submatrix[i] = new double[n-1];
    }
    for (int x = 0; x < n; ++x) {
        int subi = 0;
        for (int i = 1; i < n; ++i) {
            int subj = 0;
            for (int j = 0; j < n; ++j) {
                if (j == x) continue;
                submatrix[subi][subj] = matrix[i][j];
                ++subj;
            }
            ++subi;
        }
        det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix, n-1);
    }
    for (int i = 0; i < n-1; ++i) {
        delete[] submatrix[i];
    }
    delete[] submatrix;
    return det;
}

// Determinant operator
double SquareMat::operator!() const {
    return determinant(data, size);
}

// Output operator
std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
    for (int i = 0; i < mat.size; ++i) {
        for (int j = 0; j < mat.size; ++j) {
            os << mat.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

} // namespace operators
