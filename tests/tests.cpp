// Author: realyoavperetz@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMatrix.hpp"

using namespace operators;

/**
 * Test case for matrix addition operation
 * Verifies that adding two matrices produces correct element-by-element sums
 */
TEST_CASE("Matrix addition") {
    SquareMat mat1(2);
    SquareMat mat2(2);

    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;

    mat2[0][0] = 5; mat2[0][1] = 6;
    mat2[1][0] = 7; mat2[1][1] = 8;

    SquareMat result = mat1 + mat2;

    CHECK(result[0][0] == 6);
    CHECK(result[0][1] == 8);
    CHECK(result[1][0] == 10);
    CHECK(result[1][1] == 12);
}

/**
 * Test case for matrix subtraction operation
 * Verifies that subtracting one matrix from another produces correct element-by-element differences
 */
TEST_CASE("Matrix subtraction") {
    SquareMat mat1(2);
    SquareMat mat2(2);

    mat1[0][0] = 5; mat1[0][1] = 6;
    mat1[1][0] = 7; mat1[1][1] = 8;

    mat2[0][0] = 1; mat2[0][1] = 2;
    mat2[1][0] = 3; mat2[1][1] = 4;

    SquareMat result = mat1 - mat2;

    CHECK(result[0][0] == 4);
    CHECK(result[0][1] == 4);
    CHECK(result[1][0] == 4);
    CHECK(result[1][1] == 4);
}

/**
 * Test case for matrix multiplication operation
 * Verifies that multiplying two matrices follows the rules of matrix multiplication
 */
TEST_CASE("Matrix multiplication") {
    SquareMat mat1(2);
    SquareMat mat2(2);

    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;

    mat2[0][0] = 2; mat2[0][1] = 0;
    mat2[1][0] = 1; mat2[1][1] = 2;

    SquareMat result = mat1 * mat2;

    CHECK(result[0][0] == 4);
    CHECK(result[0][1] == 4);
    CHECK(result[1][0] == 10);
    CHECK(result[1][1] == 8);
}

/**
 * Test case for element-wise matrix multiplication (Hadamard product)
 * Verifies that element-wise multiplication correctly multiplies corresponding elements
 */
TEST_CASE("Element-wise matrix multiplication") {
    SquareMat mat1(2);
    SquareMat mat2(2);

    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;

    mat2[0][0] = 5; mat2[0][1] = 6;
    mat2[1][0] = 7; mat2[1][1] = 8;

    SquareMat result = mat1 % mat2;

    CHECK(result[0][0] == 5);   // 1 * 5
    CHECK(result[0][1] == 12);  // 2 * 6
    CHECK(result[1][0] == 21);  // 3 * 7
    CHECK(result[1][1] == 32);  // 4 * 8
}

/**
 * Test case for scalar multiplication
 * Verifies that multiplying a matrix by a scalar correctly scales each element
 */
TEST_CASE("Scalar multiplication") {
    SquareMat mat(2);
    mat[0][0] = 1; mat[0][1] = 2;
    mat[1][0] = 3; mat[1][1] = 4;

    SquareMat result = mat * 2;

    CHECK(result[0][0] == 2);
    CHECK(result[0][1] == 4);
    CHECK(result[1][0] == 6);
    CHECK(result[1][1] == 8);
    
    // Test left scalar multiplication
    SquareMat resultLeft = 2 * mat;
    
    CHECK(resultLeft[0][0] == 2);
    CHECK(resultLeft[0][1] == 4);
    CHECK(resultLeft[1][0] == 6);
    CHECK(resultLeft[1][1] == 8);
}

/**
 * Test case for scalar division
 * Verifies that dividing a matrix by a scalar correctly scales each element
 */
TEST_CASE("Scalar division") {
    SquareMat mat(2);
    mat[0][0] = 2; mat[0][1] = 4;
    mat[1][0] = 6; mat[1][1] = 8;

    SquareMat result = mat / 2;

    CHECK(result[0][0] == 1);
    CHECK(result[0][1] == 2);
    CHECK(result[1][0] == 3);
    CHECK(result[1][1] == 4);
}

/**
 * Test case for scalar modulo
 * Verifies that applying modulo to each element works correctly
 */
TEST_CASE("Scalar modulo") {
    SquareMat mat(2);
    mat[0][0] = 5; mat[0][1] = 7;
    mat[1][0] = 9; mat[1][1] = 11;

    SquareMat result = mat % 3;

    CHECK(result[0][0] == 2);
    CHECK(result[0][1] == 1);
    CHECK(result[1][0] == 0);
    CHECK(result[1][1] == 2);
}

