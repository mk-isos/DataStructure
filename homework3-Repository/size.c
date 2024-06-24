#include<stdio.h>
#include<stdlib.h>
//<stdio.h>와 <stdlib.h>을 컴파일전에 소스에 확장하도록 지시
int main()
{
    int **x; //이중포인터 변수 x선언
    
    printf("-----[Kim Moon Ki] [2021041023]-----\n");
    
    printf("sizeof(x) = %lu\n", sizeof(x));         //x의 크기 출력
    printf("sizeof(*x) = %lu\n", sizeof(*x));       //*x의 크기 출력
    printf("sizeof(**x) = %lu\n", sizeof(**x));     //**x의 크기 출력
}
/* *x와 x는 포인터이기 때문에 컴퓨터의 운영체제에 따라 결정 된다.(32bit = 4 , 64bit = 8)
**x는 int 형이므로 4가 출력된다.  */