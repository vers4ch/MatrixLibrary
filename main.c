#include <stdio.h>
#include "matrixlib.h"

int main() {
    struct Matrix *Mat;
    struct Matrix *Trans;
    struct Matrix *Mat2;
    struct Matrix *Sum;
    struct Matrix *Div;
    struct Matrix *Mult;

    Mat = create_matrix(8, 10);
    rand_matrix(10, 40, Mat);
    printf("\nRandomMatrix:\n");
    print_matrix(Mat);

    printf("\nTrans.:\n");
    Trans = trans(Mat);
    print_matrix(Trans);

    printf("\nCopy:\n");
    Mat2 = cpy_matrix(Mat);
    print_matrix(Mat2);

    printf("\nSum:\n");
    Sum = summ_matrix(Mat, Mat2);
    print_matrix(Sum);
    clean_matrix(Sum);///Очистка озу

    printf("\nDiv:\n");
    Div = div_matrix(Mat, Mat2);
    print_matrix(Div);
    clean_matrix(Mat2);///Очистка озу
    clean_matrix(Div);///Очистка озу

    printf("\nMultiplication:\n");
    Mult = mult_matrix(Mat, Trans);
    print_matrix(Mult);

    clean_matrix(Mat);///Очистка озу
    clean_matrix(Trans);///Очистка озу
    clean_matrix(Mult);///Очистка озу

    return 0;
}