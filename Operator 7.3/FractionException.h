#pragma once

#include <exception>
#include <string>

using namespace std;

/*
d�river de la classe exception de la librairie standard.
*/

class CFractionException : public exception
{
public:
	CFractionException(const char* c) : exception(c) {};
};