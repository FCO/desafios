#include <stdio.h>

int get_parent(int node)    { return (node - 1) / 2; }
int get_left(int node)      { return (node * 2) + 1; }
int get_right(int node)     { return (node * 2) + 2; }

void dump(int heap[], int size) {
	/*
	for(int i = 0; i < size; i++)
		fprintf(stderr, "%d ", heap[i]);
	fprintf(stderr, "\n");
	*/
}

void swap(int heap[], int to, int from) {
	//fprintf(stderr, "%d[%d] <=> %d[%d]\n", to, heap[to], from, heap[from]);
	int tmp     = heap[to];
	heap[to]    = heap[from];
	heap[from]  = tmp;
}

void up(int heap[], int node) {
	if(node <= 0) return;
	int parent = get_parent(node);
	if(heap[node] > heap[parent]) {
		swap(heap, node, parent);
		up(heap, parent);
	}
}

void down(int heap[], int size, int node) {
	//fprintf(stderr, "down(heap, %d, %d)\n", size, node);
	int left = get_left(node);
	if(left >= size) return;
	int right = get_right(node);
	dump(heap, size);

	if(heap[left] > heap[right]) {
		while(heap[node] < heap[left]) {
			swap(heap, node, left);
			down(heap, size, left);
		}
	} else {
		while(heap[node] < heap[right]) {
			swap(heap, node, right);
			down(heap, size, right);
		}
	}
}

void array_to_heap(int heap[], int size) {
	/*
	for(int i = size - 1; i >= 0; i--) {
		up(heap, i);
	}
	*/
	for(int i = get_parent(size); i >= 0; i--) {
		down(heap, size, i);
	}
}

int pop(int heap[], int *size) {
	//fprintf(stderr, "pop(heap, %d)\n", *size);
	int head = heap[0];
	swap(heap, 0, --(*size));
	down(heap, *size, 0);
	return head;
}

void print_k_biggest(int heap[], int size, int k) {
	dump(heap, size);
	array_to_heap(heap, size);
	dump(heap, size);
	for(int i = 0; i < k; i++) {
		printf("-> %d\n", pop(heap, &size));
		//fprintf(stderr, " ===> "); dump(heap, size);
	}
}

int main() {
	int heap[] = {5,4,3,2,1,0,9,8,7,6};
	int size = 10, k = 3;

	print_k_biggest(heap, size, k);
}
