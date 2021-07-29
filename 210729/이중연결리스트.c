#include <stdio.h>

/*
단방향 연결리스트
 - 어떤 노드의 앞에 새로운 노드를 삽입하기 어려움
 - 삭제의 경우 항상 삭제할 노드의 앞 노드 필요
이중 연결리스트
 - 각각의 노드가 다음노드와 이전노드의 주소를 가지는 연결리스트
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

/* p가 가리키는 노드 뒤에 새로운 노드를 삽입하는 경우 */

void add_after(char* item, Node* p)
{
	Node* new_node = (Node*)malloc(sizeof(Node));

	new_node->data = item;
	new_node->next = NULL;
	new_node->prev = NULL;
	
	if (p == NULL && head == NULL) {  // 빈 노드일 때
		head = new_node;
		tail = new_node;
	}

	else if (p == NULL) { // 맨 앞에 삽입하라 
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}

	else if (p == tail) { // 맨 뒤에 삽입하라
		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
	}

	else {
		new_node->prev = p;
		new_node->next = p->next;
		p->next->prev = new_node;
		p->next = new_node;
	}
	size++;
}

/* p가 가리키는 노드를 삭제하는 경우 */
void remove(Node* p)
{
	if (head == p && tail == p ) { // p가 유일한 노드인 경우
		head = NULL;
		tail = NULL;
	}

	else if (p == head) {  // p가 head인 경우
		head = head->next;
		head->prev = NULL;
	}

	else if (p == tail) { // p가 tail인 경우
		tail = tail->prev;
		tail->next = NULL;
	}
	else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
	size--;

}

void add_ordered_list(char* item)
{
	Node* p = tail;
	while (p != NULL && strcmp(item, p->data) < 0)
		p = p->prev;
	add_after(p, item);
}
