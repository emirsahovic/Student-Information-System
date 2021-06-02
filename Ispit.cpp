#include <iostream>
#include <string.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include "Ispit.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::fstream;
using std::istream;

Ispit::Ispit()
{
}

Ispit::~Ispit()
{
}

void Ispit::setPredmeti()
{
	Predmet temp;
	cin >> temp;
	this->predmeti.push_back(temp);
}

void Ispit::setStudenti()
{
	Student temp;
	cin >> temp;

	for (int i = 0; i < this->getStudenti().size(); i++)
	{
		if (temp.getBrIndeksa() == this->getStudenti()[i].getBrIndeksa())
		{
			do {
				if (temp.getBrIndeksa() == this->getStudenti()[i].getBrIndeksa())
				{
					cout << "\n[GRESKA] - Taj broj indeksa vec postoji u bazi - unesite novi!\n\n";
				}
				temp.setBrIndeksa();
			} while (temp.getBrIndeksa() == this->getStudenti()[i].getBrIndeksa());
		}
	}

	this->studenti.push_back(temp);
}

vector<Predmet>& Ispit::getPredmeti()
{
	return this->predmeti;
}

vector<Student>& Ispit::getStudenti()
{
	return this->studenti;
}

void Ispit::ispisIspita()
{
	if (this->getPredmeti().size() == 0) {
		cout << "\n\t\t\t[Baza je prazna!]\n";
	}
	else {
		fstream Ispis;
		Ispis.open("Ispis.txt");
		Ispis << setw(10) << left << "R.br" << setw(20) << left << "Prezime" << setw(15) << left << "Ime" << setw(20) << left << "BrIndeksa" << setw(20) << left << "Predmet" << setw(20) << left << "Godina" << endl;

		cout << setw(7) << left << "R.br" << setw(15) << left << "Prezime" << setw(13) << left << "Ime" << setw(15) << left << "BrIndeksa" << setw(15) << left << "Predmet" << "Godina";
		cout << "\n--------------------------------------------------------------------------------";
		Student* s = new Student();
		Predmet* p = new Predmet();
		for (int i = 0; i < this->getPredmeti().size(); i++) {
			*s = this->getStudenti()[i];
			*p = this->getPredmeti()[i];

			cout << setw(7) << left << i + 1 << setw(15) << left << s->getPrezime() << setw(13) << left << s->getIme() << setw(15) << left << s->getBrIndeksa() << setw(15) << left << p->getNaziv();

			switch (s->getGodina()) {
			case prva:
				cout << "Prva\n";
				break;
			case druga:
				cout << "Druga\n";
				break;
			case treca:
				cout << "Treca\n";
				break;
			case cetvrta:
				cout << "Cetvrta\n";
				break;
			case peta:
				cout << "Peta\n";
				break;
			}
			Ispis << setw(10) << left << i + 1 << setw(20) << left << s->getPrezime() << setw(15) << left << s->getIme() << setw(20) << left << s->getBrIndeksa() << setw(20) << left << p->getNaziv() << s->getGodina() << endl;
		}
		delete s;
		delete p;

		Ispis.close();
	}
}

void Ispit::pretragaPoImenu()
{
	char imeP[30];
	cout << "Unesite ime za pretragu: ";
	cin.getline(imeP, 30);
	if (this->getStudenti().size() == 0) {
		cout << "\n\t\t\t[Baza je prazna!]\n";
	}
	else {
		Ispit* temp = new Ispit();
		for (int i = 0; i < this->getStudenti().size(); i++) {
			if (_strcmpi(this->getStudenti()[i].getIme(), imeP) == 0) {
				temp->getPredmeti().push_back(this->getPredmeti()[i]);
				temp->getStudenti().push_back(this->getStudenti()[i]);
			}
		}
		if (temp->getStudenti().size() == 0) {
			cout << "Ne postoje studenti sa imenom: " << imeP << "!\n";
		}
		else {
			temp->ispisIspita();
		}
		delete temp;
	}
}

