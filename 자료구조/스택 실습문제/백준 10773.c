#include <stdio.h>

struct stack {
	int* contents;
	int top;
};

typedef struct stack Stack;

Stack* create();
void push(Stack*, int);
void pop(Stack*);
int main()
{
	int K, index;
	scanf("%d", &K);

	Stack* s = create();
	for (int i = 0; i < K; i++) {
		scanf("%d", &index);

		if (index != 0)
			push(s, index);
		else
			pop(s);
	}
	int n = 0, sum = 0;
	while (1) {
		if (s->top < n)
			break;
		sum += s->contents[n];
		n++;
	}
	printf("%d\n", sum);
	return 0;

}

Stack* create() {
	Stack* s = malloc(sizeof(Stack));
	s->contents = (int*)malloc(sizeof(int)*100000); /* 문제 조건 */

	s->top = -1;
	return s;
}

void push(Stack* s, int i) {
	s->top++;
	s->contents[s->top] = i;
}
void pop(Stack* s) {
	s->top--;
}

