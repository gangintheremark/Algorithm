#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node {
	int data;
	struct node* next;
};
struct queue_type {
	struct node* front;
	struct node* rear;
	int size;
};

typedef struct node Node;
typedef struct queue_type Queue;

Queue* create();
void push(Queue*, int);
int pop(Queue*);
bool is_empty(Queue*);
int front(Queue*);
int back(Queue*);

int main(){
	int N, index;
	char buffer[50];
	scanf("%d", &N);

	if (N < 1 || N >= 10000)
		return 0;
	Queue* q = create();
	for (int i = 0; i < N; i++) {

		scanf("%s", buffer);

		if (strcmp(buffer,"push") == 0) {
			scanf("%d", &index);
			push(q, index);
		}
		else if (strcmp(buffer, "pop") == 0)
			printf("%d\n", pop(q));
		else if (strcmp(buffer, "size") == 0)
			printf("%d\n", q->size);
		else if (strcmp(buffer, "empty") == 0)
			printf("%d\n", is_empty(q));
		else if (strcmp(buffer, "front") == 0)
			printf("%d\n", front(q));
		else if (strcmp(buffer, "back") == 0)
			printf("%d\n", back(q));
	}
	return 0;
}
Queue* create(){
	Queue* tmp = malloc(sizeof(Queue));

	tmp->front = NULL;
	tmp->rear = NULL;
	tmp->size = 0;

	return tmp;
}
void push(Queue* q, int index){
	Node* new_node = malloc(sizeof(Node));
	new_node->data = index;
	new_node->next = NULL;

	if (q->front == NULL) {
		q->front = new_node;
		q->rear = new_node;
	}
	else {
		q->rear->next = new_node;
		q->rear = new_node;
	}
	q->size++;
}
int pop(Queue* q){
	Node* old_front = malloc(sizeof(Node));

	if (q->front == NULL)
		return -1;

	if (q->front == q->rear)
		q->rear = NULL;

	old_front = q->front;
	int i = old_front->data;
	q->front = old_front->next;
	free(old_front);
	q->size--;
	return i;
}
bool is_empty(Queue* q){
	return q->front == NULL;
}
int front(Queue* q){
	if (q->front == NULL)
		return -1;
	return q->front->data;
}
int back(Queue* q){
	if (q->rear == NULL)
		return -1;
	return q->rear->data;
}
