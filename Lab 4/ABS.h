#pragma once
#include <iostream>
//#include "leaker.h"

template <typename T>
class ABS {
private:
	float scaleFactor = 2.0f;
	unsigned int size = 0;
	unsigned int capacity = 1;
	T *typeArray;
public:
	//Constructors
	ABS() {
		typeArray = new T[capacity];
	}
	ABS(unsigned int passedCapacity) {
		capacity = passedCapacity;
		typeArray = new T[capacity];
	}
	//Copy constructor
	ABS(const ABS &d) {
		scaleFactor = d.scaleFactor;
		size = d.size;
		capacity = d.capacity;
		typeArray = new T[capacity];

		for (unsigned int i = 0; i < size; i++) {
			typeArray[i] = d.typeArray[i];
		}
	}
	//Assignment Operator
	ABS& operator=(const ABS &d) {
		scaleFactor = d.scaleFactor;
		size = d.size;
		capacity = d.capacity;
		typeArray = new T[capacity];

		for (unsigned int i = 0; i < size; i++) {
			typeArray[i] = d.typeArray[i];
		}
		return *this;
	}
	//Destructor
	~ABS() {
		delete[] typeArray;
	}
	//Member functions
	void push(const T& value) {
		if (capacity < size + 1) {
			capacity = capacity * scaleFactor;

			T* tempArray = new T[capacity];

			for (unsigned int i = 0; i < size; i++) {
				tempArray[i] = typeArray[i];
			}
			delete[] typeArray;
			typeArray = tempArray;
		}
		typeArray[size++] = value;
	}
	T pop() {
		if (size != 0 && capacity != 1) {
			T tempVal = typeArray[size - 1];
			size--;

			if ((capacity / scaleFactor) > size) {
				capacity = capacity / scaleFactor;
				T* tempArray = new T[capacity];
				for (unsigned int i = 0; i < size; i++) {
					tempArray[i] = typeArray[i];
				}
				delete[] typeArray;
				typeArray = tempArray;
			}
			return tempVal;
		}
		else {
			throw - 1;
		}
	}
	T peek() {
		if (size < 1) {
			throw - 1;
		}
		return typeArray[size - 1];
	}
	unsigned int getSize() /*const*/ {
		return size;
	}
	unsigned int getMaxCapacity() /*const*/ {
		return capacity;
	}
	T *getData() {
		return typeArray;
	}

};
