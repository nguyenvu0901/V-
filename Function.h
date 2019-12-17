int slfile = 0;
string s;
void ReadFile(FileName a[]) {
	ifstream filein;
	filein.open("File.txt", ios::in);
	while (true) {
		getline(filein, a[slfile++].name);
		if (filein.eof())
			break;
	}
	filein.close();
}
void SaveTXT(FileName a[]) {
	ofstream fileout("File.txt", ios::out);
	for (int i = 0; i < soluong; i++)
	{
		fileout << a[i].name << endl;
	}
	fileout.close();
}
void NewDocument() {
	XoaManhinh(50, 6, 175, 31);
	gotoXY(72, 8);
	int Y = 8, X = 72;
	ShowCur(1);
	XuLyNhap_Text(Input1, X, Y, 174);
	gotoXY(0, 0);
	system("pause");
}
void mo()
{
	openfile(s);
}
/*
void OpenFile(int toadoX, int toadoY) {
	InterfacceOpen(toadoX, toadoY);
	ReadFile(a);
	for (int i = 0; i < slfile; i++)
	{
		gotoXY(toadoX + 7, toadoY + 6 + i);
		cout << a[i].name;
		gotoXY(toadoX + 40, toadoY + 6 + i);
		cout << ".txt";
	}
	string s;
	string chuoi;
	ShowCur(1);
	textcolor(7);
	int pointer2 = toadoY + 18;
	gotoXY(toadoX + 16, pointer2);
	XuLyNhap_Chu(s, toadoX + 16, pointer2, 20);
	while (true)
	{
		if (pointer2 == toadoY + 18) {
			gotoXY(toadoX + 16, pointer2);
			XuLyNhap_Chu(s, toadoX + 16, pointer2, 20);
			if (pointer2 < toadoY + 18)
				pointer2 = toadoY + 18;
		}
		else if (pointer2 = toadoY + 20) {
			ShowCur(0);
			int pointer1 = toadoX + 52;
			while (true)
			{
				if (_kbhit()) {
					char c = _getch();
					if (c == 13) {
						if (pointer1 == toadoX + 60)
							return;
						else if (pointer1 == toadoX + 52)
						{
							XoaManhinh(50, 6, 175, 31);
							filein.open(s, ios::in);
							getline(filein, chuoi);
							filein.close();

							textcolor(7);
							gotoXY(72, 8);
							cout << chuoi;
							gotoXY(0, 0);
							system("pause");
							return;
						}
						textcolor(7);
					}
					else if (c == -32) {
						c = _getch();
						if (c == 72) {
							pointer2 = pointer2 - 3;
							break;
						}
						else if (c == 80) {
							pointer2 = pointer2 + 3;
							break;
						}
						else if (c == 75) {
							if (pointer1 == toadoX + 52)
								pointer1 = toadoX + 60;
							else

								pointer1 = toadoX + 52;
						}
						else if (c == 77) {
							if (pointer1 == toadoX + 60)
								pointer1 = toadoX + 52;
							else
								pointer1 = toadoX + 60;
						}
						gotoXY(pointer1, toadoY + 18);
					}
				}
				gotoXY(pointer1, toadoY + 20);
				if (pointer1 == toadoX + 52) {
					textcolor(188);
					gotoXY(toadoX + 52, toadoY + 18);
					cout << "SAVE";
					gotoXY(toadoX + 60, toadoY + 18);
					textcolor(9);
					cout << "CANCEL";
				}
				else if (pointer1 == toadoX + 60) {
					textcolor(188);
					gotoXY(toadoX + 60, toadoY + 18);
					cout << "CANCEL";
					gotoXY(toadoX + 52, toadoY + 18);
					textcolor(9);
					cout << "SAVE";
				}
				Sleep(100);
			}
		}
	}
	gotoXY(0, 0);
	system("pause");
}
*/
//save file
void SaveFile(int toadoX, int toadoY, string& input)
{
	InterfacceSave(toadoX, toadoY);
	string s;
	ShowCur(1);
	int pointer2 = toadoY + 17;
	for (int i = 0; i < soluong; i++)
	{
		gotoXY(toadoX + 7, toadoY + 6 + i);
		cout << a[i].name;
		gotoXY(toadoX + 40, toadoY + 6 + i);
		cout << ".txt";
	}
	gotoXY(toadoX + 21, pointer2);
	XuLyNhap_Chu(s, toadoX + 21, pointer2, 20);
	while (true)
	{
		if (pointer2 == toadoY + 17) {
			gotoXY(toadoX + 21, pointer2);
			XuLyNhap_Chu(s, toadoX + 21, pointer2, 20);
			if (pointer2 < toadoY + 17)
				pointer2 = toadoY + 17;
		}
		else if (pointer2 = toadoY + 20) {
			ShowCur(0);
			int pointer1 = toadoX + 18;
			while (true)
			{
				if (_kbhit()) {
					char c = _getch();
					if (c == 13) {
						if (pointer1 == toadoX + 45)
							return;
						else if (pointer1 == toadoX + 18 && !s.empty())
						{
							s = s + ".txt";
							a[soluong].name = s;
							soluong++;
							//đưa hàm ghi file vào đây
							/*for (int i = 0; i < soluong; i++)
							{
								if (a[i].name == s) {
									filein.open(s, ios::ate);
									goto Xuli;
								}
							}*/
							SaveTXT(a);
							fileout.open(s, ios::out);
							/*Xuli:*/
							fileout << input;
							return;
						}
						textcolor(7);
					}
					else if (c == -32) {
						c = _getch();
						if (c == 72) {
							pointer2 = pointer2 - 3;
							break;
						}
						else if (c == 80) {
							pointer2 = pointer2 + 3;
							break;
						}
						else if (c == 75) {
							if (pointer1 == toadoX + 18)
								pointer1 = toadoX + 45;
							else

								pointer1 = toadoX + 18;
						}
						else if (c == 77) {
							if (pointer1 == toadoX + 45)
								pointer1 = toadoX + 18;
							else
								pointer1 = toadoX + 45;
						}
						gotoXY(pointer1, toadoY + 20);
					}
				}
				gotoXY(pointer1, toadoY + 20);
				if (pointer1 == toadoX + 18) {
					ToMauHCN(toadoX + 2, toadoY + 19, 34, 2, 27);
					textcolor(27);
					gotoXY(toadoX + 18, toadoY + 20);
					cout << "SAVE";
					ToMauHCN(toadoX + 35, toadoY + 19, 34, 2, 52);
					gotoXY(toadoX + 45, toadoY + 20);
					textcolor(52);
					cout << "CANCEL";
				}
				else if (pointer1 == toadoX + 45) {
					ToMauHCN(toadoX + 35, toadoY + 19, 34, 2, 27);
					textcolor(27);
					gotoXY(toadoX + 45, toadoY + 20);
					cout << "CANCEL";
					ToMauHCN(toadoX + 2, toadoY + 19, 34, 2, 52);
					gotoXY(toadoX + 18, toadoY + 20);
					textcolor(52);
					cout << "SAVE";
				}
				Sleep(100);
			}
		}
	}

	gotoXY(0, 0);
	system("pause");
}
