//
// Created by Данил on 17.12.2022.
//
#ifndef matrixlib_H
#define matrixlib_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// Creat new matrix
/// \param str - Height matrix
/// \param stlb - Width matrix
struct Matrix *create_matrix(int str, int stlb);

/// Fill the matrix with a random range
/// \param min - Lower bound of randomness
/// \param max - Upper bound of randomness
/// \param matrix - The matrix to be filled in
struct Matrix *rand_matrix(int min, int max, struct Matrix *matrix);

/// Printing the matrix to the console
/// \param matrixPrint - The matrix to be printed
struct Matrix *print_matrix(struct Matrix *matrixPrint);

/// Copying the matrix
/// \param matrix - The matrix to be copied
struct Matrix *cpy_matrix(struct Matrix *matrix);

/// Matrix transposition
/// \param matrix - The matrix to be transposed
struct Matrix *trans(struct Matrix *matrix);

/// Matrix summation
/// \param matrixf - The first term
/// \param matrix2 - The second term
struct Matrix *summ_matrix(struct Matrix *matrixf, struct Matrix *matrix2);

/// Matrix Subtraction
/// \param matrixf - Reduced
/// \param matrix2 - Subtractible
struct Matrix *div_matrix(struct Matrix *matrixf, struct Matrix *matrix2);

/// Matrix multiplication
/// \param first - First Multiplier
/// \param sec - Second Multiplier
struct Matrix *mult_matrix(struct Matrix *first, struct Matrix *sec);

/// Clean
/// \param matrix - Structure for cleaning
int clean_matrix(struct Matrix *matrix);

#endif // matrixlib_H