#pragma once

#include <string>
#include <ostream>
#include "Child.h"

class Parent {
public:
	Parent(std::string name);
	Parent(const Parent& other);
	virtual ~Parent();
	Parent& operator=(const Parent& other);

	//Move Constructor
	Parent(Parent&& other) noexcept;

	friend std::ostream& operator<<(std::ostream& os, const Parent& parent);

	std::unique_ptr<Child> child; //Naar public gewijzigd voor directe modificatie in main.


private:
	std::string name;
};