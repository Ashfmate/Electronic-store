#include <conio.h>
#include "Headers/Signing_page.h"

int main()
{
	switch (Signing_page{}())
	{
	case Signing_page::Choices::Login:
		break;
	case Signing_page::Choices::Register:
		break;
	case Signing_page::Choices::Quit:
		break;
	default:
		break;
	}
	while (!_kbhit());
}