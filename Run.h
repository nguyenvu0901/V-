#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<Windows.h>


using namespace std;
int pointer = 21;
ofstream fileout;
ifstream filein;
typedef struct FileName {
	string name;
};

int soluong = 0;
FileName a[10];
string Input1;
#include"Dohoa.h"
#include"Xuli.h"
#include"Function.h"

string str[] = {
"            NEW DOCCUMENT           ",
"             OPEN FILE              ",
"             SAVE FILE              ",
};
void Menu() {
	int j = 21;
	for (int i = 0; i < sizeof(str) / sizeof(*str); i++)
	{
		gotoXY(6, j++);
		cout << str[i];
	}
}
void RunMenu() {
	if (_kbhit()) {
		char c = _getch();
		if (c == -32)
		{
			c = _getch();
			if (c == 72)//mũi tên lên 
			{
				if (pointer == 21)//nếu nó ở đầu thì chuyển xuống cuối 
				{
					Menu();
					pointer = 21 - 1 + sizeof(str) / sizeof(*str);
				}
				else {
					Menu();
					pointer--;
				}
			}
			else if (c == 80)//mũi tên xuống
			{
				if (pointer == 21 - 1 + sizeof(str) / sizeof(*str))
				{
					Menu();
					pointer = 21;
				}
				else
				{
					Menu();
					pointer++;
				}
			}
		}
		else if (c == 13)//enter
		{
			textcolor(188);
			gotoXY(6, pointer);
			cout << "                                    ";
			gotoXY(6, pointer);
			cout << str[pointer - 21];
			textcolor(7);
			switch (pointer)
			{
			case 21:
				//new doccument
				NewDocument();
				break;
			case 22:
				//open file
				//OpenFile(78, 10);
				mo();
				break;
			case 23:
				//save
				SaveFile(82, 10, Input1);
				break;
			}
			textcolor(7);
			system("cls");
			Interface();
			Menu();
		}
		else if (c == 27) {
			exit(0);
		}
	}
	textcolor(188);
	gotoXY(6, pointer);
	cout << str[pointer - 21];
	textcolor(7);
}