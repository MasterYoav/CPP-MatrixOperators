// Author: realyoavperetz@gmail.com

#include "SquareMatrix.hpp"
#include <iostream>

using namespace operators;

int main() {
    // Create two 3x3 matrices
    std::cout << "Creating two 3x3 matrices..." << std::endl;
    SquareMat mat1(3);
    SquareMat mat2(3);

    // Initialize mat1
    mat1[0][0] = 1; mat1[0][1] = 2; mat1[0][2] = 3;
    mat1[1][0] = 4; mat1[1][1] = 5; mat1[1][2] = 6;
    mat1[2][0] = 7; mat1[2][1] = 8; mat1[2][2] = 9;

    // Initialize mat2
    mat2[0][0] = 9; mat2[0][1] = 8; mat2[0][2] = 7;
    mat2[1][0] = 6; mat2[1][1] = 5; mat2[1][2] = 4;
    mat2[2][0] = 3; mat2[2][1] = 2; mat2[2][2] = 1;

    // Display the matrices
    std::cout << "Matrix 1:" << std::endl;
    std::cout << mat1;
    std::cout << "Matrix 2:" << std::endl;
    std::cout << mat2;

    // Demonstrate addition
    SquareMat sum = mat1 + mat2;
    std::cout << "\nSum of matrices (mat1 + mat2):" << std::endl;
    std::cout << sum;

    // Demonstrate subtraction
    SquareMat diff = mat1 - mat2;
    std::cout << "\nDifference of matrices (mat1 - mat2):" << std::endl;
    std::cout << diff;

    // Demonstrate multiplication
    SquareMat prod = mat1 * mat2;
    std::cout << "\nProduct of matrices (mat1 * mat2):" << std::endl;
    std::cout << prod;

    // Demonstrate element-wise multiplication
    SquareMat elemProd = mat1 % mat2;
    std::cout << "\nElement-wise product of matrices (mat1 % mat2):" << std::endl;
    std::cout << elemProd;

    // Demonstrate determinant
    double det = !mat1;
    std::cout << "\nDeterminant of mat1: " << det << std::endl;

    // Create additional matrices
    std::cout << "\nCreating a special matrix for demonstration..." << std::endl;
    SquareMat mat3(3);
    mat3[0][0] = 2; mat3[0][1] = 0; mat3[0][2] = 1;
    mat3[1][0] = 0; mat3[1][1] = 1; mat3[1][2] = 0;
    mat3[2][0] = 1; mat3[2][1] = 0; mat3[2][2] = 2;
    std::cout << mat3;

    // Demonstrate scalar multiplication from right
    SquareMat scalarMult = mat1 * 2;
    std::cout << "\nScalar multiplication of mat1 by 2 (mat1 * 2):" << std::endl;
    std::cout << scalarMult;

    // Demonstrate scalar multiplication from left
    SquareMat scalarMultLeft = 3 * mat1;
    std::cout << "\nScalar multiplication of mat1 by 3 (3 * mat1):" << std::endl;
    std::cout << scalarMultLeft;

    // Demonstrate scalar division
    SquareMat scalarDiv = mat1 / 2;
    std::cout << "\nScalar division of mat1 by 2 (mat1 / 2):" << std::endl;
    std::cout << scalarDiv;

    // Demonstrate scalar modulo
    SquareMat scalarMod = mat1 % 3;
    std::cout << "\nScalar modulo of mat1 by 3 (mat1 % 3):" << std::endl;
    std::cout << scalarMod;

    // Demonstrate unary minus
    SquareMat unaryMinus = -mat1;
    std::cout << "\nUnary minus of mat1 (-mat1):" << std::endl;
    std::cout << unaryMinus;

    // Demonstrate transpose
    SquareMat transpose = ~mat1;
    std::cout << "\nTranspose of mat1 (~mat1):" << std::endl;
    std::cout << transpose;

    // Demonstrate power
    SquareMat power = mat1 ^ 2;
    std::cout << "\nmat1 raised to the power of 2 (mat1 ^ 2):" << std::endl;
    std::cout << power;

    // Demonstrate pre-increment
    std::cout << "\nPre-increment of mat1 (++mat1):" << std::endl;
    std::cout << ++mat1;

    // Make a copy for post-increment demonstration
    SquareMat mat1Copy = mat1;
    
    // Demonstrate post-increment
    std::cout << "\nPost-increment of mat1 (mat1++):" << std::endl;
    std::cout << "Before:" << std::endl;
    std::cout << mat1Copy;
    std::cout << "Result of mat1++:" << std::endl;
    std::cout << mat1Copy++;
    std::cout << "After:" << std::endl;
    std::cout << mat1Copy;

    // Demonstrate pre-decrement
    std::cout << "\nPre-decrement of mat3 (--mat3):" << std::endl;
    std::cout << --mat3;

    // Demonstrate post-decrement
    std::cout << "\nPost-decrement of mat3 (mat3--):" << std::endl;
    std::cout << "Before:" << std::endl;
    std::cout << mat3;
    std::cout << "Result of mat3--:" << std::endl;
    std::cout << mat3--;
    std::cout << "After:" << std::endl;
    std::cout << mat3;

    // Demonstrate compound assignment operators
    SquareMat compoundMat(3);
    compoundMat = mat2; // Start with a copy of mat2
    
    std::cout << "\nCompound assignment operators:" << std::endl;
    std::cout << "Starting with a copy of mat2:" << std::endl;
    std::cout << compoundMat;
    
    // Demonstrate +=
    compoundMat += mat3;
    std::cout << "After compoundMat += mat3:" << std::endl;
    std::cout << compoundMat;
    
    // Demonstrate -=
    compoundMat -= mat3;
    std::cout << "After compoundMat -= mat3 (back to original):" << std::endl;
    std::cout << compoundMat;
    
    // Demonstrate *=
    compoundMat *= mat3;
    std::cout << "After compoundMat *= mat3:" << std::endl;
    std::cout << compoundMat;
    
    // Demonstrate /=
    compoundMat /= 2;
    std::cout << "After compoundMat /= 2:" << std::endl;
    std::cout << compoundMat;
    
    // Demonstrate %= with scalar
    compoundMat %= 3;
    std::cout << "After compoundMat %= 3:" << std::endl;
    std::cout << compoundMat;
    
    // Demonstrate %= with matrix
    compoundMat %= mat3;
    std::cout << "After compoundMat %= mat3 (element-wise multiplication):" << std::endl;
    std::cout << compoundMat;

    // Demonstrate comparison operators
    std::cout << "\nComparison of mat1 and mat2:" << std::endl;
    std::cout << "mat1 == mat2: " << (mat1 == mat2) << std::endl;
    std::cout << "mat1 != mat2: " << (mat1 != mat2) << std::endl;
    std::cout << "mat1 < mat2: " << (mat1 < mat2) << std::endl;
    std::cout << "mat1 > mat2: " << (mat1 > mat2) << std::endl;
    std::cout << "mat1 <= mat2: " << (mat1 <= mat2) << std::endl;
    std::cout << "mat1 >= mat2: " << (mat1 >= mat2) << std::endl;

    // Demonstrate determinant of a new matrix
    double det3 = !mat3;
    std::cout << "\nDeterminant of mat3: " << det3 << std::endl;

    return 0;
} 