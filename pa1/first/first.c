#include <stdio.h>


int numberOfEvenNumbers(int array[], int length) {
	
	int i;
	int count = 0;
	
	for (i = 0; i < length; i++) {
		if (array[i] % 2 == 0) {
			count++;
		}
	}

	return count;
}

void sortAscending(int a[], int length) {
	
	int x;
	int y;
	int temp;
	for (x = 0; x < length; x++) {
		for (y = x + 1; y < length; y++) {
			if (a[x] > a[y]) {
				temp = a[x];
				a[x] = a[y];
				a[y] = temp;
			}
		}
	}
}

void sortDescending(int arr[], int size) {
	
	int a;
	int b;
	int temp;
	for (a = 0; a < size; a++) {
		for (b = a + 1; b < size; b++) {
			if (arr[a] < arr[b]) {
				temp = arr[a];
				arr[a] = arr[b];
				arr[b] = temp;
			}
		}
	}
}

int main(int argc, char **argv) {
	int i;
	int j;
	int k;
	/*int x;
	int y;
	int a;
	int b;*/
	int size;
	FILE *fptr;
	char *filename = argv[1];
	
	fptr = fopen(filename, "r");
	fscanf(fptr, "%d", &size);
	int arr[size];
	
	for (i = 0; i < size; i++) {
		fscanf(fptr, "%d", &arr[i]); 
	}
	
	int numEven = numberOfEvenNumbers(arr, size);
	int numOdd = size - numberOfEvenNumbers(arr, size);
	int evenArray[numEven];
	int oddArray[numOdd];
	
	
	int x = 0;
	int y = 0;
	int z;
	
	
	
	for (z = 0; z < size; z++) {
		
		if (arr[z] % 2 == 0) {
			evenArray[x] = arr[z];
			x++;
		} else {
			oddArray[y] = arr[z];
			y++;
		}
	
	}
	
	
	
	
	
	
	/*for (x = 0; x < numEven; x++) {
	
	}	*/
	
	
	/*
	for (x = 0; x < size; x++) {
		if (arr[x] % 2 == 0) {
			for (a = 0; a < numEven; a++) {
				if (evenArray[a] == 0) {
					break;
				}
				evenArray[a] = arr[i];
			}
		}
	}
	*/
	
	
	
	
	
	
	sortAscending(evenArray, numEven);
	sortDescending(oddArray, numOdd);
	
	
	/*	for (i = 0; i < numOdd; i++) {
		 printf("%d\t", oddArray[i]);
	 }
	*/
	
	
	
	
	int result[size];
	
	for (j = 0; j < numEven; j++) {
		result[j] = evenArray[j];
	}
	
	int index = 0;
	
	for (k = size - numOdd; k < size; k++) {
		result[k] = oddArray[index];
		index++;
	}
	
	
	
	
	
	
	
	/* ------------this prints result -------------*/
	/*for (i = 0; i < size; i++) {
		printf("%d\t", arr[i]);
	}
	*/
	 
	 
	 
	 
	 
	for (i = 0; i < size; i++) {
		 printf("%d\t", result[i]);
	 }
	 
	fclose(fptr);
	
	
	return 0;
}
