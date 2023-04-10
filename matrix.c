#include <stdio.h>
#include <stdlib.h>

// 행렬의 모든 원소를 출력하는 함수
void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);    // 한 행의 모든 원소를 출력
        }
        printf("\n");                       // 행 끝에 개행 추가
    }
}

// 행렬의 크기를 입력 받아 동적으로 메모리를 할당하는 함수
int** allocate_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));  // 행 개수만큼 int형 포인터 배열 동적 할당
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));   // 열 개수만큼 int형 동적 할당
    }
    return matrix;          // 할당한 메모리 반환
}

// 동적으로 할당된 행렬의 메모리를 해제하는 함수
void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {        // 열 개수만큼 동적으로 할당한 메모리를 해제
        free(matrix[i]);
    }
    free(matrix);                   // 행 개수만큼 동적으로 할당한 메모리를 해제
}

// 두 행렬의 합을 구하는 함수
void addition_matrix(int** a, int** b, int** result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];       // 대응되는 원소끼리 더한 결과를 결과 행렬에 저장
        }
    }
}

// 두 행렬의 차를 구하는 함수
void subtraction_matrix(int** a, int** b, int** result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];       // 대응되는 원소끼리 뺀 결과를 결과 행렬에 저장
        }
    }
}

// 주어진 행렬의 전치행렬을 구하는 함수
void transpose_matrix(int** a, int** result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = a[i][j];     // 원래 행렬의 i번째 행과 j번째 열의 원소를 전치 행렬의 j번째 행과 i번째 열에 대응되는 위치에 저장
        }
    }
}

// 두 행렬의 곱을 구하는 함수
void multiply_matrix(int** a, int** b, int** result, int a_rows, int a_cols, int b_cols) {
    for (int i = 0; i < a_rows; i++) {
        for (int j = 0; j < b_cols; j++) {
            result[i][j] = 0;               // 결과 행렬의 i번째 행 j번째 열의 값을 0으로 초기화
            for (int k = 0; k < a_cols; k++) {
                result[i][j] += a[i][k] * b[k][j];  // 행렬 곱셈의 핵심 연산 수행
            }
        }
    }
}

int main()
{
    printf("[----- [Kim Moon Ki]  [2021041023] -----]\n");
    
    int a_rows, a_cols, b_rows, b_cols;
    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &a_rows, &a_cols);           // 행렬 A의 크기 입력 받음
    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &b_rows, &b_cols);           // 행렬 B의 크기 입력 받음

    
    }

    int** a = allocate_matrix(a_rows, a_cols);      // 행렬 A 동적 메모리 할당
    int** b = allocate_matrix(b_rows, b_cols);      // 행렬 B 동적 메모리 할당
    int** result = allocate_matrix(a_rows, b_cols); // 행렬 A행 B열 동적 메모리 할당

    printf("Enter elements of matrix A:\n");        //행렬 A의 원소값 입력받기 
    for (int i = 0; i < a_rows; i++) {
        for (int j = 0; j < a_cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");        //행렬 B의 원소값 입력받기 
    for (int i = 0; i < b_rows; i++) {
        for (int j = 0; j < b_cols; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    

    printf("Matrix A:\n");
    print_matrix(a, a_rows, a_cols);        //행렬 A 출력
    printf("Matrix B:\n");
    print_matrix(b, b_rows, b_cols);        //행렬 B 출력

    // 행렬 A와 B의 크기가 같을 때만 덧셈과 뺄셈이 가능하므로 이를 검사
    if (a_rows == b_rows && a_cols == b_cols) {
        int** addition = allocate_matrix(a_rows, a_cols); // 덧셈 결과 행렬 동적 메모리 할당
        addition_matrix(a, b, addition, a_rows, a_cols); // 덧셈 수행
        printf("\nMatrix A + B:\n");
        print_matrix(addition, a_rows, a_cols); // 덧셈 결과 행렬 출력
        free_matrix(addition, a_rows); // 덧셈 결과 행렬 메모리 해제

        int** subtraction = allocate_matrix(a_rows, a_cols); // 뺄셈 결과 행렬 동적 메모리 할당
        subtraction_matrix(a, b, subtraction, a_rows, a_cols); // 뺄셈 수행
        printf("\nMatrix A - B:\n");
        print_matrix(subtraction, a_rows, a_cols); // 뺄셈 결과 행렬 출력
        free_matrix(subtraction, a_rows); // 뺄셈 결과 행렬 메모리 해제
    }
    else {
        printf("\nMatrix addition and subtraction cannot be performed because the sizes of matrices A and B are different.\n");
    }

    int** transpose_a = allocate_matrix(a_cols, a_rows);        // 전치행렬 동적 메모리 할당
    transpose_matrix(a, transpose_a, a_rows, a_cols);   // 전치행렬 수행
    printf("Transpose of A:\n");
    print_matrix(transpose_a, a_cols, a_rows);  // 전치행렬 출력
    free_matrix(transpose_a, a_cols);   // 전치행렬 메모리 해제

    // 행렬 A의 열의 크기와 행렬 B의 행의 크기가 같을 때만 곱셈이 가능하므로 이를 검사
    if (a_cols == b_rows) {
        int** product = allocate_matrix(a_rows, b_cols); // 곱셈 결과 행렬 동적 메모리 할당
        multiply_matrix(a, b, product, a_rows, a_cols, b_cols); // 곱셈 수행
        printf("\nMatrix A * B:\n");
        print_matrix(product, a_rows, b_cols); // 곱셈 결과 행렬 출력
        free_matrix(product, a_rows); // 곱셈 결과 행렬 메모리 해제
    }
    else {
        printf("\nMatrix multiplication cannot be performed because the number of columns in matrix A is not equal to the number of rows in matrix B.\n");
    }

    free_matrix(a, a_rows);                 // 행렬 A 메모리 해제
    free_matrix(b, b_rows);                 // 행렬 B 메모리 해제
    free_matrix(result, a_rows);            // result 메모리 해제

    return 0;

}
