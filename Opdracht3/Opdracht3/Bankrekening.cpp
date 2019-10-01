#include "Bankrekening.h"

Bankrekening::Bankrekening(float saldo, std::vector<Transactie> transactieHistorie)
{
	this->saldo = saldo;
	this->transactieHistorie = transactieHistorie;
}

Bankrekening::~Bankrekening()
{}

Bankrekening Bankrekening::operator+=(const Transactie& transactie)
{
	transactieType type = transactie.getType();

	if (type == bijschrijving){
		saldo += transactie.getAmount();
	}
	if (type == afschrijving) {
		saldo -= transactie.getAmount();
	}

	transactieHistorie.push_back(transactie);

	return *this;
}

float Bankrekening::getSaldo() const { return saldo;}

std::vector<Transactie> Bankrekening::getHistory() const{ return transactieHistorie;}

std::ostream& operator<<(std::ostream& os, const Bankrekening& bankrekening)
{
	os << "Bankrekening| Saldo: " << bankrekening.getSaldo() << " EUR \n\n";

	for (int i = 0; i < bankrekening.transactieHistorie.size(); i++)
	{
		std::string type;
		if (bankrekening.transactieHistorie[i].getType() == afschrijving) {
			type = "afschrijving";
		}
		if (bankrekening.transactieHistorie[i].getType() == bijschrijving) {
			type = "bijschrijving";
		}

		os << bankrekening.transactieHistorie[i].getDate() << " | " <<  type << " | "<< bankrekening.transactieHistorie[i].getAmount() << " EUR" << std::endl;
	}
	os << "\n\n";
	return os;
}
