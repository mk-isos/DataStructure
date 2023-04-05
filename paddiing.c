#include <stdio.h>
//<stdio.h>을 컴파일 전에 소스에 확장 하도록 지시

//구조체 student 선언
struct student {
char lastName[13]; /* 13 bytes */
//문자형 배열 lastName 선언
int studentId; /* 4 bytes */
//정수형 변수 studentId 선언
short grade; /* 2 bytes */
//short형 변수 grade 선언
};
int main()
{
    struct student pst;     //구조체 객체 pst선언
    
    printf("-----[Kim Moon Ki] [2021041023]-----\n");ㅊ
    
    printf("size of student = %ld\n", sizeof(struct student));  //student의 크기 출력
    printf("size of int = %ld\n", sizeof(int));                 //int형의 크기 출력
    printf("size of short = %ld\n", sizeof(short));             //short형의 크기 출력
    
    return 0;   //0 반환
}

/*위에서 struct student의 크기를 반환할때 
메모리의 빈공간을 채우지 않고 padding하므로 
19가 아닌 24가 출력된다.*/