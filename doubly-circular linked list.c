/*
 *  doubly circular linked list
 *
 *  Data Structures
 *
 *  Department of Computer Science
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>
//<stdio.h>와 <stdlib.h>를 컴파일 전에 소스에 확장하도록 지시
/* 필요한 헤더파일 추가 */

//listNode 구조체 선언
typedef struct Node {
	int key;	//해당 node의 key값
	struct Node* llink;	//해당 node의 llink
	struct Node* rlink;	//해당 node의 rlink
} listNode;

/* 함수 리스트 */
int initialize(listNode** h);
int freeList(listNode* h);
int insertLast(listNode* h, int key);
int deleteLast(listNode* h);
int insertFirst(listNode* h, int key);
int deleteFirst(listNode* h);
int invertList(listNode* h);

int insertNode(listNode* h, int key);
int deleteNode(listNode* h, int key);

void printList(listNode* h);

//Circular Double 연결리스트의 메인함수
int main()
{
	char command;	//사용자로부터 입력받을 command를 저장할 변수
	int key;	//사용자로부터 입력받을 key값을 저장할 변수
	int count = 0;	//Initialize가 선행되도록 하는 변수
	listNode* headnode=NULL;
	//listNode 포인터변수 headnode선언

	printf("------[Kim Moon Ki] [2021041023]------\n");

	do{//command가 q or Q가 입력될때까지 반복하는 do-while문
		//메뉴 출력
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	//사용자로부터 command를 입력받음

		switch(command) {	//command의 값에따라 실행하는 switch문
		case 'z': case 'Z':	//command가 z or Z 일때
			initialize(&headnode);
			count++;	//count값 증가 (이제 다른 메뉴 실행가능)
			break;
		case 'p': case 'P':	//command가 p or P 일때
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}

			printList(headnode);
			break;
		case 'i': case 'I':	//command가 i or I 일때
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':	//command가 d or D 일때
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':	//command가 n or N 일때
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':	//command가 e or E 일때
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			deleteLast(headnode);
			break;
		case 'f': case 'F':	//command가 f or F 일때
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':	//command가 t or T 일때
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			deleteFirst(headnode);
			break;
		case 'r': case 'R':	//command가 r or R 일때
			if(count == 0)
			{
				printf("Please enter the z or Z first.\n");
				break;
			}
			invertList(headnode);
			break;
		case 'q': case 'Q':	//command가 q or Q 일때
			freeList(headnode);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 0;	//0 반환
}

//연결리스트를 생성하는 함수
int initialize(listNode** h) 
{

	/* headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제 */
	if(*h != NULL)	
		freeList(*h);

	/* headNode에 대한 메모리를 할당하여 리턴 */
	*h = (listNode*)malloc(sizeof(listNode));
	//h를 동적할당
	(*h)->rlink = *h;
	(*h)->llink = *h;
	//h의 rlink와 llink가 모두 자신을 가리키게 설정
	(*h)->key = -9999;
	//h의 key값에 -9999 저장
	return 0;	//0 반환
}

/* 메모리 해제 */
//연결리스트의 메모리를 해제시키는 함수
int freeList(listNode* h)
{
	listNode *p = h->rlink;
	//listNode 포인터 변수 p 선언후 h의 rlink 저장
	listNode *prev = NULL;
	//listNode 포인터 변수 prev 선언

	while(p!=NULL&&p!=h)	//p가 NULL이 아니고, h가 아닐때 반복하는 while문
	{
		prev = p;
		p = p->rlink;	//p를 rlink방향으로 이동시키며 
		free(prev);		//하나씩 free
	}
	free(h);	//마지막으로 h도 free

	return 0;	//0 반환
}

//연결리스트를 출력하는 함수
void printList(listNode* h) 
{
	int i = 0;	
	listNode* p = NULL;
	//listNode 포인터 변수 p 선언

	printf("\n---PRINT\n");

	if(h == NULL)
	{	//연결리스트가 비어있을때
		printf("Nothing to print....\n");	//오류 메세지 출력
		return;
	}

	p = h->rlink;	//p에 h의 rlink를 저장

	while(p != NULL && p != h) {	//p가 NULL이 아니고, h가 아닐때 까지 반복하는 while문
		printf("[ [%d]=%d ] ", i, p->key);	//index와 해당 노드의 key값 출력
		p = p->rlink;	//p를 rlink로 이동
		i++;	//i값 증가
	}
	printf("  items = %d\n", i);	//총 원소의 갯수 출력


	/* print addresses */
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink);
	//headnode의 llink,rlink 값과 주소값 출력

	i = 0;
	p = h->rlink;
	while(p != NULL && p != h) {	//p가 NULL이 아니고, h가 아닐때 까지 반복하는 while문
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink);
		//해당 node의 llink,rlink 값과 주소값 출력
		p = p->rlink;	//rlink로 p를 이동
		i++;	//i값 증가
	}

}



