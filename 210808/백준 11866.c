#pragma warning (disable:4996)
#include <stdio.h>
#define CAPACITY 10000000


struct queue {
	int* contents;
	int front;
	int rear;
	int size;
	int capacity;
};

typedef struct queue Queue;

Queue* create();
int pop(Queue*);
void make_queue(Queue* q, int);
void move_back(Queue*);


int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	if (K > N)
		return 0;

	if (N == 1 && K == 1) {
		printf("<1>");
		return 0;
	}

	Queue* q = create();
	
	make_queue(q, N);

	printf("<");
	while (1) {
		for (int i = 0; i < K - 1; i++)
			move_back(q);

		printf("%d", pop(q));

		if (q->size == 1) {
			printf(", %d>", pop(q));
			break;
		}

		printf(", ");
	}
}

Queue* create()
{
	Queue* q = malloc(sizeof(Queue));
	q->contents = (int*)malloc(sizeof(int) * CAPACITY);

	q->front = 0;
	q->rear = -1;
	q->size = 0;
	q->capacity = CAPACITY;

	return q;
}
void make_queue(Queue* q, int N)
{
	for (int i = 0; i < N; i++)
		q->contents[i] = i + 1;

	q->rear = N - 1;
	q->size = N;

}
void move_back(Queue* q)
{
	q->rear = (q->rear + 1) % q->capacity;
	q->contents[q->rear] = q->contents[q->front];
	q->front = (q->front + 1) % q->capacity;

}
int pop(Queue* q)
{
	int result = q->contents[q->front];
	q->front = (q->front + 1) % q->capacity;
	q->size--;
	return result;
}

