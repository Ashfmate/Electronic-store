#pragma once
#include <string>

class Electronic_Product
{
public:
	Electronic_Product(std::string name, std::string date) : 
		name(name),
		date(date),
		unique_id(incrementer++)
	{}
private:
	static int incrementer;
	std::string name;
	std::string date;
	const int unique_id;
};

