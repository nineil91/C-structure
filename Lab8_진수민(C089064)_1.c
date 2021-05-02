//  Lab No 8-1  : 세가지 단순한 정렬 알고리즘- 선택정렬, 삽입정렬, 버블정렬-에 대해서 실행시간을 측정하여 결과를 비교하는 프로그램
// 작성자: 503, 진수민(C089064)
// 날짜  : 2021년 4월 21일


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x, y, t) ((t)=(x),(x)=(y),(y)=(t))
#define N 100000

void printArray(int arr[], int n, char* str);
void printStep(int arr[], int n, int val);
void selection_sort(int list_selection[], int n);//선택정렬
void insertion_sort(int list_insertiont[], int n);//삽입정렬
void bubble_sort(int list_bubble[], int n);//버블정렬
int list[N];
int list_selection[N];
int list_insertion[N];
int list_bubble[N];
void ran();
clock_t start, finish;
double duration;

void main() {
	
	ran();
	
	selection_sort(list, N);
	insertion_sort(list, N);
	bubble_sort(list, N);
}

void printArray(int arr[], int n, char* str) {
	int i;
	printf("%s = ", str);
	for (i = 0; i < n; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");
}

void printStep(int arr[], int n, int val) {
	int i;
	printf("  Step %2d = ", val);
	for (i = 0; i < n; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");
}
void selection_sort(int list_selectiont[], int n) {
	int i, j, least, tmp;
	start = clock();
	for (i = 0; i < n - 1; i++) {xor
		least = i;
		for (j = i + 1; j < n; j++) {
			if (list_selection[j] < list_selection[least]) {
				least = j;
			}
		}
		SWAP(list_selection[i], list_selection[least], tmp);
		
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("선택정렬%f 초입니다\n", duration);
}

void insertion_sort(int list_insertiont[], int n) {
	int i, j, key;
	start = clock();
	for (i = 1; i < n; i++) {
		key = list_insertiont[i];
		for (j = i - 1; j > 0 && list_insertion[j] > key; j--) {
			list_insertion[j + 1] = list_insertion[j];
		}
		list_insertion[j + 1] = key;
		
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("삽입정렬 %f 초입니다\n", duration);
	
}

void bubble_sort(int list_bubble[], int n) {
	int i, j, bChanged, tmp, count=0;
	start = clock();
	for (i = n - 1; i > 0; i--) {
		bChanged = 0;
		for (j = 0; j < i; j++) {
			if (list_bubble[j] > list_bubble[j + 1]) {
				SWAP(list_bubble[j], list_bubble[j + 1], tmp);
				bChanged = 1;
			}
		}
		if (!bChanged) {
			break;
		}
		
	}
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("버블정렬 %f 초입니다\n", duration);
	

}

void ran() {

	int i;

	srand((unsigned)time(NULL));      // 초기화

	for (i = 0; i < N; i++) {
		n = rand();
		list[i] = n;
		list_selection[i] = n;
		list_insertion[i] = n;
		list_bubble[i] = n;
	}


	return list;
}