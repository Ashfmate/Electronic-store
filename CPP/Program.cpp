#include "../Headers/Program.h"
#include <conio.h>

#define PAUSE while(!_kbhit())

Program::Program()
{
	funcs[Signing] = [&]()
	{
		Signin_page_result = Signing_page{}();
	};
	funcs[Login] = [&]()
	{};
	funcs[Register] = [&]()
	{};
	funcs[Quitting] = [&]()
	{};
}

int Program::start()
{
	funcs[Signing]();

	auto converted = sign_choice_to_Pages_converter(Signin_page_result);
	
	funcs[converted]();

	PAUSE;
	return 0;
}

Program::Pages Program::sign_choice_to_Pages_converter(sign_choice input)
{
	switch (input)
	{
	case sign_choice::Login:
		return Login;
		break;
	case sign_choice::Register:
		return Register;
		break;
	case sign_choice::Quit:
		return Quitting;
		break;
	}
	return Signing;
}
