#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef int Item; // 데이터타입이 정수인 데이터를 저장한다 가정
typedef struct stack_type *Stack;

Stack create();
void destory(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);

#endif