#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define INIT_CAPACITY 51

struct stack {
	char* contents;
	int top;
};
typedef struct stack Stack;

Stack* create();
void push(Stack*, char);
void pop(Stack*);
bool is_empty(Stack*);

int main()
{
	int T;
	char buffer[INIT_CAPACITY];

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		Stack* s = create();
		scanf("%s", buffer);

		int n = 0;
		while (buffer[n] != '\0')
		{
			if (buffer[n] == '(')
				push(s, buffer[n]);
			else {
				if (is_empty(s))
					break;
				pop(s);
			}
			n++;
		}

		if (!is_empty(s))
			printf("NO\n");
		else if (is_empty(s) && buffer[n] != '\0')
			printf("NO\n");
		else
			printf("YES\n");

		free(s);

	}
	return 0;
}
Stack* create()
{
	Stack* s = malloc(sizeof(Stack));

	s->contents = (char*)malloc(INIT_CAPACITY * sizeof(char));

	if (s->contents == NULL)
		free(s);

	s->top = -1;
	return s;
}
void push(Stack* s, char c)
{
	s->top++;
	s->contents[s->top] = c;
}
void pop(Stack* s)
{
	s->top--;
}
bool is_empty(Stack* s)
{
	return s->top == -1;
}