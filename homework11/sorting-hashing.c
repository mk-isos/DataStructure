/*
 * sorting-hashing.c
 *
 *  Sorting & Hashing
 *  School of Computer Science at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//<stdio.h>,<stdlib.h>,<time.h>를 컴파일전에 소스에 확장하도록 지시

#define MAX_ARRAY_SIZE			13	/* prime number */
#define MAX_HASH_TABLE_SIZE 	MAX_ARRAY_SIZE

/* 필요에 따라 함수 추가 가능 */
int initialize(int **a);
int freeArray(int *a);
void printArray(int *a);

int selectionSort(int *a);
int insertionSort(int *a);
int bubbleSort(int *a);
int shellSort(int *a);
/* recursive function으로 구현 */
int quickSort(int *a, int n);


/* hash code generator, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key);

/* array a에대 한 hash table을 만든다. */
int hashing(int *a, int **ht);

/* hash table에서 key를 찾아 hash table의 index return */
int search(int *ht, int key);

//정렬 프로그램의 메인함수
int main()
{
	char command; //사용자로부터 명령을 입력받을 command 선언
	int *array = NULL; //int형 포인터 변수 array 선언 후 NULL로 초기화
	int *hashtable = NULL; //int형 포인터 변수 hashtable 선언 후 NULL로 초기화
	int key = -1;	//int형 변수 key 선언
	int index = -1; //int형 변수 index 선언

	srand(time(NULL));
	//time을 시드로 설정 

	printf("------[2021041023] [Kim Moon Ki]------\n");

	do{	//q or Q 가 입력되기 전까지 반복하는 do-while문
		//메뉴 출력
		printf("----------------------------------------------------------------\n");
		printf("                        Sorting & Hashing                       \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize       = z           Quit             = q\n");
		printf(" Selection Sort   = s           Insertion Sort   = i\n");
		printf(" Bubble Sort      = b           Shell Sort       = l\n");
		printf(" Quick Sort       = k           Print Array      = p\n");
		printf(" Hashing          = h           Search(for Hash) = e\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //사용자로부터 command를 입력받음

		switch(command) { //command 값에 따라 실행하는 switch문
		case 'z': case 'Z':	//command가 z or Z일때
			initialize(&array);
			break;
		case 'q': case 'Q':	//command가 q or Q일때
			freeArray(array);
			break;
		case 's': case 'S': //command가 s or S일때
			selectionSort(array);
			break;
		case 'i': case 'I': //command가 i or I일때
			insertionSort(array);
			break;
		case 'b': case 'B': //command가 b or B일때
			bubbleSort(array);
			break;
		case 'l': case 'L': //command가 l or L일때
			shellSort(array);
			break;
		case 'k': case 'K': //command가 k or K일때
			printf("Quick Sort: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			quickSort(array, MAX_ARRAY_SIZE);
			printf("----------------------------------------------------------------\n");
			printArray(array);
			break;
		case 'h': case 'H': //command가 h or H일때
			printf("Hashing: \n");
			printf("----------------------------------------------------------------\n");
			printArray(array);
			hashing(array, &hashtable);
			printArray(hashtable);
			break;
		case 'e': case 'E': //command가 e or E일때
			printf("Your Key = ");
			scanf("%d", &key);
			printArray(hashtable);
			index = search(hashtable, key);
			printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]);
			break;
		case 'p': case 'P': //command가 p or P일떄
			printArray(array);
			break;
		default: //command가 잘못 입력 되었을때
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1; //1반환
}

//배열을 초기화 하는 함수
int initialize(int** a)
{
	int *temp = NULL;
	//int형 포인터변수 temp 선언후 초기화
	/* array가 NULL인 경우 메모리 할당 */
	if(*a == NULL) {
		temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE); 
		*a = temp;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	} else
		temp = *a;

	/* 랜덤값을 배열의 값으로 저장 */
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)
		temp[i] = rand() % MAX_ARRAY_SIZE;

	return 0; //0 반환
}

//배열을 free하는 함수
int freeArray(int *a)
{
	if(a != NULL) //a가 비어있지않을때
		free(a);	//a를 free
	return 0;	//0 반환
}

//배열을 출력하는 함수
void printArray(int *a)
{
	if (a == NULL) {//a가 비어있을때
		printf("nothing to print.\n"); //오류메시지 출력
		return;	//NULL값 반환
	}
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)	//MAX_ARRAY_SIZE만큼 반복하는 for문
		printf("a[%02d] ", i); 	//배열출력
	printf("\n");
	for(int i = 0; i < MAX_ARRAY_SIZE; i++)	//MAX_ARRAY_SIZE만큼 반복하는 for문
		printf("%5d ", a[i]);
	printf("\n");
}

