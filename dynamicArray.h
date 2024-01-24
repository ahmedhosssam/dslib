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

        dynamicArray<T> buildArrForMSort(dynamicArray<T>* arr, int start, int finish) {
            dynamicArray<T> newArr(finish-start);
            for (int i = start; i < finish; i++) {
                newArr.append(arr->getAt(i));
            }
            return newArr;
        }

	public:
		dynamicArray(int initCap = 0) : capacity(initCap) {
			array = new T[capacity];
		}

        /* sorting algorithms */
        
        void selection_sort() {
            for (int i = size-1; i >= 0; i--) {
                int max = i;
                for (int j = 0; j < i; j++) {
                    if (array[max] < array[j]) { max = j; }
                }
                // swap
                T temp = array[max];
                array[max] = array[i];
                array[i] = temp;
            }
        }

        void insertion_sort() {
            for (int i = 1; i < size; i++) {
                int j = i;
                while (j > 0 && array[j] < array[j-1]) {
                    // swap
                    T temp = array[j];
                    array[j] = array[j-1];
                    array[j-1] = temp;
                    j--;
                }
            }
        }

        void merge_sort(dynamicArray<T>* arr, int a, int b = -1) {
            if (b == -1) {
                b = arr->getSize();
            }

            if (1 < (b-a)) {
                int c = (a+b+1)/2;
                merge_sort(arr, a, c); // sort the left half
                merge_sort(arr, c, b); // sort the right half
                dynamicArray<T> L = buildArrForMSort(arr, a, c);
                dynamicArray<T> R = buildArrForMSort(arr, c, b);

                int i = 0;
                int j = 0;

                while (a < b) {
                    if ((j >= R.getSize()) || (i < L.getSize() && L.getAt(i) < R.getAt(j))) {
                        arr->insertAt(L.getAt(i), a, false);
                        i++;
                    } else {
                        arr->insertAt(R.getAt(j), a, false);
                        j++;
                        cout << "j = " << j << endl;
                    }
                    a++;
                }
            }
        }
        
        /* -------- end of sorting algorithms ----------*/

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

		void insertAt(T element, size_t index, bool shifting = true) {
			if (size == capacity) {
				resize();
			}

            if (!shifting) {
			    array[index] = element;
                size++;
                return;
            }
            // shifting
			for (size_t i = size; i > index; i--) {
				array[i] = array[i-1];
			}
			array[index] = element;
			size++;
		}

		void insertAt(T element) {
            this->append(element);
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
