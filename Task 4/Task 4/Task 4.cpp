#include <iostream>
#include <vector>

using namespace std;

vector<int> sumSets(const vector<int>& set1, const vector<int>& set2);
vector<int> sumSets(const vector<int>& set1, const vector<int>& set2, const vector<int>& set3);
vector<int> differenceSets(const vector<int>& set1, const vector<int>& set2);
vector<int> differenceSets(const vector<int>& set1, const vector<int>& set2, const vector<int>& set3);
vector<int> commonPartOfSets(const vector<int>& set1, const vector<int>& set2);
vector<int> commonPartOfSets(const vector<int>& set1, const vector<int>& set2, const vector<int>& set3);

vector<string> sumSets(const vector<string>& set1, const vector<string>& set2);
vector<string> sumSets(const vector<string>& set1, const vector<string>& set2, const vector<string>& set3);
vector<string> differenceSets(const vector<string>& set1, const vector<string>& set2);
vector<string> differenceSets(const vector<string>& set1, const vector<string>& set2, const vector<string>& set3);
vector<string> commonPartOfSets(const vector<string>& set1, const vector<string>& set2);
vector<string> commonPartOfSets(const vector<string>& set1, const vector<string>& set2, const vector<string>& set3);

void printSet(const vector<int> &s);
void printSet(const vector<string> &s);
bool isPresent(const vector<int>& s, const int element);
bool isPresent(const vector<string>& s, const string element);

int main()
{
	vector<int> setN1 = { 1,2,3,4,5, };
	vector<int> setN2 = { 1,3,5,7,9, };
	vector<int> setN3 = { 1,4,7,10,13, };

	cout << "set 1 = ";
	printSet(setN1);
	cout << "set 2 = ";
	printSet(setN2);
	cout << "set 3 = ";
	printSet(setN3);
	
	cout << "Sum of set 1 and set 2 = ";
	printSet(sumSets(setN1, setN2));
	cout << "Sum of set 1, set 2 and set 3 = ";
	printSet(sumSets(setN1, setN2, setN3));
	cout << "Difference of set 1 and set 2 = ";
	printSet(differenceSets(setN1, setN2));
	cout << "Difference of set 1, set 2 and set 3 = ";
	printSet(differenceSets(setN1, setN2, setN3));
	cout << "Commot part of set 1 and set 2 = ";
	printSet(commonPartOfSets(setN1, setN2));
	cout << "Commot part of set 1, set 2 and set 3 = ";
	printSet(commonPartOfSets(setN1, setN2, setN3));


	cout << "\n\n";

	vector<string> setS1 = { "a", "b", "c", "d", "e",};
	vector<string> setS2 = { "a", "c", "e", "g", "i", };
	vector<string> setS3 = { "a", "d", "g", "j", "m", };

	cout << "set 1 = ";
	printSet(setS1);
	cout << "set 2 = ";
	printSet(setS2);
	cout << "set 3 = ";
	printSet(setS3);

	cout << "Sum of set 1 and set 2 = ";
	printSet(sumSets(setS1, setS2));
	cout << "Sum of set 1, set 2 and set 3 = ";
	printSet(sumSets(setS1, setS2, setS3));
	cout << "Difference of set 1 and set 2 = ";
	printSet(differenceSets(setS1, setS2));
	cout << "Difference of set 1, set 2 and set 3 = ";
	printSet(differenceSets(setS1, setS2, setS3));
	cout << "Commot part of set 1 and set 2 = ";
	printSet(commonPartOfSets(setS1, setS2));
	cout << "Commot part of set 1, set 2 and set 3 = ";
	printSet(commonPartOfSets(setS1, setS2, setS3));

	return 0;
}

void printSet(const vector<int> &s) {
	for (const int& i : s) {
		cout << i << ", ";
	}
	cout << endl;
}

void printSet(const vector<string> &s) {
	for (const string& i : s) {
		cout << i << ", ";
	}
	cout << endl;
}

bool isPresent(const vector<int>& s, const int element) {
	if (s.empty()) {
		return false;
	}
	for (const int& i : s) {
		if (element == i) {
			return true;
		}
	}
	return false;
}

