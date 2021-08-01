#pragma warning ( disable:4996 )
#include <stdio.h>
#include <string.h>

struct node {
	int* data;
	struct node* next;

};
typedef struct node Node;

Node* head = NULL;

void create();
void add();
void add_first();
void add_after();
void print();
void remove_node();
void size();
void reverse();
void swap();
Node* get_node(int);


int main()
{
	char* buffer[20];
	int input;

	while (1) {
		printf("$ ");
		scanf("%s", buffer);


		if (strcmp(buffer, "create") == 0) {
			for (int i = 0; i < 4; i++) {
				scanf("%d", &input);
				create(input);
			}
		}
		else if (strcmp(buffer, "add") == 0)
			add();
		else if (strcmp(buffer, "print") == 0)
			print();
		else if (strcmp(buffer, "remove") == 0)
			remove_node();

		else if (strcmp(buffer, "size") == 0)
			size();
		else if (strcmp(buffer, "reverse") == 0)
			reverse();
		else if (strcmp(buffer, "swap") == 0)
			swap();
		else if (strcmp(buffer, "exit") == 0)
			break;
	}
}

void create(int input)
{
	Node* p = (Node*)malloc(sizeof(Node));
	Node* curr = (Node*)malloc(sizeof(Node));

	p->data = input;
	p->next = NULL;

	if (head == NULL)
		head = p;
	else {
		curr = head;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = p;
	}
}

void print() {
	Node* p = (Node*)malloc(sizeof(Node));
	for (p = head; p != NULL; p = p->next) {
		printf("%d ", p->data);
	}
	printf("\n");
}

void add() {
	char* word[20];
	int item, index;

	scanf("%s", word);

	if (strcmp(word, "-f") == 0) {
		scanf("%d", &item);
		add_first(item);
	}

	else if (strcmp(word, "-i") == 0) {
		scanf("%d", &index);
		scanf("%d", &item);

		Node* p = (Node*)malloc(sizeof(Node));

		p = get_node(index - 1);

		add_after(item, p);
	}
}

void add_first(int item) {
	Node* p = (Node*)malloc(sizeof(Node));

	p->data = item;
	p->next = head;
	head = p;
}

void add_after(int item, Node* p)
{
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = item;
	q->next = p->next;
	p->next = q;
}

Node* get_node(int index) {
	if (index < 0)
		return NULL;

	Node* p = head;
	for (int i = 0; i < index && p != NULL; i++)
		p = p->next;
	return p;
}

void remove_node() {
	char* word[20];
	int num, index;
	Node* p = (Node*)malloc(sizeof(Node));
	Node* prev = (Node*)malloc(sizeof(Node));

	scanf("%s", word);

	if (strcmp(word, "-i") == 0) {
		scanf("%d", &index);

		p = head;
		for (int i = 0; i < index - 1; i++) {
			p = p->next;
		}

		p->next = p->next->next;
	}
	if (strcmp(word, "-v") == 0) {
		scanf("%d", &num);

		p = head;
		prev = NULL;

		while (1)
		{
			if (p->data == num && p == head) {
				head = p->next;
				break;
			}

			prev = p;
			p = p->next;

			if (p->data == num) {
				prev->next = p->next;
				break;
			}
		}
	}
}

void size()
{
	int count = 0;
	Node* p = (Node*)malloc(sizeof(Node));
	p = head;
	while (p->next != NULL) {
		p = p->next;
		count++;
	}
	printf("%d\n", count + 1);
}

void reverse()
{
	Node* p, * q, * r;

	p = head;
	q = NULL;

	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	head = q;
}

void swap()
{
	int a, b;
	Node* p, * q, * prev_p, * prev_q, * temp;

	scanf("%d %d", &a, &b);

	p = get_node(a);
	q = get_node(b);
	prev_p = get_node(a - 1);
	prev_q = get_node(b - 1);

	if (p != NULL && q != NULL) {

		if (prev_p != NULL)
			prev_p->next = q;
		else
			head = q;

		if (prev_q != NULL)
			prev_q->next = p;
		else
			head = p;
	}

	temp = p->next;
	p->next = q->next;
	q->next = temp;
}