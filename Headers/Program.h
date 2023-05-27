#pragma once
#include <array>
#include <functional>
#include "../Headers/Signing_page.h"

class Program
{
public:
	Program();
	int start();
private:
	std::array<std::function<void()>, size_t(Signing_page::Choices::Count)> funcs;
};

