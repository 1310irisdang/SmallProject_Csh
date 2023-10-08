#include <iostream>
using namespace std;
bool kiem(char a[], int n);
void xoa(char a[], int& n);
int dem(char a[], int n, int d);
int main()
{
	char a[100];
	int n;
	cout << "Nhap ho va ten: ";
	do {
		cin.getline(a, 100);
		n = strlen(a);
		if (kiem(a, n) == false)
			cout << "Ho va ten khong co ky tu dac biet hay so.\nNhap sai! Nhap lai: ";
	} while (kiem(a, n) == false);

	//Xoa khoang trang dau tien
	while (a[0] == ' ')
	{
		xoa(a, n);
	}

	//Xoa khoang trang giua cac tu
	int k = 1;
	while (a[k] != '\0')
	{
		if (isspace(a[k - 1]) && isspace(a[k]))
		{
			for (int j = k; j < n; j++)
				a[j] = a[j + 1];
			n--;
		}
		else
			k++;
	}
	//Viet hoa chu cai dau
	if (islower(a[0]))
		a[0] = toupper(a[0]);
	int l = 1;
	while (a[l] != '\0')
	{
		if (isspace(a[l - 1]) && islower(a[l]))
			a[l] = toupper(a[l]);
		else
		{
			if (isupper(a[1]))
				a[1] = tolower(a[1]);
			l++;
			a[l] = tolower(a[l]);
		}
	}
	cout << "Ho va ten cua ban la: " << a << endl;

	//Xuat Ho
	cout << "Ho: ";
	int m = 0;
	while (a[m] != ' ')
	{
		cout << a[m];
		m++;
	}
	cout << endl;

	//Xuat phan con lai
	int d = 0;
	bool f = false;
	d = dem(a, n, d);
	if (d > 1)
	{
		cout << "Chu lot: ";
		while (d > 0)
		{
			while (a[m] != ' ') // Nguyen Duong Anh Duy
			{
				cout << a[m];
				m++;
				f = true;
			}
			d--;
			m++;
			if (f)
				cout << " ";

		}
		cout << endl;
		cout << "Ten: ";
		while (a[m] != '\0')
		{
			cout << a[m];
			m++;
		}
		cout << endl;
	}
	else
	{
		cout << "Ten: ";
		while (a[m] != '\0')
		{
			if (a[m] == ' ')
				m++;
			else
			{
				cout << a[m];
				m++;
			}
		}
		cout << endl;
	}
	return 0;
}
bool kiem(char a[], int n)
{
	for (int i = 0; i < n; i++)
		if (isalpha(a[i]) == 0 && a[i] != ' ') //Khong phai ky tu chu cung khong phai cho trong thi sai
			return false;
	return true;
}
void xoa(char a[], int& n)
{
	for (int i = 0; i < n; i++)
		if (a[i] == ' ')
		{
			for (int j = i; j < n; j++)
				a[j] = a[j + 1];
			n--;
			break;
		}
}
int dem(char a[], int n, int d)
{
	for (int i = 0; i < n; i++)
		if (isspace(a[i]))
			d++;
	return d;
}

/*
#include <iostream>
#include <conio.h>

using namespace std;

char a[13][6];
int level, c;
int x, y;

void menu();
bool check(char a[][6], int x, int y);
void pick(char a[][6]);
void show(char a[][6], int level);

int main()
{
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 6; j++)
			a[i][j] = '*';
	do {
		system("cls");
		menu();
		cin >> c;
		switch (c)
		{
		case 1: pick(a); _getch(); break;
		case 2: show(a, 0); _getch(); break;
		}
	} while (c != 3);
	cout << "Byeeeeeeeee\n";

}

void menu()
{
	cout << "Chao mung ban da den voi hang hang khong cc!!\n";
	cout << "\n1. Dat ve may bay\n2. Xem cho ngoi\n3. Thoat\n\nLua chon chua ban: ";
}

bool check(char a[][6], int x, int y)
{
	if (a[x - 1][y - 1] == 'X') return 1;
	return 0;
}

void pick(char a[][6])
{
	cout << "Ban muon ngoi ghe nao?\n\n1. Thuong gia\n2. Pho thong\n3. Tiet kiem\n\nLua chon cua ban: ";
	do {
		cin >> level;
		if (level < 1 || level > 3) cout << "Type again: ";
	} while (level < 1 || level > 3);

	show(a, level);
	do {
		cout << "Nhap toa do ghe ban muon dat (x va y): ";
		cin >> x >> y;
		if (check(a, x, y) == 1) cout << "Cho nay da co nguoi dat, vui long chon lai!!\n";
	} while (check(a, x, y) == 1);

	a[x - 1][y - 1] = 'X';
	cout << "Dat ve thanh cong!!";
}

void show(char a[][6], int level)
{
	cout << "\t Cot (y):";
	for (int i = 1; i <= 6; i++)
		cout << i << "\t";
	cout << endl;

	switch (level)
	{
	case 1:
		for (int i = 0; i < 2; i++)
		{
			cout << "Hang (x) " << i + 1 << "\t";
			for (int j = 0; j < 6; j++)
				cout << a[i][j] << "\t";
			cout << endl;
		}
		break;

	case 2:
		for (int i = 2; i < 7; i++)
		{
			cout << "Hang (x) " << i + 1 << "\t";
			for (int j = 0; j < 6; j++)
				cout << a[i][j] << "\t";
			cout << endl;
		}
		break;

	case 3:
		for (int i = 7; i < 13; i++)
		{
			cout << "Hang (x) " << i + 1 << "\t";
			for (int j = 0; j < 6; j++)
				cout << a[i][j] << "\t";
			cout << endl;
		}
		break;

	default:
		for (int i = 0; i < 13; i++)
		{
			cout << "Hang (x) " << i + 1 << "\t";
			for (int j = 0; j < 6; j++)
				cout << a[i][j] << "\t";
			cout << endl;
		}
	}
}*/