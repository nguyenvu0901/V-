
#include"Run.h"



int main() {
	resizeConsole(1300, 650);
	Interface();
	Menu();
	while (true)
	{
		RunMenu();
	}
}
