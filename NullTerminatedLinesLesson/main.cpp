#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(const char str[]);
char* ToUpper(char str[]);
char* ToLower(char str[]);
char* Shrink(char str[]);
bool isPalindrom(const char str[]);
//char* RemSymbol(char str[], const char symbol);
bool Is_int_number(const char str[]);
char* To_int_number(char str[]);
bool Is_bin_number(const char str[]);
char* Bin_to_dec(char str[]);
bool Is_hex_number(const char str[]);
char* hex_to_dec(char str[]);
//////////////////////////////////////
bool isIPaddress(const char str[]);
bool isMACaddress(const char str[]);

void main()
{
	setlocale(LC_ALL, "");
	const int SIZE = 256;
	//char str[SIZE] = "Хорошо      живет     на     свете      Винни      Пух";
	char str[] = "Аргентина манит негра";
	cout << "Enter str: ";
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	cout << str << endl;
	cout << StringLength(str) << endl;
	cout << strlen(str) << endl;
	ToUpper(str);
	cout << ToUpper(str) << endl;
	cout << Shrink(str) << endl;
	cout << "Строка " << str << (isPalindrom(str) ? " " : " Не") << " является палиндромом" << endl;
	if (Is_int_number(str)) cout << "to int number: " << To_int_number(str) << endl;
	cout << "IPv4: " << (isIPaddress(str) ? str : "not") << endl;

	SetConsoleCP(866);
}
int StringLength(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
char* ToUpper(char str[])
{
	for (int i = 0; str[i]; i++)
	{/*
		if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';
		if (str[i] >= 'а' && str[i] <= 'я')str[i] -= ' ';
		if (str[i] == 'ё')str[i] -= 16;*/
		str[i] = toupper(str[i]);
	}
	return str;
}
char* ToLower(char str[])
{
	for (int i = 0; str[i]; i++)str[i] = tolower(str[i]);
	return str;
}
char* Shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}
char* RemSymbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}
bool isPalindrom(const char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	for (int i = 0; str[i]; i++)buffer[i] = str[i];
	ToUpper(buffer);
	n = strlen(RemSymbol(buffer, ' '));
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return 0;
		}
	}
	delete[] buffer;
	return true;
}
/////////////////
bool Is_int_number(const char str[])
{
	//bool is = 1;
	for (int i = 0; str[i]; i++)if (str[i] >= '0' && str[i] <= '9'); else return 0;
	return 1;
}
char* To_int_number(char str[])
{
	int n = 0;
	for (int i = 0; str[i]; i++)
	{
		n *= 10;
		n += ((int)str[i] - 48);
	}
	return str;

}
bool Is_bin_number(const char str[])
{
	for (int i = 0; str[i]; i++)if (str[i] != '0' && str[i] != '1')return 0;
	return 1;
}
char* Bin_to_dec(char str[])
{
	if (Is_bin_number(str))
	{
		int n = 0;
		for (int i = StringLength(str) - 1; i >= 0; i--)
		{
			int st = 1;
			for (int ii = i - 1; ii >= 0; ii--)st *= 2;
			n += (st * (int)(str[StringLength(str) - i - 1] - 48));
		}
		return str;
	}
}
bool Is_hex_number(const char str[])
{
	char HEX[] = "ABCDEF1234567890";
	for (int i = 0; str[i]; i++)
	{
		bool Hex = 0;
		for (int ii = 0; ii < 16; ii++)
		{
			if (str[i] == HEX[ii])
			{
				Hex = 1;
				break;
			}
		}
		if (!Hex)return 0;
	}
	return 1;
}
char* hex_to_dec(char str[])
{
	if (Is_hex_number(str))
	{
		int n = 0;
		char HEX[] = "0123456789ABCDEF";
		int Hex = 0;

		for (int i = StringLength(str) - 1; i >= 0; i--)
		{
			for (int i = 0; i < StringLength(str); i++)
			{
				for (int j = 0; j < 16; j++)
				{
					if (str[i] == HEX[j])
					{
						Hex = j;
						break;
					}
				}
			}
			int st = 1;
			for (int ii = i - 1; ii >= 0; ii--)st *= 16;
			//cout << "st= " << st << endl;
			n += (st * Hex);
			//cout << "n= " << n << endl;
		}
		return str;
	}
}
bool isIPaddress(const char str[])//проверка: цифры и точки, три точки, числа между точками от 0 до 255
{
	int n = StringLength(str);
	int cont = 0;
	//bool str_int = 1;
	int str_id = 0;
	if (n <= 15)cout << "n: " << n << endl;
	cout << int(str[n]) << endl;
	if (n <= 15)
	{
		for (int ii = 0; str[ii] != '.'; ii++)
		{
			str_id *= 10;
			str_id += (int(str[ii] - 48));
			if (str_id > 255)return 0;
		}
	}
	else return 0;
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
		{

			if (str[i] == '.')
			{
				str_id = 0;
				for (int ii = i; str[ii + 1]; ii++)
				{
					cout << "------ ii+" << str[ii + 1] << endl;
					if (str[ii + 1] == '.' && str[ii] == '.')return 0;
					if ((str[ii] == '.' && str[ii + 1]== n))return 0;

					if (str[ii+1] == '.')continue;
					cout <<"ii: "<<ii << " STR+ " << str[ii + 1] << " str_id: " << str_id << endl;
					str_id *= 10;
					str_id += (int(str[ii+1] - 48));

					cout << "str_id: " << str_id << endl;
					if (str_id > 255)
					{
						cout << "255--" << endl;
						return 0;
					}
				}
				cont++;
			}
		}
		else return 0;
		
	}
	if (cont > 0 && cont <= 3)
	{
		return 1;
	}
	else return 0;
	return 1;
}
bool isMACaddress(const char str[])
{

	return 0;
}

