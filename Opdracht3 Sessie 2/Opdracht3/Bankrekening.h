#pragma once
#include <iostream>
#include <vector>

#include "Transactie.h"

class Bankrekening
{
	public:
		Bankrekening(float saldo, std::vector<Transactie> transactieHistorie);
		virtual ~Bankrekening();

		Bankrekening operator+=(const Transactie& transactie);

		float getSaldo() const;
		std::vector<Transactie> getHistory() const;

		friend std::ostream& operator<<(std::ostream& os, const Bankrekening& bankrekening);
	private:
		float saldo = 0;
		std::vector<Transactie> transactieHistorie;
};

