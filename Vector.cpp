#include "Vector.h"
int Vector::countRepackPopBack=0;
int Vector::countRepackPushBack=0;

int main() {
	Vector a(200000,4);
	Vector b(200000,3);
	cout << "Size a - " << a.Size() << "   " << "Size b - " << b.Size() << "\n";
	try {
		for (int i = 0; i <150000; i++) a.erase(1);
		cout << "The number of repackages during the erase function " << Vector::countRepackPopBack << "     The number of item deletions - 150000 " << "\n";
		for (int i = 0; i < 1000000; i++) b.pushBack(2);
		cout << "The number of repackages during the pushBack function " << Vector::countRepackPushBack << "   The number of element inserts - 1000000 " << "\n";
	}
	catch (const char* str) {
		cout << str;
	}
	return 1;
}