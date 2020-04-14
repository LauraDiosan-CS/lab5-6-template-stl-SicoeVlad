#include "Service.h"
#include "Repo.h"
#include <iostream>
using namespace std;

ServiceRepoTemplate::ServiceRepoTemplate()
{

}

ServiceRepoTemplate::ServiceRepoTemplate(const Repo<Produs> &r)
{
	repo = r;
}

void ServiceRepoTemplate::setRepo(const Repo<Produs>& r)
{
	repo = r;
}
void ServiceRepoTemplate::addProdus(Produs p)
{
	repo.addElem(p);
}


vector<Produs> ServiceRepoTemplate::getAll()
{
	return repo.getAll();
}


int ServiceRepoTemplate::getSize()
{
	return this->repo.size();
}
int ServiceRepoTemplate::findOne(Produs p)
{
	return repo.find(p);
}

ServiceRepoTemplate::~ServiceRepoTemplate()
{

}