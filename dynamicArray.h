#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <algorithm>
#include <cassert>
#include <stdexcept>
using namespace std;

/*
 dynamicArray Interface:

    dynamicArray(int initCap = 0);  // constructor
    dynamicArray(const dynamicArray& other); // copy constructor
    T& getAt(size_t i);
    void print();
    size_t getSize() const;
	size_t getCap() const; // get capacity
	T& operator[] (size_t i) const;
    void append(T element); // insert an element at the end
    void insertAt(T element, size_t index);
    void insertFront(const T &element);
    void removeEnd();
    void removeAt(size_t index);
    void removeFront();
*/

template <typename T>
class dynamicArray {
	protected:
		size_t size = 0;
		size_t capacity = 5;
		T *array;

		void resize() {
			int s = size * 2;
			size_t newCap = max(s, 2);
			T *newArr = new T[newCap];

			for (int i = 0; i < std::min(capacity, newCap); i++) {
				newArr[i] = array[i];
			}

			delete[] array;
			capacity = newCap;
			array = newArr;
		}

        T binarySearch(T target, size_t i, size_t j) {      // O(log n)
            if (i >= j) return i;
            size_t m = (i + j) / 2;
            T x = getAt(m);
            if (x > target) return binarySearch(target, i, m-1);
            if (x < target) return binarySearch(target, m+1, j);
            return m;
        }

	public:
		dynamicArray(int initCap = 0) : capacity(initCap) {
			array = new T[capacity];
		}

		// copy constructor
		dynamicArray(const dynamicArray& other)
			: capacity(other.capacity), size(other.size) {

			array = new T[capacity];
			for(int i = 0; i < size; i++) {
				array[i] = other.array[i];
			}
		}

		T& getAt(size_t i) {
			assert(i < size && i >= 0);
			return array[i];
		}

		void print() {
			for(int i = 0; i < size; i++) {
				cout << array[i] << endl;
			}
		}

		size_t getSize() const {
			return size;
		}

		size_t getCap() const {
			return capacity;
		}

		// same as copy constructor
		dynamicArray& operator= (const dynamicArray &other) {
			if (this != &other) {
				delete[] array;
				capacity = other.capacity;
				size = other.size;
				array = new T[capacity];
				
				for (int i = 0; i < size; i++) {
					array[i] = other.array[i];
				}
			}
			
			return *this;
		}

		T& operator[] (size_t i) const {
			assert(i < size && i >= 0);

			return array[i];
		}

		void append(T element) {
			if (size == capacity) {
				resize();
			}
			array[size] = element;
			size++;
		}

		void insertAt(T element, size_t index) {
			if (size == capacity) {
				resize();
			}

            // shifting
			for (size_t i = size; i > index; i--) {
				array[i] = array[i-1];
			}
			array[index] = element;
			size++;
		}

		void insertFront(const T &element) {
			if (size == capacity) {
				resize();
			}
			for (size_t i = size; i > 0; i--) {
				array[i] = array[i-1];
			}

			array[0] = element;
			size++;
		}
		
		void removeEnd() {
			if (size > 0) {
				size--;
			}
		}

		void removeAt(size_t index) {
			assert(index < size && index >= 0);
			for (size_t i = 0; i < size - 1; i++) {
				array[i] = array[i - 1];
			}
			size--;
			if (size < capacity / 3) {
				resize();
			}
		}

		void removeFront() {
			for(int i = 0; i < size; i++) {
				array[i] = array[i+1];
			}
			size--;
			if (size < capacity / 3) {
				resize();
			}
		}

		~dynamicArray() {
			delete[] array;
		}
};

#endif
