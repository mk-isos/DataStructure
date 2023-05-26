/*
 * Binary Search Tree #2
 *
 * Data Structures
 *
 * Department of Computer Science
 * at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>
//<stdio.h>와 <stdlib.h>를 컴파일 전에 소스에 확장하도록 지시

//Node 구조체 선언
typedef struct node {
	int key;			//node의 data를 저장하는 key 선언
	struct node *left;	//node의 left-child를 저장하는 left선언
	struct node *right;	//node의 right-child를 저장하는 right선언
} Node;

/* for stack */
#define MAX_STACK_SIZE 20
Node* stack[MAX_STACK_SIZE];
int top = -1;

Node* pop();
void push(Node* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		20
Node* queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

Node* deQueue();
void enQueue(Node* aNode);


int initializeBST(Node** h);

/* functions that you have to implement */
void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int deleteNode(Node* head, int key);  /* delete the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */

void printStack();

//이 프로그램의 메인함수
int main()
{
	char command;	//사용자로부터 명령을 입력 받는 command변수 선언
	int key;	//사용자로부터 값을 입력 받는 key 선언
	Node* head = NULL;
	//Node 포인터 변수 head 선언

	printf("-------[2021041023] [Kim Moon Ki]-------\n");

	do{	//command가 q or Q가 입력될때까지 반복하는 do-while문
		//메뉴 출력
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);	//사용자로부터 command를 입력받음

		switch(command) {	//command의 값에 따라 실행하는 switch문
		case 'z': case 'Z':	//command가 z or Z일때
			initializeBST(&head);
			break;
		case 'q': case 'Q':	//command가 q or Q일때
			freeBST(head);
			break;
		case 'i': case 'I': //command가 i or I일때
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D': //command가 d or D일때
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(head, key);
			break;

		case 'r': case 'R': //command가 r or R일때
			recursiveInorder(head->left);
			break;
		case 't': case 'T': //command가 t or T일때
			iterativeInorder(head->left);
			break;

		case 'l': case 'L': //command가 l or L일때
			levelOrder(head->left);
			break;

		case 'p': case 'P': //command가 p or P일때
			printStack();
			break;

		default:	//command가 잘못 입력되었을때
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;	//1 반환
}

//BST를 초기화 하는 함수
int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)	//BST가 비어있을때
		freeBST(*h);

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	//h를 동적할당

	(*h)->left = NULL;	/* root */
	//h의 left-child를 NULL로 초기화
	(*h)->right = *h;
	//h의 right-child에 h를 저장
	(*h)->key = -9999;
	//h의 key에 -9999저장

	top = -1;
	//top을 -1로 초기화

	front = rear = -1;
	//front와 rear를 -1로 초기화

	return 1;	//1 반환
}

//재귀적방법으로 중위순회하는 함수
void recursiveInorder(Node* ptr)
{
	if(ptr) {	//ptr이 NULL이 아닐때
		recursiveInorder(ptr->left);	//ptr의 left-child를 중위순회
		printf(" [%d] ", ptr->key);		//ptr의 key값 출력
		recursiveInorder(ptr->right);	//ptr의 right-child를 중위순회
	}
}

//반복적방법으로 중위순회하는 함수
void iterativeInorder(Node* node)
{
	for(;;)	//무한 루프하는 for문
	{
		for(; node; node = node->left)	//node가 NULL이될때까지 반복하는 for문
			push(node);	//node를 push
		node = pop();	//node를 pop

		if(!node) break;	//node가 NULL일때 break
		printf(" [%d] ", node->key);	//node의 key값을 출력

		node = node->right;	//node를 noed의 right-child로 이동
	}
}

