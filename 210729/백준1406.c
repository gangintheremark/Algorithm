#pragma warning (disable:4996)
#include <stdio.h>
#include <malloc.h>

struct node {
	char data;
	struct node* next;
	struct node* prev;
};
typedef struct node Node;
Node* head = NULL;
Node* tail = NULL;
int size = 0, cursor;

void create(char);
void print();
void instruction_L();
void instruction_D();
void instruction_B();
void instruction_P();
Node* get_node(int);

int main()
{
	int index;
	char buffer, word;

	while (1) {
		scanf("%c", &buffer);
		if (buffer == '\n')
			break;
		create(buffer);
		size++;
	}

	cursor = size; // 명령어가 수행되기 전 커서는 문장의 맨 뒤에 위치

	scanf("%d", &index);
 
	for (int i = 0; i < index; i++) {

		scanf(" %c", &word);

		if (word == 'L')
			instruction_L();
		else if (word == 'D')
			instruction_D();
		else if (word == 'B')
			instruction_B();
		else if (word == 'P')
			instruction_P();
		
	}
	
	print();
	printf("%d", cursor);

	return 0;
}
void create(char buffer)
{
	Node* p = (Node*)malloc(sizeof(Node));
	Node* curr = (Node*)malloc(sizeof(Node));

	p->data = buffer;
	p->next = NULL;
	p->prev = NULL;

	if (head == NULL)
		head = p;
	else {
		curr = head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = p;
		p->prev = curr;
		tail = p;
	}
	return;
}

void print() {
	Node* p = (Node*)malloc(sizeof(Node));
	p = head;
	while(1){
		printf("%c ", p->data);
		if (p == tail)
			break;
		p = p->next;

		
	}
	printf("\n");
}

void instruction_L() {
	if (cursor != 0)
		cursor--;
	return;
}
void instruction_D() {
	if (cursor != size + 1)
		cursor++;
}
void instruction_B() { // 왼쪽문자 삭제
	Node* p = (Node*)malloc(sizeof(Node));
	p = get_node(cursor - 1); //삭제될 노드 찾아오기

	if (p == head) {
		head = head->next;
	}
	else if (p == tail) {
		tail = p->prev;
	}
	else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
	cursor--;  
	size--;
}
void instruction_P() {
	char buffer;
	scanf(" %c", &buffer);

	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = buffer;
	tmp->next = NULL;
	tmp->prev = NULL;

	if (cursor == 0) { // head에 삽입 
		tmp->next = head;
		head->prev = tmp;
		head = tmp;
	}

	if (cursor == size) {
		tail->next = tmp;
		tmp->prev = tail;
		tail = tmp;
	}
	else {
		Node* q = get_node(cursor - 1); // q뒤에 새로운 노드 삽입 

		tmp->prev = q;
		tmp->next = q->next;
		q->next->prev = tmp;
		q->next = tmp;
	}
	cursor++;
	size++;

}

Node* get_node(int index) { // 연결리스트의 index 번째 노드의 주소 반환 
	if (index < 0)
		return NULL;

	Node* p = head;
	for (int i = 0; i < index && p != NULL; i++)
		p = p->next;
	return p;
}

