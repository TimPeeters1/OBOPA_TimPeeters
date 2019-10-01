#include "Transactie.h"

Transactie::Transactie(transactieType type, int saldo, std::string date)
{
	this->typeTransactie = type;

	this->saldo = saldo;

	this->date = date;
}

Transactie::~Transactie()
{
}

std::string Transactie::getDate() const{ return date;}

float Transactie::getAmount() const { return saldo;}

transactieType Transactie::getType() const { return typeTransactie; }



