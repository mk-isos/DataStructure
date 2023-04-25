/*
 * singly linked list
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 */


#include<stdio.h>
#include<stdlib.h>
//<stdio.h>,<stdlib.h>를 컴파일 전에 소스에 확장하도록 지시

/* 필요한 헤더파일 추가 */

//Node구조체 listNode 선언
typedef struct Node {
	int key;	//값을 저장할 변수 key 선언
	struct Node* link;	//다음 값을 가리킬 포인터 변수 link 선언
} listNode;

//Head구조체 headNode 선언
typedef struct Head {
	struct Node* first;	//첫번째 값을 가르킬 Node 포인터 변수 first 선언
}headNode;


/* 함수 리스트 */
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

//이 프로그램의 메인함수
int main()
{
	char command;	//사용자로부터 명령을 입력받을 command 선언
	int key;		//사용자로부터 값을 입력받을 key 선언	
	headNode* headnode=NULL;	//headNode 포인터 변수 headNode를 선언하고 0으로 초기화
	int count = 0; 	//연결리스트를 생성하기 전에 다른 명령을 실행하지 못하도록 막는 변수 count 선언

	printf("[----- [Kim Moon K] [2021041023] -----]\n");
	// q or Q가 입력되기전까지 실행하는 무한 루프문
	do{
		//메뉴 출력
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	//command값을 사용자로부터 입력 받음

		switch(command) {	//command의 값에 따라 실행하는 switch문
		case 'z': case 'Z':	//command가 z or Z 일때
			if(count == 0)
			{
				headnode = initialize(headnode);
				count++;
				break;
			}
		case 'p': case 'P':	//command가 p or P 일때
			if(count == 0)
			{
				printf("Linked List Initialize first.\n");
				break;
			}
			else
			{
				printList(headnode);
				break;
			}
		case 'i': case 'I':	//command가 i or I 일때
			if(count == 0)
			{
				printf("Linked List Initialize first.\n");
				break;
			}
			else
			{
				printf("Your Key = ");
				scanf("%d", &key);
				insertNode(headnode, key);
				break;
			}
		case 'd': case 'D':	//command가 d or D 일때
			if(count == 0)
			{
				printf("Linked List Initialize first.\n");
				break;
			}
			else
			{
				printf("Your Key = ");
				scanf("%d", &key);
				deleteNode(headnode, key);
				break;
			}
		case 'n': case 'N':	//command가 n or N 일때
			if(count == 0)
			{
				printf("Linked List Initialize first.\n");
				break;
			}
			else
			{
				printf("Your Key = ");
				scanf("%d", &key);
				insertLast(headnode, key);
				break;
			}
		case 'e': case 'E':	//command가 e or E 일떄
			if(count == 0)
			{
				printf("Linked List Initialize first.\n");
				break;
			}
			else
			{
				deleteLast(headnode);
				break;
			}
		case 'f': case 'F':	//command가 f or F 일때
			if(count == 0)
			{
				printf("Linked List Initialize first.\n");
				break;
			}
			{
				printf("Your Key = ");
				scanf("%d", &key);
				insertFirst(headnode, key);
				break;
			}
		case 't': case 'T':	//command가 t or T 일때
			if(count == 0)
			{
				printf("Linked List Initialize first.\n");
				break;
			}
			else
			{
				deleteFirst(headnode);
				break;
			}
		case 'r': case 'R':	//command가 r or R 일때
			if(count == 0)
			{
				printf("Linked List Initialize first.\n");
				break;
			}
			else
			{
				invertList(headnode);
				break;
			}
		case 'q': case 'Q':	//command가 q or Q 일때
			freeList(headnode);
			break;

		default:			//command가 잘못 입력 되었을때
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;	//1 반환
}

//연결리스트를 생성 하는 함수
headNode* initialize(headNode* h) {

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(h != NULL)
		freeList(h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	headNode* temp = (headNode*)malloc(sizeof(headNode));	
	//headNode 포인터 변수 temp 선언 후 동적할당

	temp->first = NULL;	//first값을 NULL로 초기화
	return temp;	//temp 반환
}

//연결리스트를 free해주는 함수
int freeList(headNode* h){
	/* h와 연결된 listNode 메모리 해제
	 * headNode도 해제되어야 함.
	 */
	listNode* p = h->first;	
	//listNode 포인터 변수 p 선언 후 first값 저장

	listNode* prev = NULL;
	//listNode 포인터 변수 prec 선언
	while(p != NULL) {
		//p가 NULL이 될때까지 이동하며 
		prev = p;		//prev에 p의 값 저장
		p = p->link;	//p는 다음 연결리스트로 이동
		free(prev);		//prev값 free
	}
	free(h);	//마지막으로 헤드 노드 free
	return 0;	//0 반환
}


/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));	
	//listNode 포인터 변수 node 선언 후 동적할당
	node->key = key;	//node의 key에 사용자로부터 입력받은 key 저장
	node->link = NULL;	//node의 link에 NUll 저장

	if (h->first == NULL)
	{//연결리스트가 비어있을때
		h->first = node;	//first에 node를 저장
		return 0;	//0 반환
	}

	listNode* n = h->first;	
	listNode* trail = h->first;
	//listNode 포인터 변수 n, trail 선언 후 first값 저장

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL)	//n이 NULL이 될때까지(연결리스트 처음부터 끝까지)
	{	
		if(n->key >= key) 
		{	//만약 n의 key값이 node의 key값 보다 크거나 같을 경우
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->first) //n이 first의 값과 같을때
			{	
				h->first = node; 	//first에 node저장
				node->link = n;		//node를 n에 연결
			} 

			else 	//n이 first가 아닐때
			{ /* 중간이거나 마지막인 경우 */
				node->link = n;	//node의 link를 n으로 
				trail->link = node;	//n의 직전 노드인 trail을 node에 연결
			}

			return 0;	//0 반환
		}

		//n의 key값이 node의 key값 보다 작을 경우
		trail = n;		//trail에 n을 저장하고
		n = n->link;	//n을 다음 연결리스트로 이동
	}

	/* 마지막 노드까지 찾지 못한 경우 , 마지막에 삽입 */
	trail->link = node;	//trail을 node에 연결
	return 0;	//0 반환
}

