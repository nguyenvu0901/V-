//Chuoi

char Chuyen1SoSangKiTu(int n)
{
	switch (n)
	{
	case 1:
		return '1';
	case 2:
		return '2';
	case 3:
		return '3';
	case 4:
		return '4';
	case 5:
		return '5';
	case 6:
		return '6';
	case 7:
		return '7';
	case 8:
		return '8';
	case 9:
		return '9';
	case 0:
		return '0';
	}
}
//De Nhap
string ChuyenSoSangString1(int n)
{
	string str;
	int a;
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));
		n = n / 10;
	}
	return str;
}
//De Xuat
string ChuyenSoSangString(int n)
{
	string str;
	int a;
	if (n == 0)
	{
		str = "0";
	}
	while (n > 0)
	{
		a = n % 10;
		Chuyen1SoSangKiTu(a);
		str.insert(str.begin() + 0, Chuyen1SoSangKiTu(a));
		n = n / 10;
	}
	return str;
}
//
void XuLyNhap_Chu(string& InPut, int toadoX, int& toadoY, int LenghtMax)
{
	int toadoXtam;
	char c;
	while (true)
	{
		char c = _getch();
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 46) && InPut.length() < LenghtMax)
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                            ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                 ";
			gotoXY(toadoX, whereY());
			cout << InPut;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 32 && InPut.length() < LenghtMax && InPut.length() != 0 && InPut[whereX() - toadoX - 1] != ' ')
		{
			InPut.insert(InPut.begin() + (whereX() - toadoX), ' ');
			if ((whereX() - toadoX) < InPut.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << InPut;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 13 && InPut.length() > 0)// nếu là phím enter
		{
			toadoY = toadoY + 3;
			break;
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void XuLyNhap_Text(string& InPut, int& toadoX1, int& toadoY, int LenghtMax)
{
	int toadoXtam;
	char c;
	int toadoX = toadoX1;
	int slchu = 0;
	while (true)
	{
		char c = _getch();
		if (whereX() >= 173) {
			toadoY = toadoY + 1;
			gotoXY(toadoX1 - 5, toadoY);
			toadoX = toadoX1 - 5;
			InPut.insert(/*(whereX() - toadoX)*/slchu, "\n");
			slchu++;
		}
		if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)))
		{
			InPut.insert(InPut.begin() + /*(whereX() - toadoX)*/+slchu, c);
			cout << c;
			slchu++;
		}
		else if (c > 32 && c <= 47 || c >= 58 && c <= 64 || c >= 91 && c <= 96 || c >= 123 && c <= 126)
		{
			InPut.insert(InPut.begin() + /*(whereX() - toadoX)*/+slchu, c);
			cout << c;
			slchu++;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			InPut.erase(InPut.begin() + /*(whereX() - toadoX)*/slchu - 1);
			toadoXtam = whereX() - 1;
			ShowCur(0);
			XoaManhinh(50, 6, 175, 31);
			ShowCur(1);
			gotoXY(72, 8);
			cout << InPut;
			gotoXY(toadoXtam, whereY());
			slchu--;
		}
		else if (c == 32)
		{
			InPut.insert(InPut.begin() + /*(whereX() - toadoX)*/slchu, ' ');
			slchu++;
			cout << c;
		}
		else if (c == 13)// nếu là phím enter
		{
			InPut.insert(/*(whereX() - toadoX)*/slchu, "\n");
			toadoY = toadoY + 1;
			gotoXY(toadoX1, toadoY);
			slchu++;
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + InPut.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				toadoY = toadoY + 1;
				break;
			}
			else if (c == 72)
			{
				toadoY = toadoY - 1;
				break;
			}
		}
		else if (c == 27) {
			gotoXY(6, 21);
			pointer = 21;
		}
	}
}
void XuLyNhap_So(int& n, int toadoX, int& toadoY)
{
	int toadoXtam;
	string x;
	x = ChuyenSoSangString1(n);
	char c;
	while (true)
	{
		c = _getch();
		if ((c >= 48 && c <= 57) && whereX() < toadoX + 47)// nếu là số thì
		{
			x.insert(x.begin() + (whereX() - toadoX), c);
			if ((whereX() - toadoX) < x.length() - 1)
			{
				toadoXtam = whereX() + 1;
				gotoXY(toadoX, whereY());
				cout << "                                               ";
				gotoXY(toadoX, whereY());
				cout << x;
				gotoXY(toadoXtam, whereY());
			}
			else
				cout << c;
		}
		else if (c == 8 && whereX() > toadoX)
		{
			x.erase(x.begin() + (whereX() - toadoX) - 1);
			toadoXtam = whereX() - 1;
			gotoXY(toadoX, whereY());
			cout << "                                               ";
			gotoXY(toadoX, whereY());
			cout << x;
			gotoXY(toadoXtam, whereY());
		}
		else if (c == 13 && x.length() > 0)// nếu là phím enter
		{
			toadoY = toadoY + 3;
			n = atoi(x.c_str());
			break;
		}
		else if (c == -32)
		{
			c = _getch();
			if (c == 75 && whereX() > toadoX)
			{
				cout << "\b";
			}
			else if (c == 77 && whereX() < toadoX + x.length())
			{
				gotoXY(whereX() + 1, whereY());
			}
			else if (c == 80)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY + 3;
				break;
			}
			else if (c == 72)
			{
				if (x.empty())
				{
					n = 0;
				}
				else
				{
					n = atoi(x.c_str());
				}
				toadoY = toadoY - 3;
				break;
			}
		}
	}
}
void openfile(string& s)
{
	gotoXY(80, 10);
	textcolor(2);
	cout << "Enter file name : ";
	textcolor(7);
	string name;
	cin >> name;
	name = name + ".txt";
	ifstream filein;
	filein.open(name, ios::in);
	if (filein.fail() == true)
	{
		gotoXY(80, 12);
		cout << "Your file is not exits";
	}
	else
	{
		//while (true) {
		//	{getline(filein, s); 
		//	/*{
		//		filein >> a;
		//		s = s + " ";
		//	}*/
		//	if (filein.eof())
		//		break;
		//}
		//
		//filein >> s;
		getline(filein, s);
		
	}
	gotoXY(80, 15);
	cout << s;
	int X = 80, Y = 17;
	XuLyNhap_Text(s, X, Y, 174);
	system("pause");
}
