#pragma once
#include <string>
using namespace std;

class Color {
public:
	//Default Constructor
	Color();
	//Member Functions
	void SetValue(int value);
	void SetName(const char *name);
	unsigned char GetR() const; //Get Red
	unsigned char GetG() const; //Get Green
	unsigned char GetB() const; //Get Blue
	string GetHexValue() const;
	string GetName() const;
private:
	string name = "";
	int value = 0;
	unsigned char red = 0;
	unsigned char green = 0;
	unsigned char blue = 0;
	string CharToString(unsigned char p_color) const;
	char CharToHexChar(unsigned char character) const;
};