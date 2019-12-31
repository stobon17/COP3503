
#include "Functions.h"
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
void QuadraticRoot() {
	double a, b, c;
	cout << "Enter a, b, c: \n";
	cin >> a >> b >> c;
	double discrim = b * b - 4 * a * c;
	if (discrim < 0) {
		cout << "The equation has no real roots.";
	}
	else if (discrim > 0) {
		double r1 = (-b + sqrt(discrim)) / (2 * a);
		double r2 = (-b - sqrt(discrim)) / (2 * a);
		cout << "The equation has two roots: " << r1 << " and " << r2 << std::endl;
	}
	else //if discrim == 0
	{
		double r = -b / (2 * a);
		cout << "The equation has one root: " << r << std::endl;
	}
}

void GradeCalculator() {
	int numStudents;
	cout << "Enter the number of students: \n";
	cin >> numStudents;
	vector<int> scores;
	vector<char> grades;
	//cout << "Enter " << numStudents << " scores: " << endl;
	int best = -1;
	for (int i = 0; i < numStudents; i++) {
		int value;
		cin >> value;
		scores.push_back(value);
		if (best < scores.at(i)) {
			best = scores.at(i);
		}
	}
	for (int i = 0; i < numStudents; i++) {
		if (scores.at(i) >= (best - 10)) {
			grades.push_back('A');
		}
		else if (scores.at(i) >= (best - 20)) {
			grades.push_back('B');
		}
		else if (scores.at(i) >= (best - 30)) {
			grades.push_back('C');
		}
		else if (scores.at(i) >= (best - 40)) {
			grades.push_back('D');
		}
		else {
			grades.push_back('F');
		}
		cout << "Student " << (i + 1) << " - Score: " << scores.at(i) << ", Letter: " << grades.at(i) << endl;
	}
}
int getSize(long long number) {
	int digitCount = 0;
	while (number > 0) {
		number = number / 10;
		digitCount++;
	}
	return digitCount;
}
int getDigit(int number) {
	return (number / 10) + (number % 10);
}
int sumOfDoubleEvenPlace(long long number) {
	int sum = 0;
	while (number > 0) {
		int digit = (int)((number % 100) / 10);
		number = number / 100;
		sum += getDigit(2 * digit);
	}
	return sum;
}
int sumOfOddPlace(long long number) {
	int sum = 0;
	while (number > 0) {
		int digit = (int)(number % 10);
		number = number / 100;
		sum += getDigit(digit);
	}
	return sum;
}
long getPrefix(long long number, int numDigits) {
	int numberSize = getSize(number);
	int decimalMovements = numberSize - numDigits;
	while (decimalMovements-- > 0) {
		number = number / 10;
	}
	return number;
}
bool prefixMatched(long long number, int digit) {
	return getPrefix(number, getSize(digit)) == digit;
}
bool isValid(long long number) {
	int numSize = getSize(number);
	if (numSize > 16 || numSize < 13) {
		return false;
	}
	int sum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
	if (sum % 10 != 0) {
		return false;
	}
	if (prefixMatched(number, 4)) {
		return true;
	}
	if (prefixMatched(number, 5)) {
		return true;
	}
	if (prefixMatched(number, 37)) {
		return true;
	}
	if (prefixMatched(number, 6)) {
		return true;
	}
	return false;
}	
	void CreditCardValidator()
	{
		cout << "Enter a credit card number: " << endl;
		long long number;
		cin >> number;
		//cout << number << " is ";
		if (isValid(number)) {
			cout << number << " is valid." << endl;
		}
		else {
			cout << number << " is invalid.";
		}
	}