//연결리스트의 마지막에 노드를 추가하는 함수
int insertLast(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
	//listNode 구조체변수 node를 선언 후 동적할당
	node->key = key;	//node의 key에 사용자로부터 입력받은 key값 저장
	node->link = NULL;	//node의 link값에 NULL 저장

	if (h->first == NULL)	//연결리스트가 비어있을떄 
	{
		h->first = node;	//first값에 node저장
		return 0;	//0 반환
	}

	listNode* n = h->first;	
	//listNode 포인터 변수 n 선언 후 first값을 저장
	while(n->link != NULL) {	//n의 link가 NULL일때까지
		n = n->link;	//n을 다음 연결리스트로 이동
	}

	//n의 link가 NULL일때
	n->link = node;	//n을 node에 연결
	return 0;	//0 반환
}

//연결리스트의 처음에 노드를 추가하는 함수
int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));	
	//listNode 포인터변수 node를 선언 후 동적할당
	node->key = key;	//node의 key에 사용자로부터 입력받은 key의 값 저장

	node->link = h->first;	//node를 first에 연결
	h->first = node;	//first에 node 저장

	return 0;	//0 반환
}

//사용자가 입력한 key를 삭제하는 함수
int deleteNode(headNode* h, int key) {

	if (h->first == NULL)	//연결리스트가 비어있을때
	{
		printf("nothing to delete.\n");	//오류메시지 출력
		return 0;	//0 반환	
	}

	listNode* n = h->first;
	//listNode 포인터 변수 n 선언 후 first값 저장
	listNode* trail = NULL;
	//listNode 포인터 변수 trail 선언

	/* key를 기준으로 삽입할 위치를 찾는다 */
	while(n != NULL) {	//n이 NULL이 될때까지
		if(n->key == key) {
			/* 첫 노드 앞쪽에 삽입해야할 경우 인지 검사 */
			if(n == h->first) {	//n이 first와 같다면
				h->first = n->link;	//n을 first에 저장
			} 
			
			/* 중간인 경우거나 마지막인 경우 */
			else { //n이 first가 아닐떄
				trail->link = n->link;	//trail에 n을 연결
			}
			free(n);	//n 메모리 해제
			return 0;	//0 반환
		}

		trail = n;	//trail에 n저장
		n = n->link;	//n을 다음 연결리스트로 이동
	}

	/* 찾지 못 한경우 */
	printf("cannot find the node for key = %d\n", key);	//오류메세지 출력
	return 0;	//0 반환

}

