
#pragma once
#include <string>
#include <iostream>
using namespace std;
class Produs
{
private:
	int cod;
	char* nume;
	double  pret;
public:
	Produs();
	Produs(int cod, const char* nume, int pret);
	Produs(const Produs& p);
	int getCod();
	double getPret();
	char* getNume();
	void setPret(double pret);
	void setNume(const char* nume);
	void setCod(int cod);
	Produs& operator=(const Produs& p);
	bool compare(const Produs& p, int a);
	friend ostream& operator<<(ostream& os, Produs& c);
	friend istream& operator>>(istream& is, Produs& c);
	~Produs();
};