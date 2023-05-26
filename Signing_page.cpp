#include "Login_page.h"
#include <fmt/format.h>
#include <fmt/color.h>
#include <conio.h>

using fmt::print;

Signing_page::Choices Signing_page::operator()()
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

void Signing_page::draw()
{
	print(fmt::fg(fmt::color::blue), 
		"Sign in if you already have an account, otherwise make one by choosing register\n");
	size_t size = size_t(Choices::Count);
	for (size_t i = size_t(Choices::Start) + 1; i < size; ++i)
	{
		auto text_color =
			(i == size_t(choice)) ?
			fmt::fg(fmt::color::green) : fmt::fg(fmt::color::white);
		print(text_color, "\t\t\t{}\n", expressions[i]);
	}
	print(fmt::fg(fmt::color::blue), 
		"Press enter to confirm");
}

bool Signing_page::choice_control()
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