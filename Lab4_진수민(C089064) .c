//  Lab No.4 : 다항식 프로그램
// 작성자: 503, 진수민(C089064)
// 날짜  : 2021년 3월 24일
// 다항식 프로그램을 이용하여 두 다항식의 뺄셈 하는 합수를 구현하라. 
// 또, 연산결과 최고차항의 연산의 계수가 0으로 변하였을경우 계수가 0이 아닌 값이 나오도록 
// 멤버 값들을 변성하는 함수를 구현하라.


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} Polynomial;

Polynomial read_poly();
void print_poly(Polynomial p, char str[]);
Polynomial add_poly(Polynomial a, Polynomial b);
Polynomial sub_poly(Polynomial a, Polynomial b);

void main() {
	Polynomial a, b, c, d;
	a = read_poly();
	b = read_poly();
	c = add_poly(a, b);
	d = sub_poly(a, b);
	print_poly(a, " A = ");
	print_poly(b, " B = ");
	print_poly(c, "A+B= ");
	print_poly(d, "A-B= ");

	system("pause");
}

Polynomial read_poly() {
	int i;
	Polynomial p;

	printf("다항식의 최고 차수를 입력하시오 : ");
	scanf("%d", &p.degree);
	printf("각 항의 계수를 입력하시오 (총 %d개) : ", p.degree + 1);
	for (i = 0; i <= p.degree; i++) {
		scanf("%f", p.coef + i);
	}

	return p;
}

void print_poly(Polynomial p, char str[]) {
	int i = 0;
	printf("\t%s", str);
	
	printf("%5.1f x^%d", p.coef[i], p.degree - i);

	for (i = 1; i < p.degree; i++) {
		
		if (p.coef > 0) {
			printf(" + %5.1f x^%d", p.coef[i], p.degree - i);
		}
		else {
			printf(" %5.1f x^%d", p.coef[i], p.degree - i);
		}
	}
	
	if (p.coef > 0) {
		printf(" + %4.1f\n", p.coef[p.degree]);
	}
	else {
		printf(" - %4.1f\n", p.coef[p.degree]);
	}
}

Polynomial add_poly(Polynomial a, Polynomial b) {
	int i;
	Polynomial p;
	if (a.degree > b.degree) {
		p = a;
		for (i = 0; i <= b.degree; i++) {
			p.coef[i + (p.degree - a.degree)] += b.coef[i];
		}
	}
	else {
		p = b;
		for (i = 0; i <= a.degree; i++) {
			p.coef[i + (p.degree - a.degree)] += a.coef[i];
		}
	}

	printf("\n");

	return p;
}

Polynomial sub_poly(Polynomial a, Polynomial b) {
	int i;
	Polynomial p;
	if (a.degree > b.degree) {
		p = a;
		for (i = 0; i <= b.degree; i++) {
			p.coef[i + (p.degree - a.degree)] -= b.coef[i];
		}
	}
	else {
		p = b;
		for (i = 0; i <= a.degree; i++) {
			p.coef[i + (p.degree - a.degree)] -= a.coef[i];
		}
	}

	printf("\n");

	return p;
}