void Ispit::pretragaPoPrezimenu()
{
	char prezimeP[30];
	cout << "Unesite prezime za pretragu: ";
	cin.getline(prezimeP, 30);
	if (this->getStudenti().size() == 0) {
		cout << "\n\t\t\t[Baza je prazna!]\n";
	}
	else {
		Ispit* temp = new Ispit();
		for (int i = 0; i < this->getStudenti().size(); i++) {
			if (_strcmpi(this->getStudenti()[i].getPrezime(), prezimeP) == 0) {
				temp->getPredmeti().push_back(this->getPredmeti()[i]);
				temp->getStudenti().push_back(this->getStudenti()[i]);
			}
		}
		if (temp->getStudenti().size() == 0) {
			cout << "Ne postoje studenti sa prezimenom: " << prezimeP << "!\n";
		}
		else {
			temp->ispisIspita();
		}
		delete temp;
	}
}

void Ispit::pretragaPoNazivuPredmeta()
{
	char predmetP[20];
	cout << "Unesite naziv predmeta za pretragu: ";
	cin.getline(predmetP, 20);
	if (this->getPredmeti().size() == 0) {
		cout << "\n\t\t\t[Baza je prazna!]\n";
	}
	else {
		Ispit* temp = new Ispit();
		for (int i = 0; i < this->getPredmeti().size(); i++) {
			if (_strcmpi(this->getPredmeti()[i].getNaziv(), predmetP) == 0) {
				temp->getPredmeti().push_back(this->getPredmeti()[i]);
				temp->getStudenti().push_back(this->getStudenti()[i]);
			}
		}
		if (temp->getPredmeti().size() == 0) {
			cout << "Ne postoji predmet: " << predmetP << "\n";
		}
		else {
			temp->ispisIspita();
		}
		delete temp;
	}
}

void Ispit::PoloziliSu()
{
	char pretraga[30];
	if (this->getPredmeti().size() == 0) {
		cout << "\n\t\t\t[Baza je prazna!]\n";
	}
	else {
		cout << "\n======================================================\n";
		cout << "\tUnesite predmet za pretragu: ";
		cin.getline(pretraga, 30);
		cout << endl;
		Ispit* temp = new Ispit();
		for (int i = 0; i < this->getPredmeti().size(); i++) {
			if ((this->getPredmeti()[i].getPP()) >= (this->getPredmeti()[i].Predmet::ub / 3.6) && (this->getPredmeti()[i].getDP()) >= (this->getPredmeti()[i].Predmet::ub / 3.6) && (_strcmpi(this->getPredmeti()[i].getNaziv(), pretraga) == 0)) {
				temp->getPredmeti().push_back(this->getPredmeti()[i]);
				temp->getStudenti().push_back(this->getStudenti()[i]);
			}
		}
		if (temp->getPredmeti().size() == 0) {
			cout << "\n================================================================================";
			cout << "\t\tNema polozenih ispita iz predmeta " << pretraga << endl;
			cout << "================================================================================\n";
		}
		else {
			temp->ispisPolozenih();
		}
		delete temp;
	}
}

void Ispit::NisuPolozili()
{
	char pretraga1[30];
	if (this->getPredmeti().size() == 0) {
		cout << "\n\t\t\t[Baza je prazna!]\n";
	}
	else {
		cout << "\n======================================================\n";
		cout << "\tUnesite predmet za pretragu: ";
		cin.getline(pretraga1, 30);
		cout << endl;

		Ispit* temp = new Ispit();
		for (int i = 0; i < this->getPredmeti().size(); i++) {
			if (((this->getPredmeti()[i].getPP()) < (this->getPredmeti()[i].Predmet::ub / 3.6) || (this->getPredmeti()[i].getDP()) < (this->getPredmeti()[i].Predmet::ub / 3.6)) && (_strcmpi(this->getPredmeti()[i].getNaziv(), pretraga1) == 0)) {
				temp->getPredmeti().push_back(this->getPredmeti()[i]);
				temp->getStudenti().push_back(this->getStudenti()[i]);
			}
		}

		if (temp->getPredmeti().size() == 0) {
			cout << "\n================================================================================";
			cout << "\t\tNema nepolozenih ispita iz predmeta " << pretraga1 << endl;
			cout << "================================================================================\n";
		}

		else {
			temp->ispisNepolozenih();
		}
		delete temp;
	}
}

