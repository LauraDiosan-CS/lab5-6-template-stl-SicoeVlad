#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Repo.h"
#include "Produs.h"
using namespace std;

class ServiceRepoTemplate
{
private:
	Repo<Produs> repo;
public:
	ServiceRepoTemplate();
	~ServiceRepoTemplate();
	ServiceRepoTemplate(const Repo<Produs>&);
	void setRepo(const Repo<Produs>&);
	void addProdus(Produs p);
	int getSize();
	vector<Produs> getAll();
	int findOne(Produs p);


};