
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {
	template <class V>
	friend ostream& operator<<(ostream&, Array<V>& );
	public:
		//constructor
		Array();
		//destructor
		~Array();
		//other
		void add(const T&);
		T& operator[](int)const;
		T& get(int index);
		int getSize()const;
		bool isFull()const;

	private:
		int size;
		T* elements;

};
template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}
template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
void Array<T>::add(const T& t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

template <class T>
int Array<T>::getSize()const{
	return size;
}

template <class T>
bool Array<T>::isFull()const{
	return size >= MAX_ARR;
}

template<class T>
T& Array<T>::operator[](int index)const{
	if (index < 0 || index >= size) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
ostream& operator<<(ostream& out, Array<T>& arr){
	for (int i = 0; i < arr.getSize();++i){
		out << arr[i] << endl;
	}
	return out;
}
#endif