//연결리스트의 마지막에 노드를 추가하는 함수
int insertLast(listNode* h, int key) 
{
	listNode *node = (listNode*)malloc(sizeof(listNode));
	//listNode 포인터변수 node선언 후 동적할당
	node->key = key;	//node의 key값에 사용자로부터 입력받은 key값 저장
	node->rlink = NULL;
	node->llink = NULL;
	//node의 rlink와 llink모두 NULL로 초기화

	if(h->rlink==h)	//연결리스트가 비어있을때
	{
		h->rlink = node;	//h의 rlink에 node를 연결
		h->llink = node;	//h의 llink에 node를 연결
		node->rlink = h;	//node의 rlink에 h를 연결
		node->llink = h;	//node의 llink에 h를 연결
		return 0;	//0 반환
	}

	listNode *n = h->llink;
	//listNode 포인터 변수 n을 선언 후 h->llink 저장

	n->rlink = node;	//n의 rlink에 node를 연결
	h->llink = node;	//h의 llink에 node를 연결
	node->rlink = h;	//node의 rlink에 h 연결
	node->llink = n;	//node의 llink에 n 연결
	return 0;	//0 반환
}


//연결리스트 마지막에서 노드를 삭제하는 함수
int deleteLast(listNode* h) 
{
	if(h->rlink == h) {	//연결리스트가 비어있을때
		printf("Nothing to delete....\n");	//오류 메세지 출력
		return 1;	//1 반환
	}
	
	listNode* n = h;
	listNode* trail = NULL;
	//listNode 포인터 변수 n,trail 선언 후 초기화

	if(n->rlink->rlink == n)//연결리스트에 값이 한개일때
	{
		trail = n->rlink;	//trail에 n의 rlink 저장
		free(trail);	//trail free
		n->rlink = n;	//n의 rlink에 n연결
		n->llink = n;	//n의 llink에 n연결
		
		return 0;	//0 반환
	}

	n = n->llink;	//n에 n의 llink 저장
	trail = n->llink;	//trail에 n의 llink 저장
	trail->rlink = h;	//trail의 rlink에 h 저장
	h->llink = trail;	//h의 llink에 trail 저장
	free(n);	//n free

	return 0;	//0 반환
}


//연결리스트에 처음에 노드를 추가하는 함수
int insertFirst(listNode* h, int key) 
{
	listNode *node = (listNode*)malloc(sizeof(listNode));
	//listNode 포인터 변수 node 선언후 동적 할당
	node->key = key;	//node의 key에 사용자로부터 입력받은 key값 저장
	node->rlink = NULL;
	node->llink = NULL;
	//node의 rlink와 llink 초기화

	if(h->rlink==h)	//연결리스트가 비어있으면
	{
		h->rlink = node;
		h->llink = node;
		node->rlink = h;
		node->llink = h;
		return 0;
	}

	listNode *n = h;
	//listNode 포인터변수 n 선언 후 h 저장

	n = n->rlink;

	n->llink = node;
	h->rlink = node;
	node->rlink = n;
	node->llink = h;
	return 0; // 0 반환
}

