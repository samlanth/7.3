#pragma once
#include <exception>
#include <string>
using namespace std;

/*
d�river de la classe exception de la librairie standard.
*/

class CFractionException : public exception
{
private:


public:
//un constructeur qui prend un const char* en param�tre et
//le refile au constructeur de la classe exception.
	CFractionException(const char* c) : exception(c) {};

};