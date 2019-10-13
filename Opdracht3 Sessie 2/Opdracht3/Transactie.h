#pragma once
#include <iostream>

typedef enum { bijschrijving, afschrijving } transactieType;

class Transactie
{
	public:
		Transactie(transactieType type, int saldo =0, std::string date = "01/01/2000");
		virtual ~Transactie();

		/*
		type setType(type type);
		std::string setDate();
		float setSaldo();
		*/

		std::string getDate() const;
		float getAmount() const;
		transactieType getType() const;

	private:
		transactieType typeTransactie; //Beste naming ooit

		float saldo;
		std::string date;

};

