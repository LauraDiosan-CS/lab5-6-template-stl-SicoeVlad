#include "Logic.h"
#include <iostream>

using namespace std;

Logic::Logic()
{
	t.setFile("dateIN.txt");
	t.addElement();
}

Logic::~Logic()
{

}



int Logic::gaseste(int cod) {
	for (unsigned int i = 0; i < t.getAll().size(); i++) {
		if (t.getAll()[i].getCod() == cod)
			return i;
	}
	return -1;
}

void Logic::print() {
	cout << "Acceptam bancnote in valoare de 50,10,5,1!" << endl;
	cout << "Produse disponibile: " << endl;
	for (unsigned int i = 0; i < t.getAll().size(); i++) {
		cout << t.getAll()[i] << endl;
	}
	
}

void Logic::rest(int suma, double pret, int& cinci, int& unu)
{
	double aux;
	aux = suma - pret;
	int aux2;
	aux2 = int(aux * 10);
	cinci = aux2 / 5;
	unu = aux2 % 5;
}

