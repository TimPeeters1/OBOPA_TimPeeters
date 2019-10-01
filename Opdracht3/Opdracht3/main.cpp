#include <iostream>
#include "Bankrekening.h"

int main()
{
	Bankrekening rekening = Bankrekening(0, std::vector<Transactie>());

	std::cout << rekening;

	Transactie transactie1 = Transactie(bijschrijving, 100, "30/09/2019");

	rekening += transactie1;

	std::cout << rekening;

	Transactie transactie2 = Transactie(afschrijving, 300, "1/10/2019");

	rekening += transactie2;

	std::cout << rekening;

	return 0;
}
