#include <stdio.h>

#define SIZE 3

void printMatrix(int matrix[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int A[SIZE][SIZE],int B[SIZE][SIZE],int result[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            result[i][j]=A[i][j]+B[i][j];
        }
    }
}

void multiplyMatrix(int A[SIZE][SIZE],int B[SIZE][SIZE],int result[SIZE][SIZE]){

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){

            result[i][j]=0;

            for(int k=0;k<SIZE;k++){
                result[i][j]+=A[i][k]*B[k][j];
            }

        }
    }
}

void transposeMatrix(int matrix[SIZE][SIZE],int result[SIZE][SIZE]){

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            result[j][i]=matrix[i][j];
        }
    }

}

int main(){

    int A[SIZE][SIZE]={{1,2,3},{4,5,6},{7,8,9}};
    int B[SIZE][SIZE]={{9,8,7},{6,5,4},{3,2,1}};

    int sum[SIZE][SIZE];
    int product[SIZE][SIZE];
    int transpose[SIZE][SIZE];

    addMatrix(A,B,sum);
    multiplyMatrix(A,B,product);
    transposeMatrix(A,transpose);

    printf("Matrix A\n");
    printMatrix(A);

    printf("\nMatrix B\n");
    printMatrix(B);

    printf("\nAddition\n");
    printMatrix(sum);

    printf("\nMultiplication\n");
    printMatrix(product);

    printf("\nTranspose of A\n");
    printMatrix(transpose);

    return 0;
}
