#include <iostream>

using namespace std;

int array_result_min(int A[], int i, int min, int key) {
	if (A[i] < min)
	{
		key = i;
		min = A[i];
	}
	i++;
	if (i < 10) {
		key = array_result_min(A, i, min, key);
	}
	return key;
}
int array_result_max(int A[], int i, int max, int key) {
	if (A[i] > max)
	{
		key = i;
		max = A[i];
	}
	i++;
	if (i < 10) {
		key = array_result_max(A, i, max, key);
	}
	return key;
}

int array_result_avr(int A[], int i, int max, int key, int min) {
	if (A[i] < max || A[i] > min)
	{
		key = (max + min) / 2;
	}
	i++;
	if (i < 10) {
		key = array_result_avr(A, i, max, min, key);
	}
	return key;
}

int output(int A[], int i, float avr) {
	cout << "[" << i << "] " << A[i] << "   ";
	i++;
	if (i < 10) {
		output(A, i, avr);
	}
	return 1;
}
int main() {
	int A[10];
	for (int i = 0; i < 10; i++) {
		A[i] = rand() % 20 - 40;
	}
	int max = A[0];
	int min = A[0];
	float avr = 0;
	int i = 0;
	int key = 0;
	cout << "Result(min): " << array_result_min(A, i, min, key) << endl;
	cout << "Result(max): " << array_result_max(A, i, max, key) << endl;
	cout << "Result(avr): " << array_result_avr(A, i, max, min, key) << endl;
	cout << "Array: " << output(A, 0, avr) << endl;
	return 0;
}