bool isPresent(const vector<string>& s, const string element) {
	if (s.empty()) {
		return false;
	}
	for (const string& i : s) {
		if (element == i) {
			return true;
		}
	}
	return false;
}

vector<int> sumSets(const vector<int>& set1, const vector<int>& set2) {
	vector<int> s;

	for (const int& i : set1) {
		if (!isPresent(s, i)) {
			s.push_back(i);
		}
	}
	for (const int& i : set2) {
		if (!isPresent(s, i)) {
			s.push_back(i);
		}
	}

	return s;
}

vector<string> sumSets(const vector<string>& set1, const vector<string>& set2) {
	vector<string> s;

	for (const string& i : set1) {
		if (!isPresent(s, i)) {
			s.push_back(i);
		}
	}
	for (const string& i : set2) {
		if (!isPresent(s, i)) {
			s.push_back(i);
		}
	}

	return s;
}


vector<int> sumSets(const vector<int>& set1, const vector<int>& set2, const vector<int>& set3) {
	vector<int> s;

	for (const int& i : set1) {
		if (!isPresent(s, i)) {
			s.push_back(i);
		}
	}
	for (const int& i : set2) {
		if (!isPresent(s, i)) {
			s.push_back(i);
		}
	}
	for (const int& i : set3) {
		if (!isPresent(s, i)) {
			s.push_back(i);
		}
	}

	return s;
}

vector<string> sumSets(const vector<string>& set1, const vector<string>& set2, const vector<string>& set3) {
	vector<string> s;

	for (const string& i : set1) {
		if (!isPresent(s, i)) {
			s.push_back(i);
		}
	}
	for (const string& i : set2) {
		if (!isPresent(s, i)) {
			s.push_back(i);
		}
	}
	for (const string& i : set3) {
		if (!isPresent(s, i)) {
			s.push_back(i);
		}
	}

	return s;
}

vector<int> differenceSets(const vector<int>& set1, const vector<int>& set2) {
	vector<int> s;

	for (const int& i : set1) {
		if (!isPresent(set2, i)) {
			s.push_back(i);
		}
	}

	return s;
}

vector<string> differenceSets(const vector<string>& set1, const vector<string>& set2) {
	vector<string> s;

	for (const string& i : set1) {
		if (!isPresent(set2, i)) {
			s.push_back(i);
		}
	}

	return s;
}

vector<int> differenceSets(const vector<int>& set1, const vector<int>& set2, const vector<int>& set3) {
	vector<int> s;

	for (const int& i : set3) {
		if (!isPresent(sumSets(set1, set2), i)) {
			s.push_back(i);
		}
	}

	return s;
}

vector<string> differenceSets(const vector<string>& set1, const vector<string>& set2, const vector<string>& set3) {
	vector<string> s;

	for (const string& i : set3) {
		if (!isPresent(sumSets(set1, set2), i)) {
			s.push_back(i);
		}
	}

	return s;
}


vector<int> commonPartOfSets(const vector<int>& set1, const vector<int>& set2) {
	vector<int> s;

	for (const int& i : set1) {
		if (isPresent(set2, i)) {
			s.push_back(i);
		}
	}

	return s;
}

vector<string> commonPartOfSets(const vector<string>& set1, const vector<string>& set2) {
	vector<string> s;

	for (const string& i : set1) {
		if (isPresent(set2, i)) {
			s.push_back(i);
		}
	}

	return s;
}

vector<int> commonPartOfSets(const vector<int>& set1, const vector<int>& set2, const vector<int>& set3) {
	vector<int> s;

	for (const int& i : set1) {
		if (isPresent(set2, i) && isPresent(set3, i)) {
			s.push_back(i);
		}
	}

	return s;
}


vector<string> commonPartOfSets(const vector<string>& set1, const vector<string>& set2, const vector<string>& set3) {
	vector<string> s;

	for (const string& i : set1) {
		if (isPresent(set2, i) && isPresent(set3, i)) {
			s.push_back(i);
		}
	}

	return s;
}
