#include <iostream>
#include "Parent.h"


Parent moveConstruct(Parent parent) {
	Parent tempParent = parent;
	return tempParent;
}

int main() {

	std::shared_ptr<Parent> p1 = std::make_shared<Parent>("Parent1"); //New Object parent 1
	std::cout << "Reference count: " << p1.use_count() << std::endl;

	std::shared_ptr<Parent> p2 = p1; //Copy parent 1 in parent 2
	std::cout << "Reference count: " << p2.use_count() << std::endl;

	std::shared_ptr<Parent> p3 = std::make_shared<Parent>("Parent3"); //New Object parent 3
	p3 = p1; //Assignment of parent 1 to be parent 3

	std::cout << "Reference count: " << p3.use_count() << std::endl;

	p3->child = nullptr;
	std::cout << *p3 << *p2 << *p1;


	//Voor move Constructor
	Parent p4 = moveConstruct(Parent("Parent4"));

	/*
	Parent* p1 = new Parent("Parent1");
	std::cout << "p1:" << *p1 << std::endl;

	Parent* p2 = new Parent(*p1); // roept de copy constructor aan
	std::cout << "p2:" << *p2 << std::endl;

	Parent* p3 = new Parent("Parent3");
	std::cout << "p3:" << *p3 << std::endl;

	*p3 = *p1; // roept de assignment operator aan
	std::cout << "p1:" << *p3 << std::endl;

	delete p1;
	delete p2;
	delete p3;
	*/

	return 0;
}