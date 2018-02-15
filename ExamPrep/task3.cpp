#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int MAX_OFFSET = 64;

void insertionSort(int arr[], size_t size) {
	size_t temp;
	for (size_t i = 0; i < size; i++) {
		for (size_t j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
		}
	}
}

void printMatrix(int arr[][MAX_OFFSET], int rows, int collums) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < collums; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

int main() {
	int rows, collums;
	int matrix[MAX_OFFSET][MAX_OFFSET];
	
	cout << "Enters number of rows: ";
	cin >> rows;
	cout << "Enter number of collums: ";
	cin >> collums;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < collums; j++) {
			cout << "Enter matrix element: ";
			cin >> matrix[i][j];
		}
		insertionSort(matrix[i], collums);
	}
	printMatrix(matrix, rows, collums);

	int test;
	cout << "End reached" << endl;
	cin >> test;

	return 0;
}