//level 순으로 순회하는 함수
void levelOrder(Node* ptr)
{
	if(!ptr) return; /* empty tree */
	//ptr이 NULL일때 return

	enQueue(ptr);
	//ptr을 enQueue

	for(;;)	//무한루프 for문
	{
		ptr = deQueue();	//ptr을 deQueue
		if(ptr) {	//ptr이 NULL일때
			printf(" [%d] ", ptr->key); //ptr의 key값 출력

			if(ptr->left)	//ptr의 left-child가 NULL이 아닐때
				enQueue(ptr->left);	//ptr의 left-child를 enQueue
			if(ptr->right)	//ptr의 right-child가 NULL이 아닐때
				enQueue(ptr->right);//ptr의 right-child를 enQueue
		}

		else//ptr이 NULL일때
			break;	//break
	}

}

//BST에 node를 삽입하는 함수
int insert(Node* head, int key)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	//Node 포인터변수 newNode를 선언 후 동적 할당
	newNode->key = key;
	//newNode의 key를 사용자로부터 입력받은 key로 설정
	newNode->left = NULL;
	newNode->right = NULL;
	//newNode의 left-child와 right-child를 NULL로 초기화

	if (head->left == NULL) {	//head의 left-child가 NULL일때
		head->left = newNode;	//head의 left-child에 newNode 저장
		return 1;	//1 반환
	}

	/* head->left is the root */
	Node* ptr = head->left;
	//Node 포인터 변수 ptr에 head의 left-child 저장

	Node* parentNode = NULL;
	//Node 포인터 변수 parentNode를 NULL로 초기화
	while(ptr != NULL) {	//ptr이 NULL이 아닐때 반복하는 while문

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}

	/* linking the new node to the parent */
	if(parentNode->key > key)
		parentNode->left = newNode;
	else
		parentNode->right = newNode;
	return 1;
}

//Node를 삭제하는 함수
int deleteNode(Node* head, int key)
{
	if (head == NULL) {	//head가 NULL일때
		printf("\n Nothing to delete!!\n");	//오류메시지 출력
		return -1; //-1 반환
	}

	if (head->left == NULL) {	//head의 left-child가 NULL일때
		printf("\n Nothing to delete!!\n");	//오류메시지 출력
		return -1;	//-1 반환
	}

	/* head->left is the root */
	Node* root = head->left;	
	//Node 포인터 변수 root선언 후 head의 left-child 저장

	Node* parent = NULL;
	//Node 포인터 변수 parent 선언
	Node* ptr = root;
	//Node 포인터 변수 ptr 선언 후 root 저장

	while((ptr != NULL)&&(ptr->key != key)) {	//ptr이 NULL이 아니고 ptr의 key가 key가 아닐때 반복하는 while 문 
		if(ptr->key != key) 
		{	//ptr의 key값이 key가 아닐때
			parent = ptr;	
			//parent에 ptr 저장

			if(ptr->key > key)	//ptr의 key가 key보다 클때
				ptr = ptr->left;	//ptr에 ptr left-child 저장
			else	//ptr의 key가 key보다 작거나 같을때
				ptr = ptr->right;	//ptr에 ptr right-child 저장
		}
	}

	/* there is no node for the key */
	if(ptr == NULL)	//ptr이 NULL일때
	{
		printf("No node for key [%d]\n ", key);	//오류메시지 출력
		return -1; //-1 반환
	}

	/*
	 * case 1: the node which has to be removed is a leaf node
	 */
	if(ptr->left == NULL && ptr->right == NULL)	//ptr의 left-child가 NULL이고 ptr의 right-child가 NULL일때
	{
		if(parent != NULL) { //parent의 left-child가 ptr일때
			if(parent->left == ptr)	//parent의 left-child가 ptr일때
				parent->left = NULL;	//parent의 left-child를 NULL로 초기화
			else	//parent의 left-child가 ptr이 아닐때
				parent->right = NULL;	//parent의 right-child를 NULL로 초기화
		} 
		else {	//parent의 left-child가 ptr이 아닐때
			/* parent is null, which means the node to be deleted is the root */
			head->left = NULL;
			//head의 left-child를 NULL로 초기화
		}

		free(ptr);	//ptr을 free
		return 1;	//1 반환
	}

	if ((ptr->left == NULL || ptr->right == NULL))	//ptr의 left-child가 NULL이거나 ptr의 right-child가 NULL일때
	{
		Node* child;
		//Node 포인터 변수 child 선언
		if (ptr->left != NULL)	//ptr의 left-child가 NULL이 아닐때
			child = ptr->left;	//child에 ptr의 left-child 저장
		else	//ptr의 left-child가 NULL이 아닐때
			child = ptr->right;	//child에 ptr의 right-child 저장

		if(parent != NULL)	//parent가 NULL이 아닐때
		{
			if(parent->left == ptr)	//parent의 left-child가 ptr일때
				parent->left = child;	//parent의 left-child에 child 저장
			else	//parent의 left-child가 ptr이 아닐때
				parent->right = child;	//parent의 right-child에 child 저장
		} else {
			root = child;	//root에 child 저장
		}

		free(ptr);	//ptr free
		return 1;	//1 반환
	}


	Node* candidate;
	//Node 포인터 변수 canditate
	parent = ptr;
	//parent에 ptr 저장

	candidate = ptr->right;
	//candidate에 ptr의 right-child 저장

	//candidate의 left-child가 NULL이 아닐때
	while(candidate->left != NULL)
	{
		parent = candidate;	//parent에 candidate 저장
		candidate = candidate->left;	//candidate에 candidate의 left-child 저장
	}

	if (parent->right == candidate) //parent의 right-child가 candidate일때
		parent->right = candidate->right;	//parent의 right-child에 candidate의 right-child 저장
	else	//parent의 right-child가 candidate가 아닐때
		parent->left = candidate->right;	//parent의 left-child에 candidate의 right-child 저장

	/* instead of removing ptr, we just change the key of ptr
	 * with the key of candidate node and remove the candidate node
	 */

	ptr->key = candidate->key;
	//ptr의 key값에 candidate의 key값 저장

	free(candidate);
	//candidate free

	return 1;	//1 반환
}

