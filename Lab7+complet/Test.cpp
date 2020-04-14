
#include "produs.h"
#include "repo.h"
#include "Service.h"
#include "Repofile.h"
#include "Logic.h"
#include <cassert>
#include <iostream>
using namespace std;

void testProdusCreateSuccesful()
{
	Produs p1;
	assert(p1.getCod() == -1);
}
void testProdusGetSetSuccesful()
{
	Produs p1 = Produs(1, "twix", 5);
	Produs p2 = Produs(2, "suc", 10);
	p2.setNume("apa");
	p2.setCod(8);
	assert(strcmp(p1.getNume(), "twix") == 0);
	assert(p1.getPret() == 5);
	assert(strcmp(p2.getNume(), "apa") == 0);
	assert(p2.getCod() == 8);
}
void testProdusCopiereSuccesful()
{
	Produs p1 = Produs(1, "twix", 5);
	Produs p2 = p1;
	assert(p2.compare(p1, 0) == true);
}


void testRepoAddGetAllSuccesful() {
	Repo < Produs> r;
	Produs p1 = Produs(1, "apa", 2);
	Produs p2 = Produs(11, "faina", 3);
	r.addElem(p1);
	r.addElem(p2);
	assert(r.getAll()[0].compare(p1, 0) == true);
	assert(r.getAll()[1].compare(p2, 0) == true);
	assert(r.getAll().size() == 2);
	
}




void testServiceAddProdusSuccesfull()
{
	Repo<Produs> repo = Repo<Produs>();
	ServiceRepoTemplate serv = ServiceRepoTemplate(repo);
	Produs p1 = Produs(1, "apa", 2);
	Produs p2 = Produs(11, "faina", 3);
	serv.addProdus(p1);
	serv.addProdus(p2);
	assert(serv.getAll().size() == 2);
}

void testServiceFindProdusSuccesfull()
{
	int rez;
	Repo<Produs> repo = Repo<Produs>();
	ServiceRepoTemplate serv = ServiceRepoTemplate(repo);
	Produs p1 = Produs(1, "apa", 2);
	rez = serv.findOne(p1);
	assert(rez == 0);
}


void testRepo()
{
	void testRepoAddGetAllSuccesful();
}
void testProdus()
{
	void testProdusCreateSuccesful();
	void testProdusGetSetSuccesful();
	void testProdusCopiereSuccesful();
	
}


void testService()
{
	void testServiceAddProdusSuccesfull();
	void testServiceFindProdusSuccesfull();
}


void testRepoFileSetNumeSuccesfull()
{
	RepoFile<Produs> r;
	r.setFile("A.txt");
	assert(r.getFileName() == "A.txt");
}

void testRepoFileGetAllSuccesfull()
{
	RepoFile<Produs> r;
	r.setFile("A.txt");
	r.setFile("B.txt");
	//assert(r.getAll().size == 2);
}

void testRepoFile()
{
	void testRepoFileSetNumeSuccesfull();
	void testRepoFileGetAllSuccesfull();
}

void testRestSuccsesfull()
{
	Logic l;
	int suma;
	double pret;
	int cinci, zece;
	suma = 5;
	pret = 4;
	l.rest(suma, pret, cinci, zece);
	assert(cinci == 2);
	assert(zece == 0);
}

void allTests() {
	testProdus();
	testRepo();
	testService();
	testRepoFile();
	testRestSuccsesfull();
	cout << "Toate testele au trecut cu succes!";
}
