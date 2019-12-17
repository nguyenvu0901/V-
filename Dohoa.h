//Ham Do Hoa 
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//Ve HCN
void HCNTextDong(int toadoX, int toadoY, int chieudai, int chieucao)
{
	for (int i = toadoX; i < toadoX + chieudai; i++)
	{
		gotoXY(i, toadoY);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoY; i < toadoY + chieucao; i++)
	{
		gotoXY(toadoX + chieudai - 1, i);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoX + chieudai - 1; i >= toadoX; i--)
	{
		gotoXY(i, toadoY + chieucao - 1);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
	for (int i = toadoY + chieucao - 1; i >= toadoY; i--)
	{
		gotoXY(toadoX, i);
		textcolor(1926);
		cout << " ";
		Sleep(5);
		textcolor(7);
	}
}
void HCNText(int toadoX, int toadoY, int chieudai, int chieucao)
{
	for (int i = toadoX; i < toadoX + chieudai; i++)
	{
		gotoXY(i, toadoY);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
	for (int i = toadoY; i < toadoY + chieucao; i++)
	{
		gotoXY(toadoX + chieudai - 1, i);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
	for (int i = toadoX + chieudai - 1; i >= toadoX; i--)
	{
		gotoXY(i, toadoY + chieucao - 1);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
	for (int i = toadoY + chieucao - 1; i >= toadoY; i--)
	{
		gotoXY(toadoX, i);
		textcolor(1926);
		cout << " ";
		textcolor(7);
	}
}
void VeHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauSet)
{
	SetColor(mauSet);
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, toadoY);
		if (i == toadoX)
			cout << (char)218;
		else if (i == chieudai + toadoX)
			cout << (char)191;
		else
			cout << (char)196;
	}
	for (int i = toadoX; i <= chieudai + toadoX; i++)
	{
		gotoXY(i, chieucao + toadoY);
		if (i == toadoX)
			cout << (char)192;
		else if (i == chieudai + toadoX)
			cout << (char)217;
		else
			cout << char(196);
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(toadoX, i);
		cout << (char)179;
	}
	for (int i = toadoY + 1; i < chieucao + toadoY; i++)
	{
		gotoXY(chieudai + toadoX, i);
		cout << (char)179;
	}
	SetColor(7);
}
void ToMauHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mauText)
{
	textcolor(mauText);
	for (int i = toadoY + 1; i < toadoY + chieucao; i++)
	{
		for (int j = toadoX + 1; j < chieudai + toadoX; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
	textcolor(7);
}
void XoaHCN(int toadoX, int toadoY, int chieudai, int chieucao, int mau)
{
	textcolor(mau);
	for (int j = toadoY + 1; j < toadoY + chieucao; j++)
	{
		for (int i = toadoX + 1; i < toadoX + chieudai; i++)
		{
			gotoXY(i, j);
			cout << " ";
		}
	}
}
//Logo
//Huong Dan
int MauNenHuongDan = 7;
//Xoa Man Hinh
void XoaManHinhChinh()
{
	textcolor(7);
	for (int i = 6; i < 36; i++)
	{
		for (int j = 51; j < 176; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
}
void XoaManHinhTuyChon(int toadoX, int toadoY, int chieudai, int chieucao)
{
	textcolor(188);
	for (int i = toadoY; i < chieucao + toadoY; i++)
	{
		for (int j = toadoX; j < toadoX + chieudai; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
}
void XoaManhinh(int toadoX, int toadoY, int dai, int cao) {
	SetColor(7);
	for (int i = toadoY; i < toadoY + cao; i++)
	{
		for (int j = toadoX; j < dai; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
}
//logo
void logoTEXT(int toadoX, int toadoY) {
	string s;
	ifstream filein;
	filein.open("logo.txt", ios::in);
	int h = toadoY;
	while (true)
	{
		getline(filein, s);
		gotoXY(toadoX, h++);
		cout << s << endl;
		if (filein.eof()) {
			break;
		}
	}
}

//interface
void Interface() {
	ShowCur(0);
	HCNText(4, 16, 40, 20);
	textcolor(112);
	//đường gạch chia màn hình
	for (int i = 0; i < 38; i++)
	{
		gotoXY(48, i);
		cout << " ";
	}
	//đường gạch trên khung điều khiển
	for (int i = 0; i < 48; i++)
	{
		gotoXY(i, 13);
		cout << " ";
	}
	textcolor(7);
	for (int i = 49; i < 176; i++)
	{
		gotoXY(i, 5);
		cout << (char)205;
	}
	logoTEXT(78, 0);
	gotoXY(21, 18);
	SetColor(9);
	cout << "MENU";
	textcolor(7);
}
//giao diện lưu file
void InterfacceSave(int toadoX, int toadoY) {
	ToMauHCN(toadoX, toadoY, 70, 22, 55);
	textcolor(55);
	for (int i = toadoX + 2; i < toadoX + 69; i++)
	{
		gotoXY(i, 25);
		cout << "-";
	}
	for (int i = toadoX + 2; i < toadoX + 69; i++)
	{
		gotoXY(i, toadoY + 19);
		cout << "-";
	}
	for (int i = toadoY + 4; i <= 24; i++)
	{
		gotoXY(toadoX + 5, i);
		cout << "|";
		gotoXY(toadoX + 65, i);
		cout << "|";
	}
	for (int i = toadoX + 5; i < toadoX + 66; i++)
	{
		gotoXY(i, toadoY + 3);
		cout << "-";
	}
	for (int i = toadoX + 6; i < toadoX + 65; i++)
	{
		gotoXY(i, toadoY + 5);
		cout << "-";
	}
	VeHCN(toadoX + 20, toadoY + 16, 40, 2, 15);
	gotoXY(toadoX + 8, toadoY + 17);
	textcolor(52);
	cout << "File name:";
	gotoXY(toadoX + 7, toadoY + 4);
	cout << "Name";
	gotoXY(toadoX + 40, toadoY + 4);
	cout << "Type";
	textcolor(55);
	gotoXY(toadoX + 18, toadoY + 20);
	cout << "SAVE";
	gotoXY(toadoX + 45, toadoY + 20);
	cout << "CANCEL";
}
void InterfacceOpen(int toadoX, int toadoY) {
	textcolor(7);
	for (int i = toadoX + 2; i < toadoX + 69; i++)
	{
		gotoXY(i, toadoY + 17);
		cout << "-";
	}
	for (int i = toadoX + 1; i <= toadoX + 70; i++)
	{
		gotoXY(i, toadoY + 19);
		cout << "-";
	}
	for (int i = toadoY + 4; i <= toadoY + 16; i++)
	{
		gotoXY(toadoX + 5, i);
		cout << "|";
		gotoXY(toadoX + 65, i);
		cout << "|";
	}
	for (int i = toadoX + 5; i < toadoX + 66; i++)
	{
		gotoXY(i, toadoY + 3);
		cout << "-";
	}
	for (int i = toadoX + 6; i < toadoX + 65; i++)
	{
		gotoXY(i, toadoY + 5);
		cout << "-";
	}
	for (int i = toadoX + 1; i < toadoX + 71; i++)
	{
		gotoXY(i, toadoY + 1);
		cout << "-";
	}
	for (int i = toadoY + 2; i < toadoY + 19; i++)
	{
		gotoXY(toadoX + 1, i);
		cout << "|";
		gotoXY(toadoX + 70, i);
		cout << "|";
	}
	VeHCN(toadoX + 15, toadoY + 17, 35, 2, 15);
	textcolor(4);
	gotoXY(toadoX + 7, toadoY + 4);
	cout << "Name";
	gotoXY(toadoX + 40, toadoY + 4);
	cout << "Type";
	textcolor(9);
	gotoXY(toadoX + 4, toadoY + 18);
	cout << "File name:";
	gotoXY(toadoX + 52, toadoY + 18);
	cout << "OPEN";
	gotoXY(toadoX + 60, toadoY + 18);
	cout << "CANCEL";
}