//연결리스트의 처음에서 노드를 삭제하는 함수
int deleteFirst(listNode* h) 
{
	if(h->rlink == h) {	//연결리스트가 비어있을때
		printf("Nothing to delete....\n");	//오류 메세지 출력
		return 1;	//1 반환
	}
	
	listNode* n = h;
	listNode* trail = NULL;
	//listNode 포인터변수 n과 trail 선언 후 초기화

	if(n->rlink->rlink == n)	//연결리스트안에 값이 하나일때
	{
		trail = n->rlink;
		free(trail);
		n->rlink = n;
		n->llink = n;
		
		return 0;
	}

	n = n->rlink;
	trail = n->rlink;
	trail->llink = h;
	h->rlink = trail;
	free(n);

	return 0;	// 0 반환
}


//연결리스트를 역순으로 배치하는 함수
int invertList(listNode* h) 
{
	if(h->rlink == h) {	//연결리스트가 비어있을때
		printf("Nothing to invert....\n");	//오류 메세지 출력
		return 1;	//1 반환
	}

	listNode* temp = h;
	listNode* front = NULL;
	listNode* back = NULL;
	//listNode 포인터 변수 temp,front,back 선언

	do{//temp가 h가될때까지 반복하는 do-while문
		front = temp->rlink;	//front에 temp의 rlink 저장
		back = temp->llink;		//back에 temp의 llink 저장

		temp->rlink = back;		//temp의 rlink에 back을 연결
		temp->llink	= front;	//temp의 llink에 front를 연결

		temp = temp->llink;		//temp를 llink로 이동
	}while(temp != h);

	return 0;	//0 반환
}



/* 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입 */
int insertNode(listNode* h, int key) 
{
	listNode *node = (listNode*)malloc(sizeof(listNode));
	//listNode 포인터변수 node 선언 후 동적할당
	node->key = key;	//node의 key에 사용자로부터 입력받은 key값 저장
	node->rlink = NULL;
	node->llink = NULL;
	//node의 rlink와 llink 초기화

	if(h->rlink== h)	//연결리스트가 비어있을때
	{
		h->rlink = node;
		h->llink = node;
		node->rlink = h;
		node->llink = h;
		return 0;
	}

	listNode *temp = h->rlink;
	//listNode 포인터 변수 temp 선언 후 h->rlink 저장

	//연결리스트가 비어있지 않을때
	while(temp != h)	//temp가 h가 될때까지 반복하는 while문
	{
		if(temp->key > node->key)	//temp->key가 node->key 보다 클때
		{
			node->rlink = temp;	//node의 rlink에 temp연결
			node->llink = temp->llink;	//node의 llink에 temp의 llink연결
			temp->llink->rlink = node;	//temp의 llink의 rlink에 node 연결
			temp->llink = node;	//temp의 llink에 node 연결
			return 0;	//0 반환
		}

		temp = temp->rlink;	//temp를 rlink로 이동
	}

	node->rlink = temp;	//node의 rlink에 temp 연결
	node->llink = temp->llink;	//node의 llink에 temp의 llink 연결
	temp->llink->rlink = node;	//temp의 llink의 rlink에 node 연결
	temp->llink = node;	//temp의 llink에 node 연결
	return 1;	//1 반환
}


//사용자로부터 key값을 입력받아 해당 노드를 삭제하는 함수
int deleteNode(listNode* h, int key) 
{
	if(h->rlink == h) {	//연결리스트가 비어있을때
		printf("Nothing to delete....\n");	//오류 메세지 출력
		return 1;	//1 반환
	}

	listNode* temp = h->rlink;
	listNode* front = NULL;
	listNode* back = NULL;
	//listNode 포인터변수 temp,front,back 선언

	while(temp != h)	//temp가 h가 될때까지 반복하는 while문
	{
		back = temp->llink;	//back에 temp의 llink저장
		front = temp->rlink;	//front에 temp의 rlink 저장

		if(temp->key == key)	//temp의 key가 사용자가 입력한 key의 값과 같을때
		{
			back->rlink = front;	//back의 rlink에 front연결
			front->llink = back;	//front의 llink에 back연결
			free(temp);	//temp free
			return 0;	//0반환
		}

		temp = temp->rlink;	//temp를 rlink로 이동
	}

	//key의 값이 연결리스트에 없을때
	printf("Check the key value.\n");	//오류 메시지 출력
	
	return 1;	//1 반환
}