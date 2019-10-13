#include <iostream>
#include <algorithm>

#include "TQueue.h"


template<class T>
void Sort(T arr[], int size)
{}

template<>
void Sort(float arr[], int size) {
	std::sort(arr, arr + size, std::less<float>());

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << " | Sorted float array." << std::endl;
}

template<>
void Sort(std::string arr[], int size) {
	std::sort(arr, arr + size);

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << " | Sorted string array." << std::endl;
}

int main()
{
	float nummertjes[4] = { 0.1, -12, 500};

	Sort<float>(nummertjes, 3);

	std::string textjes[4] = { "Banaan", "Aardappel", "Demonisch Fruit", "Egel" };

	Sort(textjes, 4);

	TQueue<float> floatQueue(nummertjes);

	floatQueue.put(20);

	floatQueue.print();

	std::cout << "Array Size: " << floatQueue.size << std::endl;
	
	std::cout << "Eerste element in array: " << floatQueue.get() << std::endl;


	return 0;
}

