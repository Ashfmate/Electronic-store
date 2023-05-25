#include "Login_page.h"
#include <fmt/format.h>
#include <fmt/color.h>
#include <conio.h>

using fmt::print;

Login_page::Choices Login_page::operator()()
{
	while (true)
	{
		system("cls");
		draw();
		if (choice_control())
			break;
	}
	return choice;
}

void Login_page::draw()
{
	print(fmt::fg(fmt::color::blue), "Sign in if you already have an account, otherwise make one by choosing register\n");
	print((choice == Choices::Login) ? fmt::fg(fmt::color::green) : fmt::fg(fmt::color::white), "\t\t\t{}\n", login_expression);
	print((choice == Choices::Register) ? fmt::fg(fmt::color::green) : fmt::fg(fmt::color::white), "\t\t\t{}\n", register_expression);
	print((choice == Choices::Quit) ? fmt::fg(fmt::color::green) : fmt::fg(fmt::color::white), "\t\t\t{}\n", quit_expression);
	print(fmt::fg(fmt::color::blue), "Press enter to confirm");
}

bool Login_page::choice_control()
{
	if (choice < Choices::Count && choice > Choices::Start)
	{
		int temp = _getch();
		if (temp == 0 || temp == 0xE0) temp = _getch();
		else if (temp == 13) return true;

		if (temp == up_key)
			choice = Choices(int(choice) - 1);
		else if (temp == down_key)
			choice = Choices(int(choice) + 1);
	}
	else
		(choice == Choices::Start) ? choice = Choices::Quit : choice = Choices::Login;
	return false;
}