/**
 * Test case for unary minus
 * Verifies that negating a matrix correctly flips the sign of each element
 */
TEST_CASE("Unary minus") {
    SquareMat mat(2);
    mat[0][0] = 1; mat[0][1] = -2;
    mat[1][0] = 3; mat[1][1] = -4;

    SquareMat result = -mat;

    CHECK(result[0][0] == -1);
    CHECK(result[0][1] == 2);
    CHECK(result[1][0] == -3);
    CHECK(result[1][1] == 4);
}

/**
 * Test case for transpose operation
 * Verifies that the transpose correctly swaps rows and columns
 */
TEST_CASE("Transpose") {
    SquareMat mat(2);
    mat[0][0] = 1; mat[0][1] = 2;
    mat[1][0] = 3; mat[1][1] = 4;

    SquareMat result = ~mat;

    CHECK(result[0][0] == 1);
    CHECK(result[0][1] == 3);
    CHECK(result[1][0] == 2);
    CHECK(result[1][1] == 4);
}

/**
 * Test case for power operation
 * Verifies that raising a matrix to a power works correctly
 */
TEST_CASE("Power") {
    SquareMat mat(2);
    mat[0][0] = 1; mat[0][1] = 1;
    mat[1][0] = 1; mat[1][1] = 0;

    SquareMat result = mat ^ 2;

    CHECK(result[0][0] == 2);
    CHECK(result[0][1] == 1);
    CHECK(result[1][0] == 1);
    CHECK(result[1][1] == 1);
}

/**
 * Test case for increment operators
 * Verifies that both pre-increment and post-increment work correctly
 */
TEST_CASE("Increment operators") {
    SquareMat mat(2);
    mat[0][0] = 1; mat[0][1] = 2;
    mat[1][0] = 3; mat[1][1] = 4;
    
    // Test pre-increment
    SquareMat& preResult = ++mat;
    
    // Check that mat was incremented
    CHECK(mat[0][0] == 2);
    CHECK(mat[0][1] == 3);
    CHECK(mat[1][0] == 4);
    CHECK(mat[1][1] == 5);
    
    // Check that preResult references mat
    CHECK(&preResult == &mat);
    
    // Test post-increment
    SquareMat postResult = mat++;
    
    // Check that postResult contains the original values
    CHECK(postResult[0][0] == 2);
    CHECK(postResult[0][1] == 3);
    CHECK(postResult[1][0] == 4);
    CHECK(postResult[1][1] == 5);
    
    // Check that mat was incremented
    CHECK(mat[0][0] == 3);
    CHECK(mat[0][1] == 4);
    CHECK(mat[1][0] == 5);
    CHECK(mat[1][1] == 6);
}

/**
 * Test case for decrement operators
 * Verifies that both pre-decrement and post-decrement work correctly
 */
TEST_CASE("Decrement operators") {
    SquareMat mat(2);
    mat[0][0] = 3; mat[0][1] = 4;
    mat[1][0] = 5; mat[1][1] = 6;
    
    // Test pre-decrement
    SquareMat& preResult = --mat;
    
    // Check that mat was decremented
    CHECK(mat[0][0] == 2);
    CHECK(mat[0][1] == 3);
    CHECK(mat[1][0] == 4);
    CHECK(mat[1][1] == 5);
    
    // Check that preResult references mat
    CHECK(&preResult == &mat);
    
    // Test post-decrement
    SquareMat postResult = mat--;
    
    // Check that postResult contains the original values
    CHECK(postResult[0][0] == 2);
    CHECK(postResult[0][1] == 3);
    CHECK(postResult[1][0] == 4);
    CHECK(postResult[1][1] == 5);
    
    // Check that mat was decremented
    CHECK(mat[0][0] == 1);
    CHECK(mat[0][1] == 2);
    CHECK(mat[1][0] == 3);
    CHECK(mat[1][1] == 4);
}

/**
 * Test case for compound assignment addition
 * Verifies that the += operator correctly adds another matrix in-place
 */
TEST_CASE("Compound assignment addition") {
    SquareMat mat1(2);
    SquareMat mat2(2);
    
    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;
    
    mat2[0][0] = 5; mat2[0][1] = 6;
    mat2[1][0] = 7; mat2[1][1] = 8;
    
    mat1 += mat2;
    
    CHECK(mat1[0][0] == 6);
    CHECK(mat1[0][1] == 8);
    CHECK(mat1[1][0] == 10);
    CHECK(mat1[1][1] == 12);
}

