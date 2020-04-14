#include "Service.h"
#include "Ui.h"
#include "Logic.h"
#include <iostream>
using namespace std;


UI::UI()
{

}

UI::~UI()
{

}

UI::UI(ServiceRepoTemplate service)
{
	this->serv = service;
}



void UI::run() {
	Logic l;
	int cod, suma;
	int v[4];
	string alegere;
	bool stop = false;
	int nrM5, nrM10;
	nrM5 = 15;
	nrM10 = 15;
	while (stop == false) {
		cout << "Vreti sa achizitionati un produs?" << endl;
		cout << "Alegere: "; cin >> alegere;
		if (alegere == "da")
		{
			l.print();
			cout << "Introduceti bancnota: "; cin >> suma;
			while ((suma != 1) && (suma != 5) && (suma != 10) && (suma != 50))
			{
				cout << "Puteti introduce doar unul din numerele 1, 5, 10, 50, deoarece doar astfel de bancnote accepta tonomatul!";
				cout << "Introduceti bancnota: "; cin >> suma;
			}
			cout << "Introduceti codul produsului: "; cin >> cod;
			double p;
			int mcinci, mzece;
			if (l.gaseste(cod) >= 0) {
				p = l.t.getAll()[l.gaseste(cod)].getPret();// din vectorul de produse, referim la indicele la care am gasit codul si stocam pretul
				if (suma < p)
					cout << "Suma introdusa este mai mica decat pretul produsului selectat" << endl;
				else {
					if (suma == p) {

						cout << "Tranzactie acceptata. Va multumim!" << endl;
					}
					else
					{
						l.rest(suma, p, mcinci, mzece);
						nrM5 = nrM5 - mcinci;
						nrM10 = nrM10 - mzece;
						if ((nrM5 > 0) && (nrM10 > 0)) {
							cout << "Rest: " << mcinci << " monede de 50 de bani si " << mzece << " monede de 10 bani" << endl;
							cout << "Tranzactie acceptata! Va multumim!" << endl;
						}
						else
						{
							cout << "Nu mai avem monede pentru rest! Reveniti mai tarziu!";
							stop = true;
						}
					}
				}
			}
			else
				cout << "Cod invalid!!" << endl;
		}

		else
		{
			cout << "O zi buna!";
			stop = true;
		}
	}
}
