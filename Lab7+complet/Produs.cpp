#include "Produs.h"
#include <iostream>
using namespace std;

//constructor fara parametri
Produs::Produs()
{
	this->pret = -1;
	this->cod = -1;
	this->nume = NULL;
}

//constructor cu parametri
Produs::Produs(int cod, const char* nume, int pret) {
	this->pret = pret;
	this->cod = cod;
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
}

//constructor de copiere
Produs::Produs(const Produs& p) {
	this->pret = p.pret;
	this->cod = p.cod;
	this->nume = new char[strlen(p.nume) + 1];
	strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
}

//destructorul
Produs::~Produs() {
	if (this->nume != NULL) {
		delete[] this->nume;
		this->nume = NULL;
	}
}

//getter pentru codul produsului
int Produs::getCod() {
	return this->cod;
}

//getter ptr pretul produsului
double Produs::getPret() {
	return this->pret;
}

//getter ptr numele produsului
char* Produs::getNume() {
	return this->nume;
}

//setter ptr codul produsului
void Produs::setCod(int cod) {
	this->cod = cod;
}

//setter pentru pretul produsului
void Produs::setPret(double pret) {
	this->pret = pret;
}

//setter pentru numele produsului
void Produs::setNume(const char* nume) {
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
}

//operatorul de atribuire
Produs& Produs::operator=(const Produs& p) {

	if (this != &p) {
		this->setPret(p.pret);
		this->setCod(p.cod);
		this->nume = new char[strlen(p.nume) + 1];
		this->setNume(p.nume);
	}

	return *this;
}

//functie de comparare a 2 a produse
bool Produs::compare(const Produs& p, int a) {
	bool rez;
	switch (a) {
	case 0:
		rez = (this->pret == p.pret) && (this->cod == p.cod) && (strcmp(this->nume, p.nume) == 0);
		break;
	case 1:
		rez = (this->pret == p.pret);
		break;
	case 2:
		rez = this->cod == p.cod;
		break;
	case 3:
		rez = strcmp(this->nume, p.nume) == 0;
		break;
	default:
		rez = (this->pret == p.pret) && (this->cod == p.cod) && (strcmp(this->nume, p.nume) == 0);
		break;
	}
	return rez;
}

//suprascrierea operatorului de afisare
ostream& operator<<(ostream& os, Produs& c) {
	os << c.cod << " " << c.nume << "  " << c.pret << endl;
	return os;
}

//Suprascriere operator de intrare
istream& operator>>(istream& is, Produs& c) {
	if (c.nume == NULL)
		c.nume = new char[20];
	is >> c.cod >> c.nume >> c.pret;
	return is;
}