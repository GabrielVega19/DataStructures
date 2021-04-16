

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE (10)

//Quick Sort: select an element to use as the pivot. Then partition the list so that all the elements on the list that are less than are on the left
// and all the elements that are greater are on the right side then quick sort the two halves. Use two indecators one on the left that scans for things to
// go on the right and one on the right that lookds for things to go on the left and then swap the two elements. If the scanners meet then swap the pivot in. 
void quick_sort(int numbers[], int size);

//shell sort: to h sort the list with decreasing values of h untill  h = 1: h sort is insertion sort but insead of comparing values that are 1 away you compare 
//values h away
void shell_sort(int numbers[], int size);

//insertion sort: assume the first element is a sorted list then go to the nest element shifting it to the left untill its in its proper place and then you have
// a sorted list of 2 elements and keep going worse than selection sort with large amounts of numbers and sometime better with smaller amonunt of numbers
void insertion_sort(int numbers[], int size);

//heap sort: heapify the array then remove the max n-1 times
//heapify means call fix down on all the elements in the array but ignore the leaf nodes 
void heap_sort(int numbers[], int size);
void heapify(int numbers[], int size);
void remove_max(int numbers[], int* pSize);
void fix_down(int numbers[], int size, int index);

//Selection Sort:starting at ith element where i is 0 look through the list from element i and swap the smallest element into the ith position do this for increasing 
//values of i n-1 times better than bubble sort
void selection_sort(int numbers[], int size);
int find_smallest_index(int numbers[], int start, int size);


//Bubble Sort: Compare adjasent elements starting at the begginging of the 
//list and switch them if they are out of order do this for n-1 times
void bubble_sort(int numbers[], int size);
void supposidly_improved_bubble_sort(int numbers[], int size);
void swap(int* x, int* y);

int number_of_assignments;
int number_of_comparisons;

int main(int argc, char* argv[]) {
	int* numbers;
	int* temp;
	int i;
	srand(time(0));

	numbers = (int*)malloc(sizeof(int) * SIZE);
	if (numbers == NULL) {
		exit(1);
	}
	temp = (int*)malloc(sizeof(int) * SIZE);
	if (temp == NULL) {
		exit(1);
	}

	int size = SIZE;



	for (i = 0; i < size; i++) {

		numbers[i] = temp[i] = rand();
	}

	quick_sort(temp, size);

	//printf("******\n");

	//number_of_assignments = 0;
	//number_of_comparisons = 0;
	//bubble_sort(numbers, size);
	//printf("assignments: %d ", number_of_assignments);
	//printf("comparisons: %d\n", number_of_comparisons);

	//number_of_assignments = 0;
	//number_of_comparisons = 0;
	//supposidly_improved_bubble_sort(temp, size);
	//printf("assignments: %d ", number_of_assignments);
	//printf("comparisons: %d\n", number_of_comparisons);

	for (i = 0; i < size; i++) {
		printf("%d\n", temp[i]);
	}

	free(numbers);
	free(temp);
	return 0;
}

void bubble_sort(int numbers[], int size) {
	int i;
	int j;
	
	number_of_assignments++;//for loop initialization
	for (i = 0; i < size - 1; i++) {
		number_of_comparisons++;

		number_of_assignments++;
		for (j = 0; j < size - 1 - i; j++) {
			number_of_comparisons++;
			number_of_comparisons++;
			if (numbers[j] > numbers[j + 1]) {
				swap(&numbers[j], &numbers[j + 1]);
			}
			number_of_assignments++;
		}
		number_of_assignments++;
	}
	number_of_comparisons++; //last for loop comparison
	return;
}

void supposidly_improved_bubble_sort(int numbers[], int size) {
	int i = 0;
	int j;
	int something_swapped = 1;

	while (something_swapped) { // do this for n-1 times this is one bubble sort
		number_of_comparisons++;
		something_swapped = 0;
		number_of_assignments++;
		number_of_assignments++;
		for (j = 0; j < size - 1 - i; j++) {// compare adjacent elements and swap if out of order
			number_of_comparisons++;
			number_of_comparisons++;
			if (numbers[j] > numbers[j + 1]) {
				swap(&numbers[j], &numbers[j + 1]);
				something_swapped = 1;
				number_of_assignments++;
			}
			number_of_assignments++;
		}
		number_of_comparisons++;
		i++;
		number_of_assignments++;
	}
	number_of_comparisons++;
}

void swap(int* x, int* y) {
	number_of_assignments += 3;

    int temp = *x;
	*x = *y;
	*y = temp;
}

void selection_sort(int numbers[], int size) {
	int i; 
	
	for (i = 0; i < size - 1; i++) {
		swap(&numbers[i], &numbers[find_smallest_index(numbers, i, size)]);
	}
}

int find_smallest_index(int numbers[], int start, int size) {
	int i;
	int min_index = start;

	for (i = start + 1; i < size; i++) {
		if (numbers[min_index] > numbers[i]) {
			min_index = i;
		}
	}
	return min_index;
}

void vanilla_insertion_sort(int numbers[], int size) {
	int i; 
	int j;

	for (i = 1; i < size; i++) {//do an insertion for each element after the first
		j = i;

		while (j > 0 && numbers[j] < numbers[j - 1]) {//while stil suposed to swap to the left
			swap(&numbers[j], &numbers[j - 1]);
			j--;
		}
	}
}

