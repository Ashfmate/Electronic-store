#include "../Headers/Program.h"

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
