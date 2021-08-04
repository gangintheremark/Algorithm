#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define INIT_CAPACITY 10000

struct stack_type {
	int* contents;
	int top;
	int size;
};
typedef struct stack_type Stack;
Stack* create();
void push(Stack*);
int pop(Stack*);
int top(Stack*);

bool is_empty(Stack* s)
{
	return s->top == -1;
}

int main()
{
	int index;
	char buffer[10000];
	Stack* s = create();

	scanf("%d", &index);

	for (int i = 0; i < index; i++) {
		scanf("%s", buffer);

		if (strcmp(buffer, "push") == 0)
			push(s);
		else if (strcmp(buffer, "pop") == 0)
			printf("%d\n", pop(s));
		else if (strcmp(buffer, "empty") == 0)
			printf("%d\n", is_empty(s));
		else if (strcmp(buffer, "size") == 0)
			printf("%d\n", s->size);
		else if (strcmp(buffer, "top") == 0)
			printf("%d\n", top(s));
		else
			break;
	}
	
	return 0;
}
Stack* create()
{
	Stack* s = malloc(sizeof(struct stack_type));

	s->contents = (int*)malloc(INIT_CAPACITY * sizeof(int));

	if (s->contents == NULL) {
		free(s);
	}

	s->top = -1;
	s->size = 0;
	return s;
}
void push(Stack* s)
{
	int index;
	scanf("%d", &index);

	s->top++;
	s->contents[s->top] = index;
	s->size++;
}

int pop(Stack* s)
{
	if (is_empty(s))
		return -1;
	s->top--;
	s->size--;
	return s->contents[s->top + 1];
}

int top(Stack* s)
{
	if (is_empty(s))
		return -1;
	else
		return s->contents[s->top];
}