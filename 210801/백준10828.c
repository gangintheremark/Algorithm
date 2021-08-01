#pragma warning (disable:4996)
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct node {
	int data;
	struct node* next;
};
struct stack_type {
	struct node* top;
};
typedef struct stack_type Stack;
typedef struct node Node;
int count = 0;

bool is_empty(Stack* s)
{
	return s->top == NULL;
}
void push(Stack* s)
{
	int index;
	scanf("%d", &index);

	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = index;
	tmp->next = s->top;
	s->top = tmp;
	count++;
}
int pop(Stack* s)
{
	if (s->top ==NULL)
		return -1;

	int index = s->top->data;
	s->top = s->top->next;
	count--;
	return index;
}
int top(Stack* s)
{
	if (is_empty(&s))
		return -1;
	else
		return s->top->data;
}
int main()
{
	int index; 
	char buffer[10000];
	Stack* s = NULL;

	scanf("%d", &index);

	for (int i = 0; i < index; i++) {
		scanf("%s", buffer);

		if (strcmp(buffer, "push") == 0)
			push(&s);
		else if (strcmp(buffer, "pop") == 0)
			printf("%d", pop(&s));
		else if (strcmp(buffer, "empty") == 0)
			printf("%d", is_empty(&s));
		else if (strcmp(buffer, "size") == 0)
			printf("%d", count);
		else if (strcmp(buffer, "top") == 0)
			printf("%d", top(&s));
		else
			break;
	}
	return 0;
}

