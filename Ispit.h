#ifndef ISPIT_H
#define ISPIT_H
#include <vector>
#include "Predmet.h"
#include "Student.h"

using std::vector;

class Ispit
{
private:
	vector<Predmet> predmeti;
	vector<Student> studenti;	
public:
	Ispit();
	void setPredmeti();
	void setStudenti();
	vector<Predmet>& getPredmeti();
	vector<Student>& getStudenti();
	void ispisIspita();
	void pretragaPoImenu();
	void pretragaPoPrezimenu();
	void pretragaPoNazivuPredmeta();
	void PoloziliSu();
	void NisuPolozili();
	void ispisPolozenih();
	void ispisNepolozenih();
	void Prolaznost();
	void ispisiMinS();
	void ispisiMaxS();
	void rotirajP(Predmet&, Predmet&);
	void rotirajS(Student&, Student&);
	void sortiraj();
	void ispisi_sortirano();
	void pretragaPoGodini();
	void operator^(int n);
	~Ispit();
};

#endif
