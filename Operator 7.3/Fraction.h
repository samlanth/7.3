//Vous devez concevoir une classe CFraction qui implémente un nombre rationnel,
//sous forme numérateur/dénominateur. Par exemple, 3/4 est une fraction, 5/10 aussi.
#pragma once
class CFraction
{
private:
	int num_;
	int den_;
	static int Compteur_;
	static void SetCompteur(int compteur) { Compteur_ = compteur; }
public:
	//Une CFraction devra avoir un constructeur paramétrique qui permet de donner les deux nombres qui la composent,
	//seulement le numérateur (1 sera alors utilisé comme dénominateur par défaut) ou rien du tout (0/1 sera alors la fraction par défaut obtenue).
	CFraction(int num, int den);
	CFraction(int nombre);
	CFraction();
	CFraction(const CFraction& f) {
		this->num_ = f.num_;
		this->den_ = f.den_;
		Compteur_++;
	}
	//Ajoutez un constructeur à la classe CFraction qui prend une référence à un istream en paramètre.
	~CFraction();
	void SetNum(int num);
	void SetDen(int den);
	int GetDen() const;
	int GetNum() const;
	bool operator==(const CFraction& Fraction) const;
	bool operator!=(const CFraction& Fraction) const;
	CFraction& operator=(const CFraction& Fraction);
	CFraction& operator+=(int Valeur);
	CFraction& operator+=(const CFraction& LaFraction);

	CFraction operator++(int);
	CFraction& operator++();
	bool operator<(const CFraction& Fraction) const;
	static int GetCompteur() { return Compteur_; }
};