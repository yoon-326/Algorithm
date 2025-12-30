#include <iostream>

using namespace std;

void push_x(int heap[], int x);
void find_max(int heap[]);

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
		(x == 0) ? find_max(heap) : push_x(heap, x);
	}

	return 0;
}

void find_max(int heap[]) {
	if (heap_size == 0) cout << 0 << "\n";

	else {
		cout << heap[1] << "\n";

		int last = heap[heap_size--];
		int child = 2, parent = 1;
		while (child <= heap_size) {
			if (heap[child + 1] > heap[child] && child + 1 <= heap_size) child++;
			if (last >= heap[child]) break;
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
		heap[parent] = last;
	}
}

void push_x(int heap[], int x) {
	// 왼쪽노드: 부모노드 인덱스 * 2, 오른쪽노드: 부모노드 * 2 + 1
	int child = ++heap_size;
	while (heap[child / 2] < x && child / 2 >= 1) {
		int parent = child / 2;
		heap[child] = heap[parent];
		child = parent;
		parent /= 2;
	}
	heap[child] = x;
}