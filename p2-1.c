#include <stdio.h>
//<stdio.h>를 컴파일전에 소스에 확장 하도록 지시
#define MAX_SIZE 100
//MAX_SIZE를 값이 100인 상수로 지정
float sum1(float list[], int);      //sum 함수 원형
float sum2(float *list, int);       //sum 함수 원형
float sum3(int n, float *list);     //sum 함수 원형

float input[MAX_SIZE], answer;      //실수형 배열 input과 실수형 변수 answer 선언
int i;                              //정수형 변수 i 선언

int main(void)
{
    printf("-----[Kim Moon Ki] [2021041023]-----\n");
    
    for(i=0; i < MAX_SIZE; i++) //100번 반복하는 반복문
        input[i] = i;           //input배열의 값을 i로 초기화
    
    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");    //sum1(input, MAX_SIZE 출력  
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);        //input의 값 출력
    
    answer = sum1(input, MAX_SIZE);
    printf("The sum is: %f\n\n", answer);   //anwser의 값 출력
    
    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");    //sum2(input, MAX_SIZE 출력
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);        //input의 값 출력
    
    answer = sum2(input, MAX_SIZE);
    printf("The sum is: %f\n\n", answer);   //anwser의 값 출력
    
    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");    //sum3(MAX_SIZE, input 출력
    printf("--------------------------------------\n");
    printf("input \t= %p\n", input);        //input의 값 출력
    
    answer = sum3(MAX_SIZE, input);         
    printf("The sum is: %f\n\n", answer);   //anwser의 값 출력
}

//list의 주소와 정수 n을 매개변수로 하는 함수 sum
float sum1(float list[], int n) 
{
    printf("list \t= %p \n", list);         //list의 값 출력
    printf("&list \t= %p\n\n", &list);      //list의 주소 값 출력
    
    int i ;                     //정수형 변수 i선언
    float tempsum = 0;          //실수형 변수 tempsum을 선언 후 0 초기화
    
    for(i = 0;i < n;i++)
    tempsum += list[i];         //tempsum에 list[0~n]까지의 합을 저장
    return tempsum;             //tempsum 반환
}

float sum2(float *list, int n) 
{
    printf("list\t= %p\n", list);         //list의 값 출력
    printf("&list\t= %p\n\n", &list);     //list의 주소 값 출력
    
    int i;                          //정수형 변수 i선언
    float tempsum = 0;              //실수형 변수 tempsum을 선언 후 0 초기화
    
    for(i = 0;i < n;i++)
    tempsum += *(list +i);      //tempsum에 *(list+0~n)까지의 합을 저장
    return tempsum;             //tempsum 반환
}

/* stack variable reuse test */
float sum3(int n, float *list) 
{
    printf("list\t= %p\n", list);       //list의 값 출력
    printf("&list\t= %p\n\n", &list);   //list의 주소 값 출력
    
    int i;                  //정수형 변수 i선언
    float tempsum = 0;      //실수형 변수 tempsum을 선언 후 0 초기화
    
    for(i = 0;i < n;i++)
    tempsum += *(list +i);  //tempsum에 *(list+0~n)까지의 합을 저장
    return tempsum;         //tempsum 반환
}