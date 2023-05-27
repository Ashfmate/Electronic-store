#pragma once
#include <string>
#include <fstream>
#include <sstream>

class Login_page
{
public:
	bool operator()();
private:
	void draw();
	bool leave();
	bool confirm();
	bool check_user_and_pass();
	std::string read();
	std::string read_hidden();
	std::ifstream& getline(std::ifstream& file, std::stringstream& sstr);
private:
	std::string username = "";
	std::string password = "";
	bool exit = false;
};