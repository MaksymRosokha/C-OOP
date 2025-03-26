#include <iostream>
#include <vector>

using namespace std;

void completeVector(vector<string>* vs);
bool isPresent(vector<string> vs, string st);
void printVector(vector<string> vs);
int getAverageLength(vector<string> vs);

int main()
{
	vector <string> userStrings;
	cout << "Enter your strings. To stop entering, enter an existed string." << endl;
	completeVector(&userStrings);
	printVector(userStrings);
	cout << "Average length of entered strings is: " << getAverageLength(userStrings);

	return 0;
}

void completeVector(vector<string>* vs) {
	string userStr;
	while(true) {
		cout << "Enter a string: ";
		cin >> userStr;
		if (isPresent(*vs, userStr)) {
			break;
		}
		vs->push_back(userStr);
	}
}

bool isPresent(vector<string> vs, string st) {
	if (vs.empty()) {
		return false;
	}
	return vs.back() == st;
}

void printVector(vector<string> vs) {
	for (string str : vs) {
		cout << str << " : " << str.size() << endl;
	}
}

int getAverageLength(vector<string> vs) {
	float sumOfLengths = 0;
	float averageLengthFloat;
	int averageLengthInt;
	int intPart;
	float floatPart;


	for (string str : vs) {
		sumOfLengths += str.size();
	}

	averageLengthFloat = sumOfLengths / vs.size();
	intPart = int(averageLengthFloat);
	floatPart = averageLengthFloat - intPart;

	if (floatPart < 0.5) {
		averageLengthInt = intPart;
	}
	else {
		averageLengthInt = intPart + 1;
	}

	return averageLengthInt;
}