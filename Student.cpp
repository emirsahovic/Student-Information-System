#include "Student.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::istream;


Student::Student()
{

}

void Student::setIme()
{
	cout << "Unesite ime studenta: ";
	cin.getline(this->ime, 20);
}

void Student::setPrezime()
{
	cout << "Unesite prezime studenta: ";
	cin.getline(this->prezime, 30);
}

void Student::setBrIndeksa()
{
	do {
		cout << "Unesite broj indeksa: ";
		cin >> this->brIndeksa;
		if (this->brIndeksa < 0 || this->brIndeksa>10000)
		{
			cout << "\t\n[GRESKA] - Broj indeksa mora biti u rasponu [0-10000]\n\n";
		}
	} while (this->brIndeksa < 0 || this->brIndeksa>10000);
	cin.ignore();
}

void Student::setGodina()
{
	int x;
	do {
		std::cout << "Unesite godinu studija: ";
		std::cin >> x;
		if(x < 1 || x > 5)
		{
		  cout<<"\n\t[GRESKA] - Unesite godinu iz raspona [1-5]!\n\n";
		}
	} while (x < 1 || x > 5);
	std::cin.ignore();
	this->godina = Godina(x);
}

char* Student::getIme()
{
	return this->ime;
}

char* Student::getPrezime()
{
	return this->prezime;
}

int Student::getBrIndeksa()
{
	return this->brIndeksa;
}

Godina Student::getGodina()
{
	return this->godina;
}

istream& operator>>(istream& unos, Student& s)
{
	s.setIme();
	s.setPrezime();
	s.setGodina();
	s.setBrIndeksa();
	return unos;
}

Student::~Student()
{
}
