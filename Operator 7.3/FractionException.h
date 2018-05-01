#pragma once

#include <exception>
#include <string>

using namespace std;

/*
dériver de la classe exception de la librairie standard.
*/

class CFractionException : public exception
{
public:
	CFractionException(const char* c) : exception(c) {};
};