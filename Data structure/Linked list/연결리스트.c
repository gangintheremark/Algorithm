#include <stdio.h>
#include <string.h>
/*
리스트 
 기본적인 연산 : 삽입, 삭제, 검색 등 
 리스트를 구현하는 대표적인 방법 : 배열, 연결리스트 

배열의 단점
 크기가 고정- reallocation이 필요 
 리스트 중간에 원소를 삽입하거나 삭제할 경우 다수의 데이터 이동

연결리스트
 다른 데이터의 이동없이 중간에 삽입이나 삭제가 가능
 길이 제한 x
 랜덤 엑세스 불가능 -> n번째 칸에 데이터를 쓰는데 걸리는 시간.
  ( 배열은 시작주소+4*n 하여 찾기가 쉬움 ) 
 */

struct node {
	char* data;
	struct node* next;
};

typedef struct node Node;
Node* head = NULL; // 연결리스트의 첫 번째 노드의 주소를 저장할 포인터 


/*
연결리스트 맨 앞에 새로운 노드 삽입하기 
 1) 새로운 노드를 만들고 추가할 데이터 저장
 2) 새로운 노드의 next 필드가 현재의 head 노드를 가리키도록 
 3) 새로운 노드를 새로운 head 노드로 
*/
void add_first(char* item) { // head가 전역변수인 경우
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = head;
	head = tmp;
}

void add_first(Node **ptr_head, char* item) { // head가 전역변수가 아닌경우 
	// 포인터 변수 head의 주소를 매개변수로 받는다. 
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = *ptr_head;
	*ptr_head = tmp;
} // 이렇게 구현할 경우 이 함수는 add_first(&head, item); 으로 호출해야함 

Node* add_first(Node* head, char* item)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = head;
	return tmp;  // 새로운 head 주소를 return 
} // 이렇게 구현할 경우 이 함수는 head = add_first(head, item); 으로 호출해야함


/*
어떤 노드 뒤에 새로운 노드 삽입하기
 1) 새로운 노드를 만들고 추가할 데이터 저장
 2) 새로운 노드의 next 필드가 prev의 다음 노드를 가리키도록 
 3) 새로운 노드를 prev의 다음 노드로  
*/

void add_after(Node* prev, char* item)
{
	if (prev == NULL)
		return;
	
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = prev->next;
	prev->next = tmp;
}

/*
첫번째 노드의 삭제하기 
 1) head가 null이 아니라면
 2) head가 현재 head 노드의 다음 노드로 가리키도록
*/

Node* remove_first() {
	if (head == NULL)
		return NULL;

	Node* tmp = head;
	head = head->next;
	return tmp;   // 삭제된 노드의 주소를 반환 
}

/*
어떤 노드의 다음 노드 삭제하기
 1) prev의 다음 노드가 null이 아니라면
 2) prev의 next필드가 현재 next 노드의 다음 노드를 가리키게
*/

Node* remove_after(Node* prev) {
	Node* tmp = prev->next;

	if (tmp == NULL)
		return NULL;

	prev->next = tmp->next;
	return tmp;
} // 어떤 노드를 삭제할 때는 삭제할 노드의 바로 앞 노드의 주소가 필요

/*
연결리스트 순회하기
*/

Node* find(char* word) {
	Node* p = head;
	while (p != NULL) {
		if (strcmp(p->data, word) == 0)
			return p;
		p = p->next;
	}
	return NULL;
}

Node* get_node(int index) { // 연결리스트의 index 번째 노드의 주소 반환 
	if (index < 0)
		return NULL;

	Node* p = head;
	for (int i = 0; i < index && p != NULL; i++)
		p = p->next;
	return p;
}

void add(int index, char* item) { // 연결리스트의 index번째 위치에 새로운 노드를 만들어서 삽입
	if (index < 0)
		return;
	
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = NULL;

	if (index = 0) {
		add_first(item);
		return;
	}
	
	Node* prev = get_node(index - 1);
	if (prev != NULL) {
		add_after(prev, item);
		return;
	}
	return;
}

Node *remove(int index) {
	if (index < 0)
		return;

	if (index = 0)
		return remove_first();

	Node* prev = get_node(index - 1);
	if (prev != NULL)
		return remove_after(prev);
	else
		return NULL;
}

Node* remove(char* item) { // 입력된 스트링을 저장한 노드를 찾아 삭제
	Node* p = head;
	Node* q = NULL;
	while (p != NULL && strcmp(p->data, item) != 0) {
		q = p;  // q는 항상 p의 직전 노드를 가리킴 
		p = p->next;
	}

	if (p == NULL)
		return NULL;
	if (q == NULL)
		return remove_first();
	else
		return remove_after(q);
}

void add_to_oredered_list(char* item) { // 오름차순으로 저장된 연결리스트에 새로운 데이터 삽입
	Node* p = head;
	Node* q = NULL;
	while (p != NULL && strcmp(p->data, item) <= 0) {
		q = p;  // q는 항상 p의 직전 노드를 가리킴 
		p = p->next;
	}
	if (q == NULL)
		return add_first(item);
	else
		add_after(q, item);
}



/*
이중 연결리스트
 - 각각의 노드가 다음노드와 이전노드의 주소를 가지는 연결리스트
 - 양방향의 순회 가능
*/

struct node {
	char* data;
	struct node next;
	struct node prev;
};
typedef struct node Node;

Node* head;
Node* tail;
int size = 0;


/* p가 가리키는 노드 앞에 새로운 노드를 삽입하는 경우 */
void add(char item, Node* p) {
	Node* new_node = (Node*)malloc(sizeof(Node));

	new_node->next = p;
	new_node->prev = p->prev;
	p->prev->next = new_node;
	p->prev = new_node;
}

/* p가 가리키는 노드를 삭제하는 경우 */
void remove(Node* p) {
	p->prev->next = p->next;
	p->next->prev = p->prev;
}

void add_after(Node* pre, char* item) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = item;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (pre == NULL && head == NULL) { // 빈 연결리스트 
		head = new_node;
		tail = new_node;
	}

	else if (pre == NULL) {  // head가 null 이 아니다.
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
}