/**
 * Test case for compound assignment subtraction
 * Verifies that the -= operator correctly subtracts another matrix in-place
 */
TEST_CASE("Compound assignment subtraction") {
    SquareMat mat1(2);
    SquareMat mat2(2);
    
    mat1[0][0] = 5; mat1[0][1] = 6;
    mat1[1][0] = 7; mat1[1][1] = 8;
    
    mat2[0][0] = 1; mat2[0][1] = 2;
    mat2[1][0] = 3; mat2[1][1] = 4;
    
    mat1 -= mat2;
    
    CHECK(mat1[0][0] == 4);
    CHECK(mat1[0][1] == 4);
    CHECK(mat1[1][0] == 4);
    CHECK(mat1[1][1] == 4);
}

/**
 * Test case for compound assignment multiplication
 * Verifies that the *= operator correctly multiplies with another matrix in-place
 */
TEST_CASE("Compound assignment multiplication") {
    SquareMat mat1(2);
    SquareMat mat2(2);
    
    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;
    
    mat2[0][0] = 2; mat2[0][1] = 0;
    mat2[1][0] = 1; mat2[1][1] = 2;
    
    mat1 *= mat2;
    
    CHECK(mat1[0][0] == 4);
    CHECK(mat1[0][1] == 4);
    CHECK(mat1[1][0] == 10);
    CHECK(mat1[1][1] == 8);
}

/**
 * Test case for compound assignment division
 * Verifies that the /= operator correctly divides by a scalar in-place
 */
TEST_CASE("Compound assignment division") {
    SquareMat mat(2);
    
    mat[0][0] = 2; mat[0][1] = 4;
    mat[1][0] = 6; mat[1][1] = 8;
    
    mat /= 2;
    
    CHECK(mat[0][0] == 1);
    CHECK(mat[0][1] == 2);
    CHECK(mat[1][0] == 3);
    CHECK(mat[1][1] == 4);
}

/**
 * Test case for compound assignment modulo
 * Verifies that the %= operator correctly applies modulo with a scalar in-place
 */
TEST_CASE("Compound assignment modulo with scalar") {
    SquareMat mat(2);
    
    mat[0][0] = 5; mat[0][1] = 7;
    mat[1][0] = 9; mat[1][1] = 11;
    
    mat %= 3;
    
    CHECK(mat[0][0] == 2);
    CHECK(mat[0][1] == 1);
    CHECK(mat[1][0] == 0);
    CHECK(mat[1][1] == 2);
}

/**
 * Test case for compound assignment element-wise multiplication
 * Verifies that the %= operator correctly multiplies with another matrix element-by-element in-place
 */
TEST_CASE("Compound assignment element-wise multiplication") {
    SquareMat mat1(2);
    SquareMat mat2(2);
    
    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;
    
    mat2[0][0] = 5; mat2[0][1] = 6;
    mat2[1][0] = 7; mat2[1][1] = 8;
    
    mat1 %= mat2;
    
    CHECK(mat1[0][0] == 5);   // 1 * 5
    CHECK(mat1[0][1] == 12);  // 2 * 6
    CHECK(mat1[1][0] == 21);  // 3 * 7
    CHECK(mat1[1][1] == 32);  // 4 * 8
}

/**
 * Test case for comparison operators
 * Verifies that all comparison operators work based on the sum of elements
 */
TEST_CASE("Comparison operators") {
    SquareMat mat1(2);
    SquareMat mat2(2);

    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;

    mat2[0][0] = 4; mat2[0][1] = 3;
    mat2[1][0] = 2; mat2[1][1] = 1;

    CHECK(mat1 == mat2);
    CHECK_FALSE(mat1 != mat2);
    CHECK_FALSE(mat1 < mat2);
    CHECK_FALSE(mat1 > mat2);
    CHECK(mat1 <= mat2);
    CHECK(mat1 >= mat2);
}

/**
 * Test case for matrix determinant
 * Verifies that the determinant is calculated correctly
 */
TEST_CASE("Matrix determinant") {
    SquareMat mat(2);

    mat[0][0] = 4; mat[0][1] = 6;
    mat[1][0] = 3; mat[1][1] = 8;

    double det = !mat;

    CHECK(det == 14);
} 