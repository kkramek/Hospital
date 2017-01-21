#include "stdafx.h"
#include "Menu.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Menu *menu;
	menu = new Menu();

	menu->ShowMenu();

	return 0;
}