//연결리스트의 마지막 노드를 삭제하는 함수
int deleteLast(headNode* h) {

	if (h->first == NULL)	//연결리스트가 비어있을떄
	{
		printf("nothing to delete.\n");	//오류메세지 출력
		return 0;	//0 반환
	}

	listNode* n = h->first;
	//listNode 포인터 변수 n 선언 후 first값 저장
	listNode* trail = NULL;
	//listNode 포인터 변수 trail 선언

	/* 노드가 하나만 있는 경우, 즉 first node == last node인  경우 처리 */
	if(n->link == NULL) {	//n이 마지막 노드일때
		h->first = NULL;	//first에 NULL값 저장
		free(n);	//n 메모리 해제
		return 0;	//0 반환
	}

	/* 마지막 노드까지 이동 */
	while(n->link != NULL) {	//n이 마지막노드일떄까지
		trail = n;	//trail에 n을 저장
		n = n->link;	//n을 다음 연결리스트로 이동
	}

	/* n이 삭제되므로, 이전 노드의 링크 NULL 처리 */
	trail->link = NULL;	//trail을 마지막 노드로 저장
	free(n);	//n 메모리 해제

	return 0;	//0 반환
}

//연결리스트의 처음값 삭제하는 함수
int deleteFirst(headNode* h) {

	if (h->first == NULL)	//연결리스트가 비어있을떄
	{
		printf("nothing to delete.\n");	//오류 메세지 출력
		return 0;	//0 반환
	}
	listNode* n = h->first;
	//listNode 포인텨변수 n선언 후 first값 저장

	h->first = n->link;	//first에  n의 다음값 저장
	free(n);	//n 메모리 해제

	return 0;	//0 반환
}


//연결리스트를 역순으로 바꾸는 함수
int invertList(headNode* h) {

	if(h->first == NULL) {	//연결리스트가 비어있을때
		printf("nothing to invert...\n");	//오류 메세지 출력
		return 0;	//0 반환
	}
	listNode *n = h->first;
	//listNode 포인터 변수 n 선언 후 first 저장
	listNode *trail = NULL;
	//listNode 포인터 변수 trail 선언
	listNode *middle = NULL;
	//listNode 포인터 변수 middle 선언

	while(n != NULL){	//n이 NULL이 될때까지
		trail = middle;	//trail에 middle 값 저장
		middle = n;		//middle에 n 값 저장
		n = n->link;	//n을 다음 값으로 이동
		middle->link = trail;	//middle의을 trail의 연결
	}	//한 노드씩 역순으로 돌며 middle을 trail에 연결

	//n이 NULL이고, middle이 마지막 노드일때
	h->first = middle;	//first에 middle 저장

	return 0;//0 반환
}

//연결리스트를 출력하는 함수
void printList(headNode* h) {
	int i = 0;	
	listNode* p;
	//listNode 포인터 변수 p 선언

	printf("\n---PRINT\n");

	if(h == NULL) {	//연결리스트가 비어있을때
		printf("Nothing to print....\n");	//오류 메세지 출력
		return;	
	}

	p = h->first;	//p에 first값 저장

	while(p != NULL) {	//p가 NULL이될때까지
		printf("[ [%d]=%d ] ", i, p->key);	//인덱스 번호와 p의 key값 출력
		p = p->link;	//p를 다음 연결리스트로 이동
		i++;	//i 값 증가
	}

	//마지막에 i++를 연산하고 while 문을 나오므로 i에는 총 노드 개수 저장됨
	printf("  items = %d\n", i);	//총 노드의 개수 출력
}

