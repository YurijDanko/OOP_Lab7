#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T>
class Vect {
public:
	vector<T> v;
	unsigned sizeofvect;

	Vect() {};
	Vect(unsigned a) {
		sizeofvect = a;
		for (int i = 0; i < a; i++) {
			v.push_back({});
		}
	};
	~Vect() {};
	void add(T elem) {
		v.push_back(elem);
		sizeofvect++;
	}
	friend ostream& operator << (ostream& os, Vect<T>& a) {
		if (a.sizeofvect == NULL) {
			return os;
		}
		os << "[ ";
		for (auto it = a.v.begin(); it != a.v.end()-1; it++) {
			os << *it << ", ";
		}
		os << *(a.v.end()-1) << " ]";
		return os;
	}
	
	friend istream& operator >> (istream& is, Vect<T>& a) {
		T elem;
		for (int i = 0; i < a.sizeofvect; i++) {
			is >> elem;
			a.v[i] = elem;
		}
		return is;
	}

	unsigned int ControlSumFunc() {
		unsigned int hash = 1;
		for (int i = 0; i < this->sizeofvect; i++) {
			for (unsigned int ch : this->v[i]) {
				hash += (unsigned int)ch;
			}
		}
		return hash; // 4294967010
	}
};

int main() {
	cout << "Enter amount of elems in int array: ";
	int size1; cin >> size1;
	Vect<int> intarr(size1);
	cout << endl << "Input in your int array elems: " << endl;
	cin >> intarr;
	cout << endl << "It is your int array: " << intarr << endl;
	cout << "Enter amount of elems in string array: ";
	int size2; cin >> size2;
	Vect<string> stringarr(size2);
	cout << endl << "Input in your string array elems: " << endl;
	cin >> stringarr;
	cout << endl << "It is your string array: " << stringarr << endl;

	cout << "ControlSum of string array: " << stringarr.ControlSumFunc() << endl;

	return 0;
}