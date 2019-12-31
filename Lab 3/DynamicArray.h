#pragma once
//#include "leaker.h"
using namespace std;

template <typename T>
class DynamicArray {
private:
	unsigned int size;
	unsigned int capacity;
	T *data;
	
public:
	// Accessors
	unsigned int GetCapacity() const;
	unsigned int GetSize() const;
	const T* GetData() const;
	
	//Constructors
	DynamicArray();
	DynamicArray(unsigned int capacity);
	//Trilogy of Evil
	DynamicArray(const DynamicArray &d);
	DynamicArray &operator=(const DynamicArray &d);
	~DynamicArray();
	
	const T &operator[](unsigned int indexVal) const;
	T & operator[](unsigned int indexVal);

	const T &At(unsigned int indexVal) const;
	T &At(unsigned int indexVal);

	//Member functions
	void Add(const T &data);
	void Resize(unsigned int newArraySize);
	void Remove(unsigned int indexVal);
};

template <typename T>
unsigned int DynamicArray<T>::GetCapacity() const {
	return capacity;
}

template <typename T>
unsigned int DynamicArray<T>::GetSize() const {
	return size;
}

template <typename T>
const T* DynamicArray<T>::GetData() const {
	return data;
}

template <typename T>
DynamicArray<T>::DynamicArray() {
	size = 0;
	capacity = 0;
	data = nullptr;
}

template <typename T>
DynamicArray<T>::DynamicArray(unsigned int capacity) {
	size = 0;
	this->capacity = capacity;
	data = new T[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &d) {
	this->capacity = d.capacity;
	this->size = d.size;
	data = new T[capacity];
	for (unsigned int i = 0; i < size; i++) {
		this->data[i] = d.data[i];
	}
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T> &d) {
	if (this != &d) {
		delete[] data;
		this->size = d.size;
		this->capacity = d.capacity;

		data = new T[capacity];
		for (unsigned int i = 0; i < size; i++) {
			this->data[i] = d.data[i];
		}
	}
	return *this;
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] data;
}

template <typename T>
const T& DynamicArray<T>::operator[](unsigned int indexVal) const {
	if (indexVal >= size) {
		throw "Error: Invalid index";
	}
	return data[indexVal];
}

template <typename T>
T & DynamicArray<T>::operator[](unsigned int indexVal) {
	if (indexVal >= size) {
		throw "Error: Invalid index";
	}
	return data[indexVal];
}

template <typename T>
const T& DynamicArray<T>::At(unsigned int indexVal) const {
	if (indexVal >= size){
		throw "Error: Invalid index";
	}
	return data[indexVal];
}

template <typename T>
T& DynamicArray<T>::At(unsigned int indexVal) {
	if (indexVal >= size) {
		throw "Error: Invalid index";
	}
	return data[indexVal];
}

template <typename T>
void DynamicArray<T>::Add(const T &data) {
	if (capacity == size) {
		this->Resize(capacity + 1);
	}
	this->data[size] = data;
	size++;
}

template <typename T>
void DynamicArray<T>::Resize(unsigned int newArraySize) {
	cout << "Resizing... old capacity: " << capacity << " New capacity: " << newArraySize << endl;

	T* tempArray = new T[capacity];

	for (unsigned int i = 0; i < size; i++) {
		tempArray[i] = data[i];
	}

	delete[] data;
	data = new T[newArraySize];
	unsigned int addCounter = 0;
	for (unsigned int i = 0; i < newArraySize && i < size; i++) {
		data[i] = tempArray[i];
		addCounter++;
	}
	delete[] tempArray;
	capacity = newArraySize;
	size = addCounter;
}

template <typename T>
void DynamicArray<T>::Remove(unsigned int indexVal) {
	if (indexVal >= size) {
		throw "Error! Invalid index";
	}
	else if (indexVal == 0) {
		throw "Error! Invalid index";
	}
	for (unsigned int i = indexVal; i < size; i++) {
		data[i] = data[i + 1];
	}
	size--;
}