#include "../Headers/Login_page.h"
#include <fmt\format.h>
#include <fmt\color.h>
#include <conio.h>

using fmt::print;

bool Login_page::operator()()
{
	while (true)
	{
		system("cls");

		if (leave())
			return false;

		draw();

		if (!confirm())
			continue;

		if (check_user_and_pass())
			return true;
	}
}

void Login_page::draw()
{
	system("cls");
	print(fmt::fg(fmt::color::blue), "Enter your username: ");
	username = read();
	print(fmt::fg(fmt::color::blue), "\nEnter your password: ");
	password = read_hidden();
}

bool Login_page::leave()
{
	print(fmt::fg(fmt::color::red), "Do you want to go back? (y/n) ");
	return _getch() == 'y';
}

bool Login_page::confirm()
{
	print(fmt::fg(fmt::color::red), "\nDo you confirm? (y/n) ");
	return _getch() == 'y';
}

bool Login_page::check_user_and_pass()
{
	std::string path = "Profiles/" + username + ".txt";
	std::ifstream file(path);
	if (!file)
		return false;
	std::stringstream line;
	while (getline(file, line))
	{
		while (line)
		{
			std::string word;
			line >> word;
			if (word == "password")
			{
				line >> word >> word;
				return word == password;
			}
			else
				break;
		}
	}
	return false;
}

std::string Login_page::read()
{
	std::string result;
	for (auto answer = _getch(); answer != 13 && answer != ' '; answer = _getch())
	{
		result.push_back(answer);
		_putch(answer);
	}
	return result;
}

std::string Login_page::read_hidden()
{
	std::string result;
	for (auto answer = _getch(); answer != 13 && answer != ' '; answer = _getch())
	{
		result.push_back(answer);
		_putch('*');
	}
	return result;
}

std::ifstream& Login_page::getline(std::ifstream& file, std::stringstream& sstr)
{
	std::string line;
	std::getline(file, line);
	sstr.str(line);
	return file;
}
