#include <iostream>
#include "ConcurrentVector.h"


void addToVector() {
	ConcurrentVector vec;
	vec.push_back_safe();
}


int main()
{
	std::thread t1(addToVector);
	std::thread t2(addToVector);
	std::thread t3(addToVector);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}



