//
// Created by Данил on 17.12.2022.
//
#include "matrixlib.h"
struct Matrix {
    int strok;
    int stolbov;
    int strok1;   // copy variable
    int stolbov1; // copy variable
    int **array;
};
/// generate matrix with entered str&stlb
struct Matrix *create_matrix(int str, int stlb) {
    struct Matrix *matrix = (struct Matrix *)malloc(sizeof(struct Matrix));
    matrix->strok = str;
    matrix->stolbov = stlb;
    matrix->strok1 = str;    // copy variable
    matrix->stolbov1 = stlb; // copy variable
    //Наверное надо сделать проверку
    matrix->array = (int **)malloc(str * sizeof(int *));
    for (int i = 0; i < str; i++) {
        matrix->array[i] = (int *)malloc(stlb * sizeof(int));
    }
    return matrix;
}
/// filling the matrix with random numbers
struct Matrix *rand_matrix(int min, int max, struct Matrix *matrix) {
    srand(time(NULL));
    for (int i = 0; i < matrix->strok; i++) {
        for (int j = 0; j < matrix->stolbov; j++) {
            matrix->array[i][j] = rand() % (max - min + 1) + min;
        }
    }
    return matrix;
}
/// printing
struct Matrix *print_matrix(struct Matrix *matrixPrint) {
    for (int i = 0; i < matrixPrint->strok; i++) {
        for (int j = 0; j < matrixPrint->stolbov; j++) {
            printf("%d ", matrixPrint->array[i][j]);
        }
        printf("\n");
    }
    return matrixPrint;
}
/// coping array/matrix
struct Matrix *cpy_matrix(struct Matrix *matrix) {
    struct Matrix *cpy_matrix = create_matrix(matrix->strok, matrix->stolbov);
    cpy_matrix->strok = matrix->strok;
    cpy_matrix->stolbov = matrix->stolbov;
    for (int i = 0; i < matrix->strok; i++) {
        for (int j = 0; j < matrix->stolbov; j++) {
            cpy_matrix->array[i][j] = matrix->array[i][j];
        }
    }
    return cpy_matrix;
}
/// Trans
struct Matrix *trans(struct Matrix *matrix) {
    struct Matrix *matrix1 = (struct Matrix *)malloc(sizeof(struct Matrix));
    matrix1->strok = matrix->stolbov;
    matrix1->stolbov = matrix->strok;
    matrix1->array = (int**)malloc(matrix1->strok * sizeof(int *));
    for (int i = 0; i < matrix1->strok; i++) {
        matrix1->array[i] = (int *)malloc(matrix1->stolbov * sizeof(int));
    }
    for (int i = 0; i < matrix1->strok; i++) {
        for (int j = 0; j < matrix1->stolbov; j++) {
            matrix1->array[i][j] = matrix->array[j][i];
        }
    }
    return matrix1;
}
/// Summing
struct Matrix *summ_matrix(struct Matrix *matrixf, struct Matrix *matrix2) {
    //Проверка на порядок матрицы
    if (matrixf->strok != matrix2->strok &&
        matrixf->stolbov != matrix2->stolbov) {
        printf("Matrix order error!!!!!\n");
        return NULL;
    }
    //Выделяем память
    struct Matrix *summ_matrix = create_matrix(matrixf->strok, matrixf->stolbov);
    summ_matrix->strok = matrixf->strok1;
    summ_matrix->stolbov = matrixf->stolbov1;
    //Суммируем массивы
    for (int i = 0; i < matrixf->strok; i++) {
        for (int j = 0; j < matrixf->stolbov; j++) {
            summ_matrix->array[i][j] = matrixf->array[i][j] + matrix2->array[i][j];
        }
    }
    return summ_matrix;
}
/// Division
struct Matrix *div_matrix(struct Matrix *matrixf, struct Matrix *matrix2) {
    //Проверка на порядок матрицы
    if (matrixf->strok != matrix2->strok &&
        matrixf->stolbov != matrix2->stolbov) {
        printf("Matrix order error!!!!!\n");
        return NULL;
    }
    //Выделяем память
    struct Matrix *div_matrix = create_matrix(matrixf->strok, matrixf->stolbov);
    div_matrix->strok = matrixf->strok1;
    div_matrix->stolbov = matrixf->stolbov1;
    //Вычитаем массивы
    for (int i = 0; i < matrixf->strok; i++) {
        for (int j = 0; j < matrixf->stolbov; j++) {
            div_matrix->array[i][j] = matrixf->array[i][j] - matrix2->array[i][j];
        }
    }
    return div_matrix;
}
/// Multiplication
struct Matrix *mult_matrix(struct Matrix *first, struct Matrix *sec){
    if (first->stolbov == sec->strok && first->strok == sec->stolbov) {
        struct Matrix *mlt_matrix = create_matrix(first->strok, sec->stolbov);
        for (int i = 0; i < first->strok; i++) {
            for (int j = 0; j < sec->stolbov; j++) {
                mlt_matrix->array[i][j] = 0;
                for (int b = 0; b < first->stolbov; b++) {
                    mlt_matrix->array[i][j] += first->array[i][b] * sec->array[b][j];
                }
            }
        }
        return mlt_matrix;
    }
    else {
        printf("Error in matrix order\n");
        return NULL;
    }
    return 0;
}
///Cleaning
int clean_matrix(struct Matrix *matrix) {
    for (int i = 0; i < matrix->strok; i++) {
        free(matrix->array[i]);
    }
    free(matrix->array);
    free(matrix);
    printf("\nRAM has been cleared, trash removed\n");
    return 0;
}
