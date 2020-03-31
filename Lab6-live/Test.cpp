
#include "produs.h"
#include "repo.h"
#include <cassert>
#include <iostream>
using namespace std;
void testProdus() 
{
	void testProdusConstructor();
	void testGet();
	void testSet();
	void testCopiere();
	cout << "Toate testele referitoare la clasa Produs au trecut cu succes!" << endl;
}
void testProdusConstructor()
{
	Produs p1;
	assert(p1.getCod() == -1);
}
void testProdusGet()
{
	Produs p1 = Produs(1, "twix", 5);
	assert(strcmp(p1.getNume(), "twix") == 0);
	assert(p1.getPret() == 5);
}
void testProdusCopiere()
{
	Produs p1 = Produs(1, "twix", 5);
	Produs p2 = p1;
	assert(p2.compare(p1, 0) == true);
}
void testProdusSet()
{
	Produs p1 = Produs(1, "twix", 5);
	p1.setNume("apa");
	p1.setCod(8);
	assert(strcmp(p1.getNume(), "apa") == 0);
	assert(p1.getCod() == 8);
}

void testRepo() {
	Repo < Produs> r;
	Produs p1 = Produs(1, "apa", 2);
	Produs p2 = Produs(11, "faina", 3);
	r.addElem(p1);
	r.addElem(p2);
	assert(r.getAll()[0].compare(p1, 0) == true);
	assert(r.getAll()[1].compare(p2, 0) == true);
	assert(r.getAll().size() == 2);
	cout << "Testele au trecut cu succes!!" << endl;
}






void allTests() {
	testProdus();
	testRepo();
}
