#include <iostream>
#include "Fraction.h"
#include <string>
#include "FractionException.h"
#include <fstream>
using namespace std;
int CFraction::Compteur_ = 0;

int CFraction::GetDen() const
{
	return den_;
}
int CFraction::GetNum() const
{
	return num_;
}
//Modifiez le mutateur SetDenominateur de la classe
//CFraction pour qu'il lance une exception de type
//CFractionException avec le message
//"Denominateur est zero" lorsque la valeur
//du dénominateur est nulle. 
void CFraction::SetDen(int den)
{
	if (den == 0)
		throw CFractionException("Denominateur est zero", den);
	else
	{
		den_ = den;
	}
}
void CFraction::SetNum(int num)
{
	num_ = num;
}

//Une CFraction devra avoir un constructeur paramétrique qui permet de donner les deux nombres qui la composent,
//seulement le numérateur (1 sera alors utilisé comme dénominateur par défaut) ou rien du tout (0/1 sera alors la fraction par défaut obtenue).
CFraction::CFraction(int num, int den)
	: num_(num), den_(den)
{
	
	if (den == 0)
	throw CFractionException("Denominateur est zero", den);
	else
		Compteur_++;
			
}

CFraction::CFraction(int nombre)
	: num_(nombre), den_(1)
{
	Compteur_++;
}

//Ajoutez un constructeur à la classe CFraction qui prend une référence à un istream en paramètre. 
//Ce constructeur doit lire la prochaine ligne du flux d'entrée et en extraire les valeurs du numérateur et du dénominateur.
//Si le constructeur est incapable de déchiffrer la ligne correctement, il lance une exception de type CFractionException avec un message d'erreur précis


CFraction::CFraction()
	: num_(0), den_(1)
{
	
	Compteur_++;
	
}
CFraction::~CFraction()
{
	Compteur_--;
}

bool CFraction::operator==(const CFraction& f) const
{
	double d1 = static_cast<double>(num_) / static_cast<double>(den_);
	double d2 = static_cast<double>(f.num_) / static_cast<double>(f.den_);
	return (d1 == d2);
}
bool CFraction::operator!=(const CFraction& Fraction) const
{
	return !operator==(Fraction);
}
CFraction& CFraction::operator=(const CFraction& Fraction)
{
	if (this != &Fraction)
	{
		SetNum(Fraction.GetNum());
		SetDen(Fraction.GetDen());
	}
	return *this;
}
CFraction& CFraction::operator+=(int Valeur)
{
	Valeur = Valeur * GetDen();
	SetNum(GetNum() + Valeur);
	SetDen(GetDen());
	return *this;
}
CFraction& CFraction::operator+=(const CFraction& LaFraction)
{
	SetNum(GetNum() * LaFraction.GetDen() + (LaFraction.GetNum() * GetDen()));
	SetDen(GetDen() * LaFraction.GetDen());
	return *this;
}

CFraction CFraction::operator++(int)
{
	// n1/d1 + 1 = (n1+1*d1)/d1
	CFraction old = *this;
	this->num_ = this->num_ + 1 * this->den_;
	return old;
}

CFraction& CFraction::operator++()
{
	// n1/d1 + 1 = (n1+1*d1)/d1
	this->num_ = this->num_ + 1 * this->den_;
	return *this;
}

bool CFraction::operator<(const CFraction& Fraction) const
{
	double d1 = static_cast<double>(GetNum()) / static_cast<double>(GetDen());
	double d2 = static_cast<double>(Fraction.GetNum()) / static_cast<double>(Fraction.GetDen());
	if (d1 < d2)
		return true;
	else
		return false;
}