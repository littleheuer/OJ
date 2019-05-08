#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N = 1e4 + 7;

int heap[MAX_N], p = 0;

typedef struct Data {
	int v, d;
} Data;

Data data[MAX_N];

bool cmp(Data x, Data y) {
	return x.d < y.d;
}

void push(int *heap, int val) {
	heap[++p] = val;
	int ind = p;
	while((ind >> 1) >= 1) {
		if(heap[ind] < heap[ind >> 1]) swap(heap[ind >> 1], heap[ind]), ind >>= 1;
		else break;
	}
}

void pop(int *heap) {
	heap[1] = heap[p];
	p--;
	int ind = 1, s = ind << 1;
	while(s <= p) {
		if(s < p && heap[s] > heap[s + 1]) s++;
		if(heap[s] < heap[ind]) {
			swap(heap[s], heap[ind]);
			ind = s, s <<= 1;
		}
		else break;
	}
}

int main() {
	int n;
	while(cin >> n) {
		for(int i = 1; i <= n; i++) cin >> data[i].v >> data[i].d;
		sort(data + 1, data + n + 1, cmp);
		for(int i = 1; i <= n; i++) {
			if(data[i].d > p) push(heap, data[i].v);
			else if(data[i].v > heap[1]) pop(heap), push(heap, data[i].v);
		}
		int ans = 0;
		while(p > 0) {
			ans += heap[1];
			pop(heap);
		}
		cout << ans << "\n";
	}
	return 0;
}
