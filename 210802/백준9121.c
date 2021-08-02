#pragma warning (disable:4996)
#include <stdio.h>

struct node {
	char data;
	struct node* next;
};
struct stack {
	struct node* top;
};
typedef struct stack Stack;
typedef struct node Node;

Stack* s = NULL;

void check_VPS(char*);
void push(Stack*, char);
char pop(Stack*);
int main()
{
	int T;
	char buffer[50];
	
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {

		scanf("%s", buffer);

		int n = 0;
		while (buffer[n] != '\0')
		{
			if (buffer[n] == '(')
				push(&s, buffer[n]);
			else {
				if (s == NULL) {
					break;
				}
				pop(&s);
			}
			n++;
		}
		if (s != NULL)
			printf("No\n");
		else if (s == NULL && buffer[n] != '\0')
			printf("No\n");
		else
			printf("Yes\n");


	}
	return 0;
}


void push(Stack* s, char item)
{
	Node* new_node = (Node*)malloc(sizeof(Node));

	if (s == NULL) 
		s->top->data = item;

	else {
		new_node->data = item;
		new_node->next = s->top;
		s->top = new_node;
	}
}
char pop(Stack* s)
{
	Node* old_node = (Node*)malloc(sizeof(Node));

	old_node->data = s->top->data;
	s->top = s->top->next;

	return old_node->data;
}