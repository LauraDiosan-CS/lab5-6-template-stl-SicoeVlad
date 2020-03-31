
#pragma once
#include <vector>
using namespace std;

template <class T>
class Repo {
protected:
	vector <T> elem;
	
public:
	//C
	void addElem(T el) {
		this->elem.push_back(el);
	}

	//R
	vector<T> getAll() {
		return this->elem;
	}

	//constr fara param
	Repo() {}
	//destructor
	~Repo() {
		this->elem.~vector();
	}
	
};