#include <stdio.h>
//<stdio.h>를 컴파일 전에 소스에 확장하도록 지시

//이중 포인터 변수와 포인터 변수로 역참조 하는 프로그램의 메인함수
int main()
{
    int i;      //int형 변수 i 선언
    int *ptr;   //int형 포인터 변수 ptr 선언
    int **dptr; //int형 이중 포인터 변수 dptr선언

    printf("----[김문기] [2021041023]----\n\n");

    i = 1234;   //변수 i에 값 1234 초기화
    printf("[checking values before ptr = &i] \n");     //ptr = &i 전의 값 출력
    printf("value of i == %d\n", i);                    //i의 값 출력
    printf("address of i == %p\n", &i);                 //i의 주소 값 출력
    printf("value of ptr == %p\n", ptr);                //ptr의 값 출력
    printf("address of ptr == %p\n", &ptr);             //ptr의 주소 값 출력

    ptr = &i; //변수 ptr에 i의 주소값을 초기화
    printf("\n[checking values after ptr = &i] \n");    //ptr = &i 후의 값 출력
     printf("value of i == %d\n", i);                   //i의 값 출력
    printf("address of i == %p\n", &i);                 //i의 주소 값 출력
    printf("value of ptr == %p\n", ptr);                //ptr의 값 출력
    printf("address of ptr == %p\n", &ptr);             //ptr의 주소 값 출력
    printf("value of *ptr == %d\n", *ptr);              //ptr이 역참조 하는 값 출력

    dptr = &ptr; //변수 dptr에 ptr의 주소값을 초기화
    printf("\n[checking values after dptr = &ptr] \n"); //dptr = &ptr 후의 값 출력
    printf("value of i == %d\n", i);                    //i의 값 출력
    printf("address of i == %p\n", &i);                 //i의 주소 값 출력
    printf("value of ptr == %p\n", ptr);                //ptr의 값 출력
    printf("address of ptr == %p\n", &ptr);             //ptr의 주소 값 출력
    printf("value of *ptr == %d\n", *ptr);              //ptr이 역참조 값 출력
    printf("value of dptr == %p\n", dptr);              //dptr의 값 출력
    printf("address of dptr == %p\n", &dptr);           //dptr의 주소 값 출력
    printf("value of *dptr == %p\n", *dptr);            //dptr이 역참조 하는 값 출력
    printf("value of **dptr == %d\n", **dptr);          //*dptr이 역참조 하는 값 출력

    *ptr = 7777; //*ptr의 값을 7777로 교체
    printf("\n[after *ptr = 7777] \n");                 //*ptr = 7777 후의 값 출력
    printf("value of i == %d\n", i);                    //i의 값 출력
    printf("value of *ptr == %d\n", *ptr);              //ptr이 역참조 하는 값 출력
    printf("value of **dptr == %d\n", **dptr);          //*dptr이 역참조 하는 값 출력

    **dptr = 8888; //*dptr의 값을 8888로 교체
    printf("\n[after **dptr = 8888] \n");               //**dptr = 8888 후의 값 출력
    printf("value of i == %d\n", i);                    //i의 값 출력
    printf("value of *ptr == %d\n", *ptr);              //ptr이 역참조 하는 값 출력
    printf("value of **dptr == %d\n", **dptr);          //*dptr이 역참조 하는 값 출력

    //주소 값은 전부 16진수 출력, 값은 10진수로 출력

    return 0;   //0 반환
}
