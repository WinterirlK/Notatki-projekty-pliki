#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

int partition (int* array, int size);
void sort (int* array, int size);
void sort2 (int* array, int size);
void swap (int* a, int* b);

void printa(int* array, int size);

int main(){
	int arr[10] = {3, 5, 23, 7, -2, 3, 90, 34, 6, 7};
	sort2(arr, 10);
	printa(arr, 10);
	
	return 0;
}

int partition (int* array, int size){
	int pivot = array[size-1];
	int i=-1;

	for (int j=0; j<size; j++){
		if (array[j] < pivot){
			i++;
			swap(array+i, array+j);
		}
	}
	i++;
	swap(array+i, array+size-1);

	return i; 
}

void sort(int* array, int size){
	if (size > 1){
		int q = partition(array, size); //id of selected element
		//printa(array, size);
		sort(array, q);
		sort(array+q+1, size-q-1);
	}
}

void sort2(int* array, int size){
	struct stack* s = init_stack(4);
	int p, r, q;
	push(s, 0); push(s, size);
	while(s->top > 0){
		r = pop(s);
		p = pop(s);
		q = partition(array+p, r);

		if (q > 1){
			push(s, p);
			push(s, q);
		}
		if (q+2 < r){
			push(s, q+1);
			push(s, size-q-1);
		}
	}
}

void swap (int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void printa(int* array, int size){
	for (int i=0; i<size; i++)
		printf("%d ", array[i]);
	putchar('\n');
}