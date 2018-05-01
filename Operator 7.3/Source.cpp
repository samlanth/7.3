#include <iostream>
#include "Fraction.h"
#include <exception>
#include "FractionException.h"
#include <string>
#include <fstream>
using namespace std;

CFraction operator+(const CFraction &LaFraction, int Valeur)
{
	// f5 + 3
	Valeur = Valeur * LaFraction.GetDen();

	int NouvelleVal = (LaFraction.GetNum() + Valeur);
	int n2 = (LaFraction.GetDen());
	CFraction Nouveau(NouvelleVal, n2);
	return Nouveau;
}

CFraction operator+(int Valeur, const CFraction &LaFraction)
{
	return operator+(LaFraction, Valeur);
}

CFraction operator+(const CFraction &LaFraction, const CFraction &LaFraction2)
{
	// n1/d1 + n2/d2 = n1*d2 + n2*d1 / (d1*d2)
	int n = LaFraction.GetNum() * LaFraction2.GetDen() + LaFraction2.GetNum() * LaFraction.GetDen();
	int d = LaFraction.GetDen() * LaFraction2.GetDen();

	return CFraction(n, d);
}

ostream & operator<<(ostream& os, const CFraction& Fraction)
{
	os << Fraction.GetNum() << "/";
	os << Fraction.GetDen();
	return os;
}

CFraction LaPlusPetite(CFraction f1, CFraction f2, CFraction f3)
{
	CFraction r;
	if ((f1 < f2) && (f1 < f3)) r = f1;
	else if ((f2 < f1) && (f2 < f3)) r = f2;
	else r = f3;

	cout << "Dans fonction -- Nombre de fractions: " << CFraction::GetCompteur() << endl;
	// Affiche 7 (f1, f2, f3 dans le main, plus f1, f2, f3 et plusPetite locales)

	return r;
}

int main()
{
	CFraction f1(1, 2);
	bool erreur = false;
	int num;
	int den;
	do
	{
		erreur = false;
		cout << " Ecrivez votre fraction " << endl;
		cout << " Numerateur " << endl;
		cin >> num;
		cout << " Denominateur " << endl;
		cin >> den;


		try
		{
			f1.SetNum(num);
			f1.SetDen(den);
			cout << "fraction cree" << endl;
		}
		catch (int i)
		{
			cout << "erreur " << i << endl;
		}
		catch (string s)
		{
			cout << s << endl;
			erreur = true;
		}
		catch (const exception& e)
		{
			cout << e.what() << endl;
			erreur = true;
		}
		catch (const CFractionException& e)
		{
			cout << e.what() << ": " << e.numRecu << "et" << e.denRecu << endl;
			erreur = true;
		}
		catch (...)
		{
			cout << "erreur" << endl;
			erreur = true;
		}
		cout << "fin des catchs " << endl;
	} while (erreur);
	system("pause");
}