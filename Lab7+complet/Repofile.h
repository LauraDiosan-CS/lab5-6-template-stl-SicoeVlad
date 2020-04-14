
#pragma once
#include "repo.h"
#include <iostream>
#include <fstream>
#include <istream>
using namespace std;

template <class T>
class RepoFile : public  Repo<T> {
private:
	ifstream  in;
	ofstream of;
	char* fileName;
public:
	// Constructor fara param
	RepoFile() :Repo<T>() {};
	// Constructor cu paramentrii
	RepoFile(const char* fileName) {
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		in.open(fileName);
		if (!in)
			cerr << "Error in opening the file" << endl;
	}

	//Destructor,inc. f
	~RepoFile() {
		
		in.close();
		of.close();
	}

	//Seteaza numele fisierului
	void setFile(const char* fileName) {
		this->fileName = new char[strlen(fileName) + 1]; 
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
		in.open(fileName);
		if (!in)
			cerr << "Error in opening the file" << endl;
	}

	string getFileName()
	{
		return this->fileName;
	}
	//Operatorul de atribuire
	

	const RepoFile<T>& operator=(const RepoFile<T>& r) {
		in = r.in;
		this->fileName = new char[strlen(r.fileName) + 1];
		strcpy(this->fileName, r.fileName);
		return *this; 
	}

	//Adauga elemente din fisier
	void addElement() {
		T el;
			
		while (in >> el) {
			Repo<T>::addElem(el);
		}
	}

	//setter pentru numar
	void setNumar(int numar, int pos) {
		this->elem[pos].setNumar(numar);

	}

	//Returneaza toate elementele din fisier, copia lui getAll() din repo
	vector<T> getAll() {
		return Repo<T>::getAll();
	}

	// suprascrie datele din fisier
	void scriere() {
		of.open(this->fileName);
		for (unsigned int i = 0; i < this->elem.size(); i++)
			of << this->elem[i];
	}

};
