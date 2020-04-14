#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <class T>
class Repo {
protected:
	vector <T> elem;
	
public:

	
	void addElem(T el) {
		this->elem.push_back(el);
	}

	void setRepo(vector <T> t)
	{
		this->elem = t;
	}

	vector<T> getAll() {
		return this->elem;
	}

	vector<T> getElem()
	{
		return this->elem;
	}
	
	

	int find(const T &e)
	{
		int index = 0;
		for (T crt : elem)
		{
			index++;
			
				return index;
		}
	}

	int size()
	{
		return elem.size();
	}
	
	
	//constr fara param
	Repo() 
	{

	}
	//destructor
	~Repo() 
	{
		this->elem.~vector();
	}
	Repo& operator=(const T& t)
	{
		if (this != &t)
		{
			this->setRepo(t.elem);
		}
		return *this;
	}
	
};