#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

enum Godina{prva = 1, druga, treca, cetvrta, peta};

class Student
{
private:
	char ime[20], prezime[30];
	int brIndeksa;
	Godina godina;
public:
	Student();
	void setIme();
	void setPrezime();
	void setBrIndeksa();
	void setGodina();
	char* getIme();
	char* getPrezime();
	int getBrIndeksa();
	Godina getGodina();
	friend std::istream& operator>>(std::istream& unos, Student& s);
	~Student();
};

#endif
