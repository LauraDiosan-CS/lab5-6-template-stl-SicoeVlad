#pragma once
#include "Repofile.h"
#include "Produs.h"
#include "Service.h"
#include "Ui.h"
#include <iostream>
using namespace std;

class Logic
{
public:
	RepoFile <Produs> t;
	Logic();
	~Logic();
	int gaseste(int cod);
	void print();
	void rest(int suma, double pret, int& cinci, int& unu);
	
};