//Node를 free하는 함수
void freeNode(Node* ptr)
{
	if(ptr) {	//ptr이 NULL일때
		freeNode(ptr->left);	//ptr의 left-child를 free
		freeNode(ptr->right);	//ptr의 right-child를 free
		free(ptr);	//ptr free
	}
}

//BST를 free하는 함수
int freeBST(Node* head)
{
	if(head->left == head)	//head의 left-child가 head일때
	{
		free(head);	//head free
		return 1;	//1 반환
	}

	Node* p = head->left;
	//Node 포인터 변수 p 선언 후 head의 left-child 저장

	freeNode(p);
	//p를 free

	free(head);
	//head를 free

	return 1;
	//1 반환
}

//stack을 pop하는 함수
Node* pop()
{
	if (top < 0) return NULL;	//top이 0보다 작을때 NULL을 return
	return stack[top--];	//stack[top]을 return하고 top을 -1
}

//stack에 push하는 함수
void push(Node* aNode)
{
	stack[++top] = aNode;
	//top을 +1하고 stack[top]에 aNode 저장
}

void printStack()
{
	int i = 0;
	printf("--- stack ---\n");
	while(i <= top)
	{
		printf("stack[%d] = %d\n", i, stack[i]->key);
	}
}

//deQueue 함수
Node* deQueue()
{
	if (front == rear) {	//front가 rear와 일치할때
		// printf("\n....Now Queue is empty!!\n" );	
		return NULL;	//NULL을 리턴
	}

	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];	//queue[front] 리턴

}

//enQueue 함수
void enQueue(Node* aNode)
{
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	if (front == rear) {	//front와 rear가 같을때
		// printf("\n....Now Queue is full!!\n");
		return;	//return NULL
	}

	queue[rear] = aNode;	//queue[rear]에 aNode 저장
}