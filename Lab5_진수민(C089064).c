//  Lab No.5 : stack
// 작성자: 503, 진수민(C089064)
// 날짜  : 2021년 3월 31일
// 순차탐색함수를 이용해 사용자가 입력한 key 값을 찾는 프로그램을 작성하고 시간복잡도

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
typedef int Element;

Element data[MAX_STACK_SIZE];
int top;

void error(char str[]) {
	printf("%s\n", str);
	exit(1);
}

void init_stack() { top = -1; }
int is_empty() { return top == -1; }
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

int check_matching(char expr[]) {
	int i = 0, prev;
	char ch;
	init_stack();
	while (expr[i] != '\0') {
		ch = expr[i++];
		if (ch == '[' || ch == '(' || ch == '{') {
			push(ch);
		}
		else if (ch == ']' || ch == ')' || ch == '}') {
			if (is_empty()) {
				return 2;
			}
			prev = pop();
			if ((ch == ']' && prev != '[') || (ch == ')' && prev != '(') || (ch == '}' && prev != '{')) {
				return 3;
			}
		}
	}
	if (is_empty() == 0) {
		return 1;
	}
	return 0;
}

void main() {
	char expr[4][80] = { "{A[(i+1)]=0;}", "if((i==0)&&(j==0)", "A[(i+1])=0;", "A[i] = f)(;" };
	int errCode, i;

	for (i = 0; i < 4; i++) {
		errCode = check_matching(expr[i]);
		if (errCode == 0) {
			printf(" 정상: %s\n", expr[i]);
		}
		else {
			printf(" 오류: %s (조건%d 위반)", expr[i], errCode);
			if (errCode == 1) {
				printf("괄호가 닫히지 않았음.\n");
			}
			else if (errCode == 2) {
				printf("열림 괄호보다 닫힘 괄호가 먼저 표기되었음.\n");
			}
			else if (errCode == 3) {
				printf("괄호 종류가 잘못되었음.\n");
			}
		}
	}
}