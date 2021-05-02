#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE	100

typedef struct {
	int  x;
	int  y;
} Location2D;
typedef Location2D Element;

// 프로그램 4.1의 6~37행 추가 -------------------------------
Element data[MAX_QUEUE_SIZE];	// 요소의 배열
int	front;			// 전단
int	rear;			// 후단
int i = 0; j = 0;

					// 프로그램 3.1의 error()함수와 동일
void error(char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
};
// 큐의 주요 연산: 공통
void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear; }
int is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
int size() { return(rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue(Element val)
{
	if (is_full())
		error("  큐 포화 에러");
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	data[rear] = val;
}
Element dequeue()
{
	if (is_empty())
		error("  큐 공백 에러");
	front = (front + 1) % MAX_QUEUE_SIZE;
	return data[front];
}
Element peek()
{
	if (is_empty())
		error("  큐 공백 에러");
	return data[(front + 1) % MAX_QUEUE_SIZE];
}


// 프로그램 4.2의 3~28행 추가 -------------------------------
void init_deque() { init_queue(); }
void add_rear(Element val) { enqueue(val); }
Element delete_front() { return dequeue(); }
Element get_front() { return peek(); }

void add_front(Element val)
{
	if (is_full())
		error("  덱 포화 에러");
	data[front] = val;
	front = (front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}
Element delete_rear()
{
	int prev = rear;
	if (is_empty())
		error("  덱 공백 에러");
	rear = (rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return data[prev];
}
Element get_rear()
{
	if (is_empty())
		error("  덱 공백 에러");
	return data[rear];
}


#define	MAZE_SIZE 6
char map[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1' },
	{ 'e', '0', '1', '0', '0', '1' },
	{ '1', '0', '0', '0', '1', '1' },
	{ '1', '0', '1', '0', '1', '1' },
	{ '1', '0', '1', '0', '0', 'x' },
	{ '1', '1', '1', '1', '1', '1' },
};

Location2D getLocation2D(int x, int y) {
	Location2D p;
	p.x = x;
	p.y = y;
	return p;
}
int is_valid(int x, int y) {
	if (x < 0 || y < 0 || x >= MAZE_SIZE || y >= MAZE_SIZE) return 0;
	else return map[y][x] == '0' || map[y][x] == 'x';
}
int DFS()
{
	int x, y;
	Location2D here;

	init_deque();
	add_rear(getLocation2D(i, j));
	printf("DFS: ");
	while (is_empty() == 0) {
		here = delete_rear();
		printf("(%2d,%2d)", here.x, here.y);
		x = here.x;
		y = here.y;
		if (map[y][x] == 'x') return 1;
		else {
			map[y][x] = '.';
			if (is_valid(x - 1, y)) add_rear(getLocation2D(x - 1, y));
			if (is_valid(x + 1, y)) add_rear(getLocation2D(x + 1, y));
			if (is_valid(x, y - 1)) add_rear(getLocation2D(x, y - 1));
			if (is_valid(x, y + 1)) add_rear(getLocation2D(x, y + 1));
		}
	}
	return 0;
}

int BFS()
{
	int x, y;
	Location2D here;

	init_deque();
	add_rear(getLocation2D(i, j));
	printf("BFS: ");
	while (is_empty() == 0) {
		here = delete_front();
		printf("(%2d,%2d)", here.x, here.y);
		x = here.x;
		y = here.y;
		if (map[y][x] == 'x') return 1;
		else {
			map[y][x] = '.';
			if (is_valid(x - 1, y)) add_rear(getLocation2D(x - 1, y));
			if (is_valid(x + 1, y)) add_rear(getLocation2D(x + 1, y));
			if (is_valid(x, y - 1)) add_rear(getLocation2D(x, y - 1));
			if (is_valid(x, y + 1)) add_rear(getLocation2D(x, y + 1));
		}
	}
	return 0;
}

int findLocation(i, j) {
	for (i = 0; i < MAX_QUEUE_SIZE; i++) {
		for (j = 0; j < MAX_QUEUE_SIZE; j++) {
			if (map[i][j] == 'e') {
				return 0;
			}
		}
	}

	return 0;
}

int main()
{
	findLocation(i, j);
	//printf("->%s\n", DFS() ? "성공" : "실패");
	printf("->%s\n", BFS() ? "성공" : "실패");

	system("pause");
	return 0;
}