void Ispit::ispisPolozenih()
{
	fstream IspisNP;
	IspisNP.open("IspisNP.txt");
	IspisNP << setw(10) << left << "R.br" << setw(20) << left << "Prezime" << setw(15) << left << "Ime" << setw(20) << left << "Predmet" << setw(20) << left << "Bodovi" << setw(20) << left << "Ocjena" << endl;

	cout << setw(10) << left << "R.br" << setw(10) << left << "Prezime" << setw(10) << left << "Ime" << setw(15) << left << "Predmet" << setw(10) << left << "Bodovi" << "Ocjena";
	cout << "\n--------------------------------------------------------------------------------";

	Student* s = new Student();
	Predmet* p = new Predmet();
	int ocjena;

	for (int i = 0; i < this->getPredmeti().size(); i++) {
		*s = this->getStudenti()[i];
		*p = this->getPredmeti()[i];

		if ((p->getPP() + p->getDP()) < 55) ocjena = 5;
		if ((p->getPP() < p->Predmet::ub / 3.6) || (p->getDP() < p->Predmet::ub / 3.6)) ocjena = 5;
		else if ((p->getPP() + p->getDP()) >= 55 && (p->getPP() + p->getDP()) < 65) ocjena = 6;
		else if ((p->getPP() + p->getDP()) >= 65 && (p->getPP() + p->getDP()) < 75) ocjena = 7;
		else if ((p->getPP() + p->getDP()) >= 75 && (p->getPP() + p->getDP()) < 85) ocjena = 8;
		else if ((p->getPP() + p->getDP()) >= 85 && (p->getPP() + p->getDP()) < 95) ocjena = 9;
		else if ((p->getPP() + p->getDP()) >= 95 && (p->getPP() + p->getDP()) <= 120) ocjena = 10;

		cout << setw(10) << left << i + 1 << setw(10) << left << s->getPrezime() << setw(10) << left << s->getIme() << setw(15) << left << p->getNaziv() << setw(10) << left;
		cout << p->getPP() + p->getDP() << ocjena << endl;

		IspisNP << setw(10) << left << i + 1 << setw(20) << left << s->getPrezime() << setw(15) << left << s->getIme() << setw(20) << left << p->getNaziv() << setw(20) << left << p->getPP() + p->getDP() << ocjena << endl;

	}
	delete s;
	delete p;
	IspisNP.close();
}

void Ispit::ispisNepolozenih()
{
	this->ispisPolozenih();
}

