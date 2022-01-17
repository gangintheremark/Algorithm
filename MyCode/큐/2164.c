#include <stdio.h>
#include <stdlib.h>
#define INIT_CAPACITY 500000

struct queue {
	int* contents;
	int front;
	int rear;
	int size;
	int capacity;
};
typedef struct queue Queue;

Queue* create();
void push(Queue*, int);

int main()
{
	int N;
	Queue* q = create();

	scanf("%d", &N);

	if (N == 1) {
		printf("%d\n", N);
		return 0;
	}
	push(q, N);  // 카드 리스트 q 생성 

	while (1)
	{
		q->front = (q->front + 1) % q->capacity;
		q->size--; // 앞 삭제

		if (q->contents[q->front] == q->contents[q->rear]) {
			printf("%d\n", q->contents[q->front]);
			return 0;
		}
		
		q->rear = (q->rear + 1) % q->capacity;
		q->contents[q->rear] = q->contents[q->front];
		q->front = (q->front + 1) % q->capacity;

	}
	return 0;
	
}

Queue* create()
{
	Queue* q = malloc(sizeof(Queue));

	q->contents = (int*)malloc(INIT_CAPACITY * sizeof(int));

	if (q->contents == NULL)
		free(q);

	q->front = 0;
	q->rear = -1;
	q->size = 0;
	q->capacity = INIT_CAPACITY;

	return q;
}
void push(Queue* q, int N)
{
	for (int i = 1; i <= N; i++) {
		q->rear = (q->rear + 1) % q->capacity;
		q->contents[q->rear] = i;
		q->size++;
	}
}
