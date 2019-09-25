#pragma once
#include <iostream>
//TODO Person superclass maken

using string = std::string;

class Docent
{
	public:
		Docent(string naam);
		~Docent();

		string getNaam();
	private:
		string docentNaam;
};

