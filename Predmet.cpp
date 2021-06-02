#include "Predmet.h"

#include <iostream>

using std::istream;
using std::cout;
using std::cin;
using std::endl;

int Predmet::ub = 100;

Predmet::Predmet()
{

}

void Predmet::setNaziv()
{
	cout << "Unesite naziv predmeta: ";
	cin.getline(this->naziv, 20);
}

void Predmet::setPP()
{
	do {
		try {
			cout << "Unesi osvojen broj bodova s [1.] parcijalnog ispita: ";
			cin >> this->pp;
			if (this->pp < 0) throw "Broj bodova ne moze biti negativan!\n";
			if (this->pp > Predmet::ub / 2) throw pp;
		}
		catch (const char* poruka)
		{
			cout << poruka << endl;
		}

		catch (double n)
		{
			cout << "Broj bodova " << n << " je veci od ukupnog broja bodova s [1.] parcijalnog ispita!\n";
		}

	} while (this->pp < 0 || this->pp > Predmet::ub / 2);
	cin.ignore();
}


void Predmet::setDP()
{
	do {
		try {
			cout << "Unesi osvojen broj bodova s [2.] parcijalnog ispita: ";
			cin >> this->dp;
			if (this->dp < 0) throw "Broj bodova ne moze biti negativan!\n";
			if (this->dp > Predmet::ub / 2) throw dp;
		}
		catch (const char* poruka)
		{
			cout << poruka << endl;
		}

		catch (double n)
		{
			cout << "Broj bodova " << n << " je veci od ukupnog broja bodova s [2.] parcijalnog ispita!\n";
		}
	} while (this->dp < 0 || this->dp > Predmet::ub / 2);
	cin.ignore();
}

char* Predmet::getNaziv()
{
	return this->naziv;
}

double Predmet::getPP()
{
	return this->pp;
}

double Predmet::getDP()
{
	return this->dp;
}

istream& operator>>(istream& unos, Predmet& p)
{
	p.setNaziv();
	p.setPP();
	p.setDP();
	return unos;
}

Predmet::~Predmet()
{
}
