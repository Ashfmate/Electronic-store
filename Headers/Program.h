#pragma once
#include <array>
#include <functional>
#include "../Headers/Signing_page.h"

class Program
{
public:
	Program();
	int start();
public:
	enum Pages : size_t
	{
		Signing,
		Login,
		Register,
		Quitting,
		Count
	};
private:
	typedef Signing_page::Choices sign_choice;
private:
	Pages sign_choice_to_Pages_converter(sign_choice input);
private:
	std::array<std::function<void()>, Count> funcs;
	bool exit_confirm = false;
	sign_choice Signin_page_result = sign_choice::Start;
};

