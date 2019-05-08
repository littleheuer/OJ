#include<stdio.h>
#include<stdlib.h> 
#include<algorithm>
using namespace std; 
/***
#define swap(a, b) {\
	__typeof(a) __tmp = a;\
	a = b, b = __tmp;\
}
***/
typedef struct Data {
	int v, d;
} Data;

typedef struct Heap {
	int *data;
	int size, n;
} Heap;

Heap *init(int size) {
	Heap *h = (Heap*)malloc(sizeof(Heap));
	h->size = size + 1;
	h->n = 0;
	h->data = (int*)malloc(sizeof(int) * h->size);
	return h;
}

#define V(x) h->data[x]

void up(Heap *h, int ind) {
	while(ind >> 1 >= 1) {
		if(V(ind) < V(ind >> 1)) {
			swap(V(ind), V(ind >> 1));
			ind >>= 1;
		} else break;
	}
}

void down(Heap *h, int ind) {
	int s = ind << 1;
	while(s <= h->n) {
		if(s < h->n && V(s) > V(s + 1)) s++;
		if(V(s) < V(ind)) {
			swap(V(s), V(ind));
			ind = s, s <<= 1;
		} else break;
	}
}

int empty(Heap *h) {
	return h->n == 0;
}

int top(Heap *h) {
	return V(1);
}

void push(Heap *h, int k) {
	if(h->size - 1 == h->n) return ;
	V(++(h->n)) = k;
	up(h, h->n);
}

void pop(Heap *h) {
	if(empty(h)) return ;
	V(1) = V(h->n);
	h->n--;
	down(h, 1);
}

void clear(Heap *h) {
	if(h == NULL) return ;
	free(h->data);
	free(h);
}

//从小到大 ,大顶堆 
void sort(Data *d, int n) {
	d -= 1;
	for(int i = n; i >= 2; i--) {
		int ind = i;
		while((ind >> 1) >= 1) {
			if(d[ind].d > d[ind >> 1].d) {
				swap(d[ind], d[ind >> 1]);
				ind >>= 1;
			} else break;
		}
	}
	for(int i = n; i >= 2; i--) {
		swap(d[1], d[i]);
		int ind = 1, s = ind << 1;
		while(s < i) {
			if(s < (i - 1) && d[s].d < d[s + 1].d) s++;
			if(d[s].d > d[ind].d) {
				swap(d[ind], d[s]);
				ind = s, s <<= 1;
			} else break;
		}
	}
}

long long cal(int n) {
	Heap *h = init(n);
	Data *d = (Data*)malloc(sizeof(Data) * n);
	for(int i = 0; i < n; i++) {
		int v, dl;
		scanf("%d%d", &v, &dl);
		d[i].v = v, d[i].d = dl;
	}
	sort(d, n);
	for(int i = 0; i < n; i++) {
		if(d[i].d > h->n) {
			push(h, d[i].v);
		} else if(d[i].v > top(h)){
			pop(h);
			push(h, d[i].v);
		}
	}
	long long ans = 0;
	for(int i = h->n; i >= 1; i--) {
		ans += top(h);
		pop(h);
	}
	clear(h);
	free(d);
	return ans;
}

int main() {
	int n;
	long long ans = 0;
	while(~scanf("%d", &n)) {
		ans = cal(n);
		printf("%lld\n", ans);
	}
	return 0;
}
