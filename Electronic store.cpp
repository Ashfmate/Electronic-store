#include <conio.h>
#include "Signing_page.h"

int main()
{
	Signing_page{}();
	while (!_kbhit());
}