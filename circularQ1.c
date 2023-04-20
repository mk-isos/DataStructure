// circularQ.c
//
// School of Computer Science,
// Chungbuk National University
//

#include <stdio.h>
#include <stdlib.h>
//<stdio.h>와 <stdlib.h>가 컴파일 전에 소스에 확장하도록 지시

#define MAX_QUEUE_SIZE 4
//MAX_QUEUE_SIZE를 상수로 지정 후 4 저장

// 구조체 QueueType 정의
typedef char element;
//element 구조체 선언

typedef struct
{
    element queue[MAX_QUEUE_SIZE];
    int front, rear;        //front와 rear 선언
} QueueType;
//QueueType 구조체 선언

// 큐 생성 함수
QueueType* createQueue();
// 동적 할당된 큐 메모리 해제 함수
int freeQueue(QueueType* cQ);
// 큐가 비어있는지 확인하는 함수
int isEmpty(QueueType* cQ);
// 큐가 가득 차있는지 확인하는 함수
int isFull(QueueType* cQ);
// 큐에 데이터를 추가하는 함수
void enQueue(QueueType* cQ, element item);
// 큐에서 데이터를 삭제하고 그 값을 반환하는 함수
void deQueue(QueueType* cQ, element* item);
// 큐의 모든 데이터를 출력하는 함수
void printQ(QueueType* cQ);
// 디버그용 함수
void debugQ(QueueType* cQ);
// 사용자로부터 하나의 element를 입력받아 반환하는 함수
element getElement();

// 메인 함수
int main(void)
{
    //QueueType 객체 *cQ 선언 후 큐 생성

    QueueType* cQ = createQueue(); // 큐 생성
    element data;                  // 입력받은 element 저장하는 변수
    char command;                  // 사용자 입력 명령 저장하는 변수
    
    printf("[----- [Kim Moon Ki] [2021041023] -----]");

    do
    {
        printf("\n-----------------------------------------------------\n");
        printf("                     Circular Q                   \n");
        printf("------------------------------------------------------\n");
        printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
        printf("------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);     //사용자로부터 Command를 입력받음

        switch (command)
        {
        case 'i':                //Command가 i or I 일때
        case 'I':
            data = getElement(); // 사용자로부터 element 입력받음
            enQueue(cQ, data);   // 큐에 element 추가
            break;
        case 'd':               //Command가 d or D 일때
        case 'D':
            deQueue(cQ, &data); // 큐에서 element 삭제하고 그 값을 data에 저장
            break;
        case 'p':               //Command가 p or P 일때
        case 'P':
            printQ(cQ); // 큐의 모든 데이터 출력
            break;
        case 'b':               //Command가 b or B 일때
        case 'B':
            debugQ(cQ); // 디버그용 정보 출력
            break;
        case 'q':       //Command가 q or Q 일때
        case 'Q':
            break;
        default:            //Command를 잘못 입력 했을때
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    } while (command != 'q' && command != 'Q');

    // 동적 할당된 큐 메모리 해제
    freeQueue(cQ);

    return 1;           //1 반환
}

// 큐 생성 함수
QueueType* createQueue()
{
    QueueType* cQ;
    cQ = (QueueType*)malloc(sizeof(QueueType));
    cQ->front = 0;      //front값 0으로 초기화
    cQ->rear = 0;       //rear값 0으로 초기화
    return cQ;
}

//rear와 front가 같을때 empty rear와 front가 가장 멀때 full 

// 동적 할당된 큐 메모리 해제 함수
int freeQueue(QueueType* cQ)
{
    if (cQ == NULL)     //cQ가 비어있을때 1 반환
        return 1;
    free(cQ);           //cQ가 비어있지 않을때 free
    return 1;
}

// 사용자로부터 하나의 element를 입력받아 반환
// 요소를 입력받는 함수
element getElement()
{
    element item;
    printf("Input element = ");
    scanf(" %c", &item);
    return item;
}

// 큐가 비어있는지 검사하는 함수
int isEmpty(QueueType* cQ)
{
    if (cQ->front == cQ->rear) {            //큐가 비어있을때
        printf("원형 큐가 비어있습니다!");
        return 1;
    }
    else {
        return 0;
    }
}

// 큐가 가득 차있는지 검사하는 함수
int isFull(QueueType* cQ)
{
    if (((cQ->rear + 1) % MAX_QUEUE_SIZE) == cQ->front)     //큐가 가득 찼을때
    {
        printf("원형 큐가 가득 차있습니다!");
        return 1;
    }
    else {
        return 0;
    }
}

// 큐에 요소를 추가하는 함수
void enQueue(QueueType* cQ, element item)
{
    if (isFull(cQ))     //큐가 가득 찼을때
    {
        return;
    }
    else                //큐가 가득 차있지 않을때
    {
        cQ->rear = (cQ->rear + 1) % MAX_QUEUE_SIZE;
        cQ->queue[cQ->rear] = item;
    }
}

// 큐에서 요소를 제거하는 함수
void deQueue(QueueType* cQ, element* item)
{
    if (isEmpty(cQ)) //큐가 비어있을때
    {
        return;
    }
    else //큐가 비어있지 않을때
    {   //큐 삭제
        cQ->front = (cQ->front + 1) % MAX_QUEUE_SIZE;
        *item = cQ->queue[cQ->front];   //큐가 실제로는 남아있지만 공백상태로 봄
        return;
    }
}

// 큐의 내용을 출력하는 함수
void printQ(QueueType* cQ)
{
    int i, first, last;

    first = (cQ->front + 1) % MAX_QUEUE_SIZE;       //first의 현재 인덱스 위치
    last = (cQ->rear + 1) % MAX_QUEUE_SIZE;         //last의 현재 인덱스 위치

    printf("원형 큐 : [");

    //first부터 last까지 큐 출력
    i = first;
    while (i != last) {
        printf("%3c", cQ->queue[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }

    printf(" ]\n");
}

// 큐의 내부 상태를 출력하는 디버그 함수
void debugQ(QueueType* cQ)
{   //Queue에 문제가 있는지 확인하는 함수
    printf("\n---DEBUG\n");

    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        if (i == cQ->front) {
            printf("  [%d] = front\n", i);      //front의 위치 출력
            continue;
        }

        printf("  [%d] = %c\n", i, cQ->queue[i]);
    }

    printf("front = %d, rear = %d\n", cQ->front, cQ->rear);     //front와 rear의 인덱스 위치 출력
}