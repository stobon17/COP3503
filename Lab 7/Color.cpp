#include "Color.h"
#include <vector>
#include <string>
using namespace std;

Color::Color() {
}

void Color::SetValue(int p_value) {
	value = p_value;
	red = (p_value >> 16) & 255; //Shift 16 right this defines the red region
	green = (p_value >> 8) & 255;//Shift 8 right this defines green
	blue = (p_value) & 255;//no shift blue 0-8
}

void Color::SetName(const char *p_name) {
	name = p_name;
}

unsigned char Color::GetR() const {
	return red;
}

unsigned char Color::GetG() const {
	return green;
}

unsigned char Color::GetB() const {
	return blue;
}

string Color::GetHexValue() const {
	string hexString = "0x" + CharToString(red) +
		CharToString(green) +
		CharToString(blue);
	return hexString;
}

string Color::GetName() const {
	return name;
}

string Color::CharToString(unsigned char p_color) const {
	unsigned char firstChar = p_color / 16;
	unsigned char secondChar = (p_color % 16);

	char char1 = CharToHexChar(firstChar);
	char char2 = CharToHexChar(secondChar);

	vector<char> result = { char1, char2 };
	string stringResult(result.begin(), result.end());

	return stringResult;
}

char Color::CharToHexChar(unsigned char character) const {
	if (9 < character && character < 16) {
		return 65 + character - 10;
	}
	else {
		return character + '0';
	}
}