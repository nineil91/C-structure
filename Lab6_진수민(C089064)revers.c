//  Lab No.6 : stack-2
// 작성자: 503, 진수민(C089064)
// 날짜  : 2021년 4월 7일
// 스택에 문자열을 넣고 출력하는 프로그램

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int Element;

Element data[MAX_STACK_SIZE];
int top;

void init_stack() { top = EOF; }
int is_empty() { return top == EOF; }
int is_full() { return top == MAX_STACK_SIZE - 1; }
int size() { return top + 1; }


void push(Element e) {
	if (is_full()) {
		error("스택 포화 에러");
	}
	data[++top] = e;
}
Element pop() {
	if (is_empty()) {
		error("스택 공백 에러");
	}
	return data[top--];
}
Element peek() {
	if (is_empty()) {
		error("스택 공백 에러");
	}
	return data[top];
}

void print_stack(char msg[]) {
	int i;
	printf("%s[%2d]= ", msg, size());
	for (i = 0; i < size(); i++) {
		printf("%2d ", data[i]);
	}
	printf("\n");
}

void main() {
	int ch = 'A';

	while ((ch != getchar()) != EOF) {
		push(ch);
	}
	while ((ch = pop()) != data[top]) {
		putchar(ch);
	}

}
