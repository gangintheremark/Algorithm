# 자료구조
## 리스트
- 기본적인 연산 : 삽입, 삭제, 검색 등
- 리스트를 구현하는 대표적인 방법 : 배열, 연결리스트
---------------
## 스택
- 스택은 일종의 리스트
- 단, 데이터의 삽입과 삭제가 한쪽 끝에서만 이루어짐
- LIFO ( Last-In, First-Out )
- 삽입/삭제가 일어나는 쪽을 스택의 top이라고 부름 
- 스택 응용 예 : 괄호 검사 문제 (입력 수식의 괄호가 올바른지 검사)

## 큐
- 큐 역시 스택과 마찬가지로 일종의 리스트
- 단 데이터의 삽입은 한쪽 끝에서, 삭제는 반대쪽 끝에서만 일어남
- FIFO (First-In,First-Out ) 
- 삽입이 일어나는 쪽을 rear, 삭제가 일어나는 쪽을 front라고 부름 
--------------
### 스택과 큐 생성 시 항상 쓰는 create 함수

 - 스택 
```
Stack* create() {
	Stack* s = malloc(sizeof(Stack));
	s->contents = (int*)malloc(sizeof(int) * CAPACITY); 
    /* 문제 조건에 따라 메모리 할당하기 */

	s->top = -1;
	return s;
}

```
 - 큐 
```
Queue* create()
{
	Queue* q = malloc(sizeof(Queue));
	q->contents = (int*)malloc(sizeof(int) * CAPACITY);
        /* 문제 조건에 따라 메모리 할당하기 */

	q->front = 0;
	q->rear = -1;
	q->size = 0;
	q->capacity = CAPACITY;

	return q;
}
```