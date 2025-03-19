#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int arr[], int length);
void completeArray(int arr[], int length);
bool isExistInArray(int arr[], int lastIndex, int number);
int findMinElement(int arr[], int length);
int findMaxElement(int arr[], int length);
void printInfoAboutElement(int arr[], int length, int element);
bool isPrimeNumber(int number);

int main() {
	int const length = 6;
	int lotto[length];

	cout << "Random set of Lotto numbers: ";
	completeArray(lotto, length);
	printArray(lotto, length);

	cout << "Information about the minimum in the randomized set: " << endl;
	printInfoAboutElement(lotto, length, findMinElement(lotto, length));

	cout << "Information about the maximum in the randomized set: " << endl;
	printInfoAboutElement(lotto, length, findMaxElement(lotto, length));

	return 0;
}

void printArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << "   ";
	}
	cout << endl;
}

void completeArray(int arr[], int length) {
	srand(time(0));

	for (int i = 0; i < length; i++) {
		int randNumber = (rand() % 49) + 1;
		if (!isExistInArray(arr, i, randNumber)) {
			arr[i] = randNumber;
		}
		else {
			i--;
		}
	}
}

bool isExistInArray(int arr[], int lastIndex, int number) {
	for (int i = 0; i < lastIndex; i++) {
		if (arr[i] == number) {
			return true;
		}
	}
	return false;
}

int findMinElement(int arr[], int length) {
	int min = arr[0];
	for (int i = 1; i < length; i++) {
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	return min;
}

int findMaxElement(int arr[], int length) {
	int max = arr[0];
	for (int i = 1; i < length; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

void printInfoAboutElement(int arr[], int length, int element) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == element) {
			cout << "Number = " << element << endl;
			cout << "Position = " << (i + 1) << endl;
			cout << "Is it a prime number? " << (isPrimeNumber(element) ? "Yes" : "No") << endl;
			cout << endl;
			return;
		}
	}
}

bool isPrimeNumber(int number) {
	int deviders = 0;

	if (number < 1) {
		return false;
	}

	for (int i = 1; i <= number; i++) {
		if (number % i == 0) {
			deviders++;
		}
	}

	return deviders == 2;
}