//선택정렬 함수
int selectionSort(int *a)
{
	int min;
	int minindex;
	int i, j;

	printf("Selection Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	//min값을 찾아 최소값 부터 앞으로 정렬하는 방식
	for (i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		minindex = i;
		min = a[i];
		for(j = i+1; j < MAX_ARRAY_SIZE; j++)
		{
			if (min > a[j])	
			{
				min = a[j];
				minindex = j;
			}
		}
		a[minindex] = a[i];
		a[i] = min;
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);
	return 0;
}

//삽입정렬 함수
int insertionSort(int *a)
{
	int i, j, t;

	printf("Insertion Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	//앞에서부터 반복하며 알맞은 자리에 삽입하는 방식
	for(i = 1; i < MAX_ARRAY_SIZE; i++)
	{
		t = a[i];
		j = i;
		while (a[j-1] > t && j > 0)
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = t;
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

//버블정렬 함수
int bubbleSort(int *a)
{
	int i, j, t;

	printf("Bubble Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	//근접값을 비교하며 정렬하는 방식
	for(i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		for (j = 1; j < MAX_ARRAY_SIZE; j++)
		{
			if (a[j-1] > a[j])
			{
				//배열 값 스왑
				t = a[j-1];
				a[j-1] = a[j];
				a[j] = t;
			}
		}
	}

	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

//셀정렬 함수
int shellSort(int *a)
{
	int i, j, k, h, v;

	printf("Shell Sort: \n");
	printf("----------------------------------------------------------------\n");

	printArray(a);

	//임의의 간격을 생성해 간격별로 정렬하며 간격을 줄여나가는 방식
	for (h = MAX_ARRAY_SIZE/2; h > 0; h /= 2)
	{
		for (i = 0; i < h; i++)
		{
			for(j = i + h; j < MAX_ARRAY_SIZE; j += h)
			{
				v = a[j];
				k = j;
				while (k > h-1 && a[k-h] > v)
				{
					a[k] = a[k-h];
					k -= h;
				}
				a[k] = v;
			}
		}
	}
	printf("----------------------------------------------------------------\n");
	printArray(a);

	return 0;
}

//퀵정렬 함수
int quickSort(int *a, int n)
{
	int v, t;
	int i, j;

	//pivot을 설정해 pivot을 기준으로 정렬해 나가는 방식
	if (n > 1)
	{
		v = a[n-1];
		i = -1;
		j = n - 1;

		while(1)
		{
			while(a[++i] < v);
			while(a[--j] > v);

			if (i >= j) break;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		t = a[i];
		a[i] = a[n-1];
		a[n-1] = t;

		quickSort(a, i);
		quickSort(a+i+1, n-i-1);
	}


	return 0;
}

//key 값을 구해 반환하는 함수
int hashCode(int key) {
   return key % MAX_HASH_TABLE_SIZE;
}

//hasing 함수
int hashing(int *a, int **ht)
{
	int *hashtable = NULL;

	/* hash table이 NULL인 경우 메모리 할당 */
	if(*ht == NULL) {
		hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
		*ht = hashtable;  /* 할당된 메모리의 주소를 복사 --> main에서 배열을 control 할수 있도록 함*/
	} else {
		hashtable = *ht;	/* hash table이 NULL이 아닌경우, table 재활용, reset to -1 */
	}

	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		hashtable[i] = -1;

	/*
	for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++)
		printf("hashtable[%d] = %d\n", i, hashtable[i]);
	*/

	int key = -1;
	int hashcode = -1;
	int index = -1;
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		key = a[i];
		hashcode = hashCode(key);
		/*
		printf("key = %d, hashcode = %d, hashtable[%d]=%d\n", key, hashcode, hashcode, hashtable[hashcode]);
		*/
		if (hashtable[hashcode] == -1)
		{
			hashtable[hashcode] = key;
		} else 	{

			index = hashcode;

			while(hashtable[index] != -1)
			{
				index = (++index) % MAX_HASH_TABLE_SIZE;
				/*
				printf("index = %d\n", index);
				*/
			}
			hashtable[index] = key;
		}
	}

	return 0;
}

//hash-search 함수
int search(int *ht, int key)
{
	int index = hashCode(key);

	if(ht[index] == key)
		return index;

	while(ht[++index] != key)
	{
		index = index % MAX_HASH_TABLE_SIZE;
	}
	return index;
}

