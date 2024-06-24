#include <stdio.h>
//<stdio.h>을 컴파일 전에 소스에 확장하도록 지시

//struct구조체 student1 선언
struct student1 {
    char lastName;
    int studentId;
    char grade;
};

//struct구조체 student2 선언
typedef struct {
    char lastName;
    int studentId;
    char grade;
} student2;


int main() {
    struct student1 st1 = {'A', 100, 'A'};          //stduent1 객체 st1 선언 후 초기화
    //구조체 선언을 struct student1로 했기 때문에 위와 같이 선언함

    printf("-----[Kim Moon Ki] [2021041023]-----\n");
    
    printf("st1.lastName = %c\n", st1.lastName);    //st1의 lastName 출력
    printf("st1.studentId = %d\n", st1.studentId);  //st1의 studentId 출력
    printf("st1.grade = %c\n", st1.grade);          //st1의 grade 출력
    
    student2 st2 = {'B', 200, 'B'};                 //student2 객체 st2 선언 후 초기화
    //구조체 선언을 typedef struct로 했기 때문에 위와 같이 선언함
    
    printf("\nst2.lastName = %c\n", st2.lastName);  //st2의 lastName 출력
    printf("st2.studentId = %d\n", st2.studentId);  //st2의 studentId 출력
    printf("st2.grade = %c\n", st2.grade);          //st2의 grade 출력
    
    student2 st3;       //student2의 객체 st3 선언
    
    st3 = st2;          //st3에 st2를 초기화
    
    printf("\nst3.lastName = %c\n", st3.lastName);  //st3의 lastName 출력
    printf("st3.studentId = %d\n", st3.studentId);  //st3의 studentId 출력
    printf("st3.grade = %c\n", st3.grade);          //st3의 grade 출력

    
    // /* equality test */
    // if(st3 == st2) /* not working */
    //     printf("equal\n");
    // else
    //     printf("not equal\n");
    

    //st3와 st2를 비교
    if(st3. lastName == st2.lastName && st3.studentId == st2.studentId && st3.grade == st2.grade)
        printf("equal\n");
    else
        printf("not equal\n");
    
    //st3와 st2를 비교 2번쨰 방법
    /*
    if (strcmp(st3.lastName,st2.studentId))
    {
        printf("not equal\n");
    }
    if(st3.studentId != st2.studentId)
    {
        printf("not equal\n");
    }
    if (strcmp(st3.grade,st3.grade))
    {
        printf("not equal\n");
    }
    위와같은 방식으로 비교해야함*/
    
    return 0;
}
/* 구조체에서 st3 = st2를 통해서 st3에 st2를 복사할 수 있다. 
또, 구조체끼리 비교할때 if(st3 == st2)로는 비교 할 수 없고,
구조체내의 성분들을 하나씩 비교 해 주어야 한다.*/
