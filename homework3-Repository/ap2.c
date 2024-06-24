#include <stdio.h>
#include <stdlib.h>
//<stdio.h>와 <stdlib.h>를 컴파일 전에 소스에 확장 하도록 지시
int main()
{
    int list[5];        //일차원배열 list선언
    int *plist[5];      //포인터배열 plist선언
    //stack 영역에 할당
    list[0] = 10;       //list[0]에 10을 초기화
    list[1] = 11;       //list[1]에 11을 초기화
    
    plist[0] = (int*)malloc(sizeof(int));
    //plist를 heap 영역에 할당
    
    printf("-----[Kim Moon Ki] [2021041023]-----\n");
    
    printf("list[0] \t= %d\n", list[0]);    //list[0]의 값 출력
    printf("list \t\t= %p\n", list);        //list의 값 출력
    printf("&list[0] \t= %p\n", &list[0]);  //list[0]의 주소 값 출력
    printf("list + 0 \t= %p\n", list+0);    //list+0의 값 출력
    printf("list + 1 \t= %p\n", list+1);    //list+1의 값 출력
    printf("list + 2 \t= %p\n", list+2);    //list+2의 값 출력
    printf("list + 3 \t= %p\n", list+3);    //list+3의 값 출력
    printf("list + 4 \t= %p\n", list+4);    //list+4의 값 출력
    printf("&list[4] \t= %p\n", &list[4]);  //list[4]의 주소 값 출력
    
    free(plist[0]);
    //plist 배열의 메모리 할당 해제
}
//주소 값은 모두 16진수로, 값은 모두 10진수로 출력

/*배열에서 list자체는 list배열의 주소 값을 저장한다.
고로, list == &list == &list[0]이다.*/