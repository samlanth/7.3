#pragma once
#include <exception>
#include <string>
using namespace std;

/*
dériver de la classe exception de la librairie standard.
*/

class CFractionException : public exception
{
private:


public:
//un constructeur qui prend un const char* en paramètre et
//le refile au constructeur de la classe exception.
	CFractionException(const char* c) : exception(c) {};

};