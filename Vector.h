#pragma once
#include "iostream"
using namespace std;
const int factor = 5;

class Vector {
private:
	double * data = nullptr;
	int capacity = 0;
	int len = 0;
public:
	int getCapacity() {
		return capacity;
	}
	static int countRepackPopBack;
	static int countRepackPushBack;

	Vector(int n,double value=0): capacity(factor*n), len(n){
		data = new double[this->capacity];
		for (int i = 0; i < len; i++) data[i] = value;
	}
	Vector(const Vector & a) : capacity(a.capacity), len(a.len) {
		data = new double[this->capacity];
		for (int i = 0; i < this->len; i++) data[i] = a[i];
	}
	double & operator[](int index) const{
		return data[index];
	}
	Vector & operator=(const Vector& a) {
		this->capacity = a.capacity;
		this->len = a.len;
		delete[] data;
		data = new double[capacity];
		for (int i = 0; i < capacity; i++) data[i] = a[i];
		return *this;
	}
	void pushBack(double a) {
		if (len < capacity) {
			this->data[len++] = a;
		}
		else {
			this->len += 1;
			this->capacity = len * factor;
			double * dataNew = new double[capacity];
			for (int i = 0; i < len-1; i++) {
				dataNew[i] = data[i];
			}
			dataNew[len - 1] = a;
			delete[] data;
			this->data = dataNew;
			countRepackPushBack++;
		}
	}
	void popBack() {
		if (len != 0) {
			data[len - 1] = -10000;
			len -= 1;
			double d1= ((len * factor + capacity / factor - 1) / (capacity / factor));
			bool flag = (((len * factor + capacity / factor - 1) / (capacity / factor)) < factor);
			if (flag) {
				this->capacity = len * factor;
				double* dataNew = new double[capacity];
				for (int i = 0; i < len; i++) dataNew[i] = data[i];
				delete[] data;
				data = dataNew;
				countRepackPopBack++;
			}
		}
		else throw "Incorrect size vecotr\n";
	}
	void erase(int pos){
		if (pos < len) {
			swap(data[len - 1], data[pos]);
			popBack();
		}
		else throw "Incorecct size\n";
	}
	void insert(int pos, double value) {
		this->len += 1;
			if (len < capacity) {
				double* dataNew = new double[capacity];
				int j = 0, i = 0;
				while (i < pos) dataNew[i++] = data[j++];
				dataNew[i++] = value;
				while (i < len) dataNew[i++] = data[j++];
				delete[] data;
				data = dataNew;
			}
			else {
				this->capacity = factor * len;
				double* dataNew = new double[capacity];
				int j = 0, i = 0;
				while (i < pos) dataNew[i++] = data[j++];
				dataNew[i++] = value;
				while (i < len) dataNew[i++] = data[j++];
				delete[] data;
				data = dataNew;
			}
	}
	int Size() const {
		return this->len;
	}
	bool empty() {
		if (this->Size() == 0) return 1;
		return 0;
	}
	void printVector() {
		cout << "(";
		for (int i = 0; i < len-1; i++) {
			cout << data[i] << ", ";
		}
		cout << data[len-1];
		cout << ")\n";
	}
	~Vector() {
		delete[] data;
	}
	void swap(double & a1, double & a2) {
		double tmp = a2;
		a2 = a1;
		a1 = tmp;
	}
};
