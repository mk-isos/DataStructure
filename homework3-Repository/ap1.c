#include <stdio.h>
#include <stdlib.h> 

//<stdio.h>와 <stdlib.h>를 컴파일 전에 소스에 확장 하도록 지시함

int main()
{
    int list[5]; //일차원배열 list 선언
    int *plist[5] = {NULL,}; //포인터배열 plist 선언
    //stack영역에 할당

    plist[0] = (int *)malloc(sizeof(int)); //plist를 heap영역에 할당
    list[0] = 1;            //list[0]에 1 초기화
    list[1] = 100;          //list[1]에 100 초기화
    *plist[0] = 200;        //plist[0]가 역참조 하는 값에 200 초기화
    
    printf("-----[Kim Moon Ki] [2021041023]-----\n");
    
    printf("list[0] = %d\n", list[0]);      //list[0]의 값 출력
    printf("&list[0] = %p\n", &list[0]);    //list[0]의 주소 값 출력
    printf("list = %p\n", list);            //list의 값 출력
    printf("&list = %p\n", &list);          //list의 주소 값 출력
    
    printf("----------------------------------------\n\n");
    printf("list[1] = %d\n", list[1]);      //list[1]의 값 출력
    printf("&list[1] = %p\n", &list[1]);    //list[1]의 주소 값 출력
    printf("*(list+1) = %d\n", *(list + 1));//list+1이 역참조 하는 값 출력
    printf("list+1 = %p\n", list+1);        //list+1의 값 출력
    
    printf("----------------------------------------\n\n");
    printf("*plist[0] = %d\n", *plist[0]);  //plist[0]이 역참조 하는 값 출력
    printf("&plist[0] = %p\n", &plist[0]);  //plist[0]의 주소를 출력
    printf("&plist = %p\n", &plist);        //plist의 주소를 출력
    printf("plist = %p\n", plist);          //plist의 값 출력
    printf("plist[0] = %p\n", plist[0]);    //plist[0]의 값 출력
    printf("plist[1] = %p\n", plist[1]);    //plist[1]의 값 출력
    printf("plist[2] = %p\n", plist[2]);    //plist[2]의 값 출력
    printf("plist[3] = %p\n", plist[3]);    //plist[3]의 값 출력
    printf("plist[4] = %p\n", plist[4]);    //plist[4]의 값 출력
    
    free(plist[0]);
}   //plist 배열의 메모리 할당 해제

//주소 값은 모두 16진수로, 값은 모두 10진수로 출력

/*위의 선언 된 두 배열 list와 plist에서 배열 list는 값을 저장하고 plist는 배열을 저장한다. 
list는 배열이기에 list[0~4]는 모두 정수값을 가지고,
plist는 포인터 배열이기에 plist[0~4]는 모두 주소 값을 가진다.*/