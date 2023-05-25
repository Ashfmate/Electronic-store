#include <iostream>
#include <fmt/format.h>
#include <conio.h>
#include <Windows.h>
#include "Login_page.h"

int main()
{
	Login_page log;
	log();
	while (!_kbhit());
}