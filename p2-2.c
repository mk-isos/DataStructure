#include <stdio.h>
//<stdio.h>를 컴파일 전에 소스파일에 확장 하도록 지시
void print_one(int *ptr, int rows);
//void형 print1함수 원형
int main()
{
    printf("-----[Kim Moon Ki] [2021041023]-----\n");
    
    int one[] = {0, 1, 2, 3, 4};        //정수형 배열 one선언
    printf("one = %p\n", one);          //one의 값 출력
    printf("&one = %p\n", &one);        //one의 주소 값 출력
    printf("&one[0] = %p\n", &one[0]);  //one[0]의 주소 값 출력
    printf("\n");
    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");//print_one(&one[0], 5) 출력
    printf("------------------------------------\n");
    print_one(&one[0], 5);              //print_one함수 실행
    //one[0]은 call by reference 5는 call by value
    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");    
    printf("------------------------------------\n");
    print_one(one, 5);                  //print_one함수 실행
    
    return 0;
}

/*call by reference를 통해 받은 one[0]의 주소 값을 포인터를 이용해 접근하고,
rows는 call by value를 통해 값을 받음*/

void print_one(int *ptr, int rows)
{/* print out a one-dimensional array using a pointer */
    int i;              //정수형 변수 i 선언
    printf ("Address \t Contents\n");
    for (i = 0; i < rows; i++)
    printf("%p \t %5d\n", ptr + i, *(ptr + i));     //포인터변수 ptr을 통해서 one배열의 값과 주소를 순차적으로 출력
    printf("\n");
}

/*call by reference 를 통해 받은 배열의 주소를 포인터 변수를 통해 접근했다.*/