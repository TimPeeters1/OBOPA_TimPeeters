#include <iostream>
#include <algorithm>
#include <functional>
#include <set> 
#include <numeric>
#include <vector>



template<typename T>
void printList(std::vector<T> list) {
	for (int i = 0; i < list.size(); i++)
	{
		std::cout << list[i] << " ";
	}
	std::cout << std::endl;
}

std::vector<std::string> splitStringArray(std::vector<std::string> list, std::string word) {
	std::sort(list.begin(), list.end());

	bool split = false;

	std::vector<std::string> list1;
	std::vector<std::string> list2;

	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] == word) {
			split = true;
		}

		if (!split) {
			list1.push_back(list[i]);
		}
		else {
			list2.push_back(list[i]);
		}
	}

	return list2;
}

std::vector<std::string> makeUppercase(std::vector<std::string> list) {
	std::vector<std::string> upList;

	int toupper(int c);

	for (int i = 0; i < list.size(); i++)
	{
		std::string word = list[i];

		std::transform(word.begin(), word.end(), word.begin(), ::toupper);

		upList.push_back(word);
	}

	return upList;

}

std::vector<std::string> removeDouble(std::vector<std::string> list) {
	std::set<std::string> s;

	for (int i = 0; i < list.size(); i++)
	{
		s.insert(list[i]);
	}

	std::vector<std::string> undoubleList(s.begin(), s.end());

	return undoubleList;

}

std::vector<double> removeNegative(std::vector<double> list) {
	std::vector<double> newList;
	
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i] > 0) {
			newList.push_back(list[i]);
		}
	}

	return newList;
}

std::vector<double> checkEven(std::vector<double> list) {
	std::vector<double> newList;

	for (int i = 0; i < list.size(); i++)
	{
		int x = (int) list[i];

		if (x % 2 == 0) {
			newList.push_back(list[i]);
		}
	}

	return newList;
}

std::vector<double> doSums(std::vector<double> list) {
	std::vector<double> newList;

	//som van lijst.

	double sum = std::accumulate(list.begin(), list.end(), 0);
	newList.push_back(sum);

	//gemiddelde van lijst.
	
	double average = std::accumulate(list.begin(), list.end(), 0.0)/list.size();
	newList.push_back(average);

	//product van lijst.
	double product = std::accumulate(list.begin(), list.end(), 1, std::multiplies<double>());
	newList.push_back(product);
	

	return newList;

}

int main() {
	std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)

	// 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
	printList(splitStringArray(colours, "purple"));

	// 2) alle elementen UPPERCASE te maken.
	printList(makeUppercase(colours));

	// 3) alle dubbele te verwijderen
	printList(removeDouble(colours));
	

	std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) alle negatieve elementen te verwijderen
	printList(removeNegative(numbers));

	// 2) voor alle elementen te bepalen of ze even of oneven zijn
	printList(checkEven(numbers));

	// 3) de som, het gemiddelde, en het product van alle getallen te berekenen
	printList(doSums(numbers));
}
