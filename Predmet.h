#ifndef PREDMET_H
#define PREDMET_H
#include <iostream>

class Predmet {
private:
	char naziv[20];
	double pp, dp;
public:
	Predmet();
	static int ub;
	void setNaziv();
	void setPP();
	void setDP();
	char* getNaziv();
	double getPP(); // prva parcijala
	double getDP(); // druga parcijala
	friend std::istream& operator>>(std::istream& unos, Predmet& p);
	~Predmet();
};

#endif
