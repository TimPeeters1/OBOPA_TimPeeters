#include <iostream>
#include "Parent.h"

Parent::Parent(std::string name) {
    this->name = name;
    std::string childName = "Child Of " + name;

	//Make Child Unique Pointer.
	this->child = std::make_unique<Child>(childName);
}

Parent::Parent(const Parent& other) {
    this->name = other.name;

	std::cout << "Constructed: " << this->name << std::endl;

	//Changed pointer to unique pointer
	this->child = std::unique_ptr<Child>(new Child(std::move(*other.child)));
}

Parent::~Parent() {
    std::cout << "Destructed: " << this->name << std::endl;
}

Parent& Parent::operator=(const Parent& other) {
    std::cout << "Parent assignment " << std::endl;

    if (this == &other) return *this;

    this->name = other.name;

	//Changed pointer to unique pointer
	this->child = std::unique_ptr<Child>(new Child(std::move(*other.child)));

    return *this;
}

Parent::Parent(Parent&& other) noexcept
{
	std::cout << "Moving: " << other.name << " @ " << &other << " To:" << this << std::endl;
	name = std::move(other.name);
	child = std::move(other.child);

	other.name = "(nodata: has been moved)";
	other.child = nullptr;
	
}

std::ostream& operator<<(std::ostream& os, const Parent& parent) {
	if (parent.child != NULL) {
		os << parent.name << "," << *parent.child << std::endl;
	}
	else {
		os << parent.name << ", with no children" << std::endl;
	}

    return os;
}
