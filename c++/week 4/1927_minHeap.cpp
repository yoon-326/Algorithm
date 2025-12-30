#include <iostream>

using namespace std;

void push_x(int heap[], int x);
void find_min(int heap[]);

const int MAX_SIZE = 100001;

int heap[MAX_SIZE];
int heap_size = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x; 
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		(x == 0) ? find_min(heap) : push_x(heap, x);
	}

	return 0;
}

void find_min(int heap[]) {
	if (heap_size == 0) {
		cout << 0 << "\n";
	}
	else {
		cout << heap[1] << "\n";

		int last = heap[heap_size--];
		int min = 2, index = 1;
		while (min <= heap_size) {
			if (min + 1 <= heap_size && heap[min] > heap[min + 1]) {
				min++;
			}
			if (last <= heap[min]) break;
			heap[index] = heap[min];
			index = min;
			min *= 2;
		}
		heap[index] = last;
	}
}

void push_x(int heap[], int x) {
	// 왼쪽노드: 부모노드 인덱스 * 2, 오른쪽노드: 부모노드 * 2 + 1
	int index = ++heap_size;
	while (index != 1 && heap[index / 2] > x) {
			heap[index] = heap[index / 2];
			index /= 2;
	}
	heap[index] = x;
}