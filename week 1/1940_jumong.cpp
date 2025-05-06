#include <iostream>
#include <vector>

using namespace std;

int two_point(vector<int> arr, int low, int high, int M);
int sort(vector<int>& S);
void quicksort(vector<int>& S, int low, int high);
int partition(vector<int>& S, int low, int high);
void exchangesort(vector<int>& S, int low, int high);
void exchange(int& a, int& b);


int main() {
	int N, M;
	cin >> N >> M;

	int num;
	vector<int> arr;

	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}

	sort(arr);
	int count = two_point(arr, 0, N-1, M);

	cout << count;

	return 0;
}

int sort(vector<int>& S) {
	quicksort(S, 0, S.size() - 1);
	return 1;
}

void quicksort(vector<int>& S, int low, int high) {
	if (high - low > 5) {
		int pivot_index = partition(S, low, high);

		quicksort(S, low, pivot_index - 1);
		quicksort(S, pivot_index + 1, high);
	}

	else exchangesort(S, low, high);
}

int partition(vector<int>& S, int low, int high) {
	int pivot = S[low];
	int i = low;

	for (int j = low + 1; j <= high; j++) {
		if (S[j] < pivot) {
			i++;
			exchange(S[i], S[j]);
		}
	}
	exchange(S[i], S[low]);
	return i;
}

void exchangesort(vector<int>& S, int low, int high) {
	int i, j;
	for (i = low; i < high; i++) {
		for (j = i + 1; j <= high; j++) {
			if (S[j] < S[i]) exchange(S[i], S[j]);
		}
	}
}

void exchange(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int two_point(vector<int> arr, int low, int high, int M) {
	int count = 0;

	while (low < high) {
		int sum = arr[low] + arr[high];

		if (sum == M) {
			count++;
			low++; high--;
		}
		else if (sum < M) low++;
		else high--;
	}

	return count;
}