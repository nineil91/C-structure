//  Lab No.6 : stack-2
// �ۼ���: 503, ������(C089064)
// ��¥  : 2021�� 4�� 7��
// ���ÿ� ���ڿ��� �ְ� ����ϴ� ���α׷�

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
		error("���� ��ȭ ����");
	}
	data[++top] = e;
}
Element pop() {
	if (is_empty()) {
		error("���� ���� ����");
	}
	return data[top--];
}
Element peek() {
	if (is_empty()) {
		error("���� ���� ����");
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
