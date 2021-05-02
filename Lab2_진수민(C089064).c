//  Lab No.2 : 시간 복잡도 분석- 실행시간 측정, 비교횟수 counting 기법
// 작성자: 503, 진수민(C089064)
// 날짜  : 2021년 3월 17일
// 순차탐색함수를 이용해 사용자가 입력한 key 값을 찾는 프로그램을 작성하고 시간복잡도를 측정한다

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

int list[N];
int n, key, count = 0;
void ran();
int sequential_search(int list[], int n, int key);

int main() {

	clock_t start, finish;
	double duration;
	
	//start = clock();

	printf("키 값을 입력하세요 : ");
	scanf("%d", &key);
	

	ran();

	sequential_search(list, n, key);

	printf("\ncount = %d", count);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f 초입니다\n", duration);

	return 0;
	
}

int sequential_search(int list[], int n, int key) {
	
	for (int i = 0; i < n; i++) {
		if (list[i] == key) {
			return i;
		}
		count++;
	}

	printf("\n 해당 키값 찾음");

	return -1;

}

void ran() {

	int i;

	srand((unsigned)time(NULL));      // 초기화

	for (i = 0; i < N; i++) {
		n = rand();
		list[i] = n;
	}


	return list;
}