void Ispit::Prolaznost()
{
	if (this->getPredmeti().size() == 0)
	{
		cout << "\n\t\t\t[Baza je prazna!]\n";
	}

	else {
		char pretraga2[30];

		cout << "\n======================================================\n";
		cout << "\tUnesite predmet za pretragu: ";
		cin.getline(pretraga2, 30);
		cout << endl;

		float prolaznost = 0;
		float br = 0;
		float brp = 0;
		float brn = 0;
		Ispit* temp = new Ispit();
		Ispit* temp1 = new Ispit();

		for (int i = 0; i < this->getPredmeti().size(); i++)
		{
			if ((this->getPredmeti()[i].getPP()) >= (this->getPredmeti()[i].Predmet::ub / 3.6) && (this->getPredmeti()[i].getDP()) >= (this->getPredmeti()[i].Predmet::ub / 3.6) && (_strcmpi(this->getPredmeti()[i].getNaziv(), pretraga2) == 0))
			{
				temp->getPredmeti().push_back(this->getPredmeti()[i]);
				temp->getStudenti().push_back(this->getStudenti()[i]);
				brp++;
			}

			else if (((this->getPredmeti()[i].getPP()) < (this->getPredmeti()[i].Predmet::ub / 3.6) || (this->getPredmeti()[i].getDP()) < (this->getPredmeti()[i].Predmet::ub / 3.6)) && (_strcmpi(this->getPredmeti()[i].getNaziv(), pretraga2) == 0)) {
				temp1->getPredmeti().push_back(this->getPredmeti()[i]);
				brn++;
			}
		}

		if (temp->getPredmeti().size() == 0 && temp1->getPredmeti().size() == 0)
		{
			cout << "\t[GRESKA] - Nema predmeta " << "<" << pretraga2 << ">\n";
		}

		else {
			br = brp + brn;

			prolaznost = (temp->getStudenti().size() / br) * 100;
			cout << "===================================================================\n";
			cout << "\t\tProlaznost iznosi [" << prolaznost << "%]" << endl;
			cout << "===================================================================\n";
			delete temp;
		}
	}
}

void Ispit::ispisiMinS()
{
	float minS = INT_MAX;
	int index = 0;

	if (this->getPredmeti().size() == 0)
	{
		cout << "\n\t\t\t[Baza je prazna!]\n";
	}

	else {
		char pretraga3[30];

		cout << "\n======================================================\n";
		cout << "\tUnesite predmet za pretragu: ";
		cin.getline(pretraga3, 30);
		cout << endl;

		Ispit* is = new Ispit();

		for (int i = 0; i < this->getPredmeti().size(); i++)
		{
			if ((this->getPredmeti()[i].getPP() + this->getPredmeti()[i].getDP()) < minS && (_strcmpi(this->getPredmeti()[i].getNaziv(), pretraga3) == 0))
			{
				is->getPredmeti().push_back(this->getPredmeti()[i]);
				minS = (this->getPredmeti()[i].getPP() + this->getPredmeti()[i].getDP());
				index = i;
			}
		}

		if (is->getPredmeti().size() == 0)
		{
			cout << "[GRESKA] - Nema predmeta " << "<" << pretraga3 << ">\n";
		}

		else {
			cout << "================================================================================";
			cout << "<Student " << this->getStudenti()[index].getIme() << " " << this->getStudenti()[index].getPrezime() << " ima najmanji broj bodova [" << minS << "] iz predmeta " << pretraga3 << ">\n";
			cout << "================================================================================";
		}
	}
}

void Ispit::ispisiMaxS()
{
	float maxS = INT_MIN;
	int index1 = 0;

	if (this->getPredmeti().size() == 0)
	{
		cout << "\n\t\t\t[Baza je prazna!]\n";
	}

	else {
		char pretraga4[30];

		cout << "\n======================================================\n";
		cout << "\tUnesite predmet za pretragu: ";
		cin.getline(pretraga4, 30);
		cout << endl;

		Ispit* is = new Ispit();

		for (int i = 0; i < this->getPredmeti().size(); i++)
		{
			if ((this->getPredmeti()[i].getPP() + this->getPredmeti()[i].getDP()) > maxS && (_strcmpi(this->getPredmeti()[i].getNaziv(), pretraga4) == 0))
			{
				is->getPredmeti().push_back(this->getPredmeti()[i]);
				maxS = (this->getPredmeti()[i].getPP() + this->getPredmeti()[i].getDP());
				index1 = i;
			}
		}


		if (is->getPredmeti().size() == 0)
		{
			cout << "\t[GRESKA] - Nema predmeta " << pretraga4 << endl;
		}

		else {
			cout << "================================================================================";
			cout << "<Student " << this->getStudenti()[index1].getIme() << " " << this->getStudenti()[index1].getPrezime() << " ima najveci broj bodova [" << maxS << "] iz predmeta " << pretraga4 << ">\n";
			cout << "================================================================================";
		}
	}
}