void insertion_sort(int numbers[], int size) {
	int i;
	int j;
	int temp;

	for (i = 1; i < size; i++) {//do an insertion for each element after the first
		j = i;
		temp = numbers[j];
		while (j > 0 && temp < numbers[j - 1]) {//while stil suposed to swap to the left
			numbers[j] = numbers[j - 1];
			j--;
		}
		numbers[j] = temp;
	}
}

void improved_insertion_sort(int numbers[], int size) {
	int i;
	int j;
	int temp;

	//sentinel improvement
	swap(&numbers[0], &numbers[find_smallest_index(numbers, 0, size)]);

	for (i = 1; i < size; i++) {//do an insertion for each element after the first
		j = i;
		temp = numbers[j];
		while (temp < numbers[j - 1]) {//while stil suposed to swap to the left
			numbers[j] = numbers[j - 1];
			j--;
		}
		numbers[j] = temp;
	}
}


//
//void bubble_sort(int numbers[], int size) {
//	int i;
//	int j;
//
//	for (i = 0; i < size - 1; i++) { // do this for n-1 times this is one bubble sort
//		for (j = 0; j < size - 1 - i; j++) {// compare adjacent elements and swap if out of order
//
//			if (numbers[j] > numbers[j + 1]) {
//				swap(&numbers[j], &numbers[j + 1]);
//			}
//		}
//	}
//	return;
//}
//
//void supposidly_improved_bubble_sort(int numbers[], int size) {
//	int i = 0;
//	int j;
//	int something_swapped = 1;
//
//	while (something_swapped) { // do this for n-1 times this is one bubble sort
//		something_swapped = 0;
//
//		for (j = 0; j < size - 1 - i; j++) {// compare adjacent elements and swap if out of order
//
//			if (numbers[j] > numbers[j + 1]) {
//				swap(&numbers[j], &numbers[j + 1]);
//				something_swapped = 1;
//			}
//		}
//	}
//	return;
//}


void shell_sort(int numbers[], int size) {
	int i;
	int j;
	int temp;

	int h = 1;
	while (h < size / 3) {
		h *= 2;
	}
	if (h > 1) {
		h = h - 1;
	}

	//h should be a third of the list to get started and less than half 2^k

	while (h > 0) {

		for (i = h; i < size; i++) {//do an insertion for each element after the first
			j = i;
			temp = numbers[j];
			while (j > h - 1 && temp < numbers[j - h]) {//while stil suposed to swap to the left
				numbers[j] = numbers[j - h];
				j -= h;
			}
			numbers[j] = temp;
		}
		h /= 2;
	}
}

void heap_sort(int numbers[], int size) {
	int i;
	int number_of_elements = size;
	heapify(numbers, size);

	for (i = 0; i < size - 1; i++) {
		remove_max(numbers, &number_of_elements);
	}
}

void heapify(int numbers[], int size) {
	int i;

	for (i = (size / 2) - 1; i >= 0; i--) {
		fix_down(numbers, size, i);
	}
}

void remove_max(int numbers[], int *pSize) {
	swap(&numbers[0], &numbers[*pSize - 1]);
	(*pSize)--;
	fix_down(numbers, *pSize, 0);
}

void fix_down(int numbers[], int size, int index) {
	int index_of_left_child = (index * 2) + 1;
	int index_of_right_child = (index * 2) + 2;
	int index_of_largest_child = -1;
	
	if (index_of_right_child < size) {
		index_of_largest_child = (numbers[index_of_left_child] > numbers[index_of_right_child]) ? index_of_left_child : index_of_right_child;
	}
	else if (index_of_left_child < size) {
		index_of_largest_child = index_of_left_child;
	}

	if (index_of_largest_child > 0) {
		if (numbers[index_of_largest_child] > numbers[index]) {
			swap(&numbers[index_of_largest_child], &numbers[index]);
			fix_down(numbers, size, index_of_largest_child);
		}
	}
}

void quick_sort(int numbers[], int size) {
	//select a pivot
	//option #1 pick a random pivot
	if (size > 1) {
		swap(&numbers[0], &numbers[rand() % size]);
	}

	//option #3 median of 3, pick 3 elemets somehow (most of the time random) and then use the middle one

	int index_of_pivot = 0;
	int index_of_left = index_of_pivot;
	int index_of_right = size - 1;

	//partition the list
	while (index_of_left < index_of_right) {
		
		//scan from the right
		while (index_of_left < index_of_right && numbers[index_of_right] >= numbers[index_of_pivot]) {
			index_of_right--;
		}

		//scan from the left 
		while (index_of_left < index_of_right && numbers[index_of_left] <= numbers[index_of_pivot]) {
			index_of_left++;
		}

		//if they did not meet then swap the elements and scan again 
		if (index_of_left < index_of_right) {
			swap(&numbers[index_of_left], &numbers[index_of_right]);
		}
	}

	if (index_of_left == index_of_right) {
		swap(&numbers[index_of_pivot], &numbers[index_of_right]);
		//quick sort the left half
		quick_sort(numbers, index_of_right);
		//quick sort the right half
		quick_sort(numbers + index_of_right + 1, size - index_of_right - 1);
	}

}