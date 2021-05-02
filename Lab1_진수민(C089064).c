//  Lab No.1 : 정수 최대값을 출력하는 프로그램
// 작성자: 503, 진수민(C089064)
// 날짜  : 2021년 3월 10일
// 100개의 임의로 정한 정수 중 최대값을 출력하는 프로그램.
//(단, 1차원 배열에 정수 값을 저장하고 최대값을 구한다.)

#include <stdio.h>

int n = 0;
void find_array_max(int list[], int n);

int main(void) {
    int list[100];

    for (int i = 0; i < 100; i++) {
        list[i] = i + 1;
    }

    find_array_max(list, n);

    return 0;
}

void find_array_max(int list[], int n) {
    for (int i = 0; i < 100; i++) {
        if (list[i] > n) {
            n = list[i];
        }
    }

    printf("최대값 : %d\n\n\n", n);

}