void Ispit::operator^(int n)
{
	this->studenti.erase(this->studenti.begin() + n - 1);
	this->predmeti.erase(this->predmeti.begin() + n - 1);
	std::cout << "\nStudent uspjesno obrisan!\n";
}

void Ispit::rotirajP(Predmet &x, Predmet &y) {
	Predmet temp = x;
	x = y;
	y = temp;
}

void Ispit::rotirajS(Student &x, Student &y)
{
	Student temp = x;
	x = y;
	y = temp;
}

void Ispit::sortiraj() {
	for (int i = 0; i < this->getPredmeti().size() - 1; i++) {
		for (int j = 0; j < getPredmeti().size() - 1; j++) {
			if ((this->getPredmeti()[j].getPP() + this->getPredmeti()[j].getDP()) < (this->getPredmeti()[j + 1].getPP() + this->getPredmeti()[j + 1].getDP())) {
				rotirajP(this->getPredmeti()[j], this->getPredmeti()[j + 1]);
				rotirajS(this->getStudenti()[j], this->getStudenti()[j + 1]);
			}
		}
	}
}

void Ispit::ispisi_sortirano() {

	if (this->getPredmeti().size() == 0)
	{
		cout << "\n\t\t\t[Baza je prazna!]\n";

	}

	else {
		sortiraj();
		Ispit* is = new Ispit();
		char pretraga5[30];

		cout << "\n======================================================\n";
		cout << "\tUnesite predmet za pretragu: ";
		cin.getline(pretraga5, 30);
		cout << endl;
		int j = 0;

		cout << "=============================================================================\n";
		for (int i = 0; i < this->getPredmeti().size(); i++) {
			if (_strcmpi(this->getPredmeti()[i].getNaziv(), pretraga5) == 0)
			{
				is->getPredmeti().push_back(this->getPredmeti()[i]);
				cout << " " << j + 1 << ".    " << this->getStudenti()[i].getIme() << " " << setw(10) << left << this->getStudenti()[i].getPrezime() << " PREDMET " << "[" << this->getPredmeti()[i].getNaziv() << "]" << "   " << (this->getPredmeti()[i].getPP() + this->getPredmeti()[i].getDP()) << " [BODOVA]" << endl;
				j++;
			}
		}

		if (is->getPredmeti().size() == 0)
		{
			cout << "\t[GRESKA] - Nema predmeta " << "<" << pretraga5 << ">" << endl;
		}

		cout << "=============================================================================\n";
	}
}

void Ispit::pretragaPoGodini()
{
	int godinaP;
	do {
		cout << "\n======================================================\n";
		cout << "\tUnesite godinu za pretragu [1-5]: ";
		cin >> godinaP;
		if (godinaP < 1 || godinaP>5)
		{
			cout << "[GRESKA] - Godina mora biti u rasponu [1-5]!\n";
		}
	} while (godinaP < 1 || godinaP>5);

	cin.ignore();
	cout << endl;

	if (this->getPredmeti().size() == 0) {
		cout << "\n\t\t\t[Baza je prazna!]\n";
	}
	else {
		Ispit* temp = new Ispit();
		for (int i = 0; i < this->getPredmeti().size(); i++) {
			if ((int(this->getStudenti()[i].getGodina()) == godinaP)) {
				temp->getPredmeti().push_back(this->getPredmeti()[i]);
				temp->getStudenti().push_back(this->getStudenti()[i]);
			}
		}
		if (temp->getPredmeti().size() == 0) {
			cout << "<Ne postoje studenti na " << godinaP << ". godini studija!>\n";
		}
		else {
			temp->ispisIspita();
		}
		delete temp;
	}
}
