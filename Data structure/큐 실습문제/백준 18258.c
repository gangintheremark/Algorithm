#include <stdio.h>
#include <stdbool.h>

#define INIT_CAPACITY 2000000
struct Queue_type {
	int* contents;
	int front;
	int rear;
	int size;
	int capacity;
};

typedef struct Queue_type Queue;

Queue* create();
void push(Queue*, int);
int pop(Queue*);
bool is_empty(Queue*);
int front(Queue*);
int back(Queue*);

int main()
{
	int N, index;
	char buffer[50];

	scanf("%d", &N);

	Queue* q = create();

	for (int i = 0; i < N; i++) {

		scanf("%s", buffer);

		if (strcmp(buffer, "push") == 0) {
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
Queue* create() {
	Queue* q = malloc(sizeof(Queue));

	q->contents = (int*)malloc(sizeof(int) * INIT_CAPACITY);

	q->front = 0;
	q->rear = -1;
	q->size = 0;
	q->capacity = INIT_CAPACITY;
	return q;
}

void push(Queue* q, int index)
{
	q->rear = (q->rear + 1) % q->capacity;
	q->contents[q->rear] = index;
	q->size++;
}

int pop(Queue* q)
{
	if (q->size == 0)
		return -1;
	int result = q->contents[q->front];
	q->front = (q->front + 1) % q->capacity;
	q->size--;
	return result;
}

bool is_empty(Queue* q)
{
	return q->size == 0;
}

int front(Queue* q)
{
	if (q->size == 0)
		return -1;
	return q->contents[q->front];
}

int back(Queue* q)
{
	if (q->size == 0L)
		return -1;
	return q->contents[q->rear];
}