#include<iostream>
#include<Windows.h>
using namespace std;
//Хорошо      живет     на     свете      Винни      Пух

//////////    Прототипы   //////////
int StringLength(char arr[], const int SIZE);
void ToUpper(char arr[], const int SIZE);
void ToLower(char arr[], const int SIZE);
bool Is_palindrome(char arr[], const int SIZE);
void Shrink(char arr[], const int SIZE);
bool Is_int_number(char arr[], const int SIZE);
int To_int_number(char arr[], const int SIZE);
bool Is_bin_number(char arr[], const int SIZE);
int Bin_to_dec(char arr[], const int SIZE);
bool Is_hex_number(char arr[], const int SIZE);
int hex_to_dec(char arr[], const int SIZE);

void main()
{
	setlocale(LC_ALL, "");
	const int size = 60;
	char stroka[size] = "";
	//char buffer[size] = "";
	SetConsoleCP(1251);
	cin.getline(stroka, size);
	//for (int i = 0; i < StringLength(stroka, size); i++)cout << (int)stroka[i] << endl;
	cout << (Is_hex_number(stroka, size) ? "Maybe HEX" : "Not HEX") << endl;
	//if(Is_hex_number(stroka, size)) cout<< hex_to_dec(stroka, size);
	cout << stroka << endl;
	Shrink(stroka, size);
	cout << stroka << endl;
	ToUpper(stroka, size);
	cout << stroka << endl;
	ToLower(stroka, size);
	cout << stroka << endl;
	cout << (Is_palindrome(stroka, size) ? "Is palindrome!" : "Not palindrome...") << endl;

	cout << (Is_int_number(stroka, size) ? "Maybe INT" : "Not INT") << endl;
	cout << To_int_number(stroka, size) << endl;
	cout << (Is_bin_number(stroka, size) ? "Maybe BIN" : "Not BIN") << endl;
	cout << "Bin: " << Bin_to_dec(stroka, size) << endl;

	SetConsoleCP(866);
	cout << "Length Stroka = " << StringLength(stroka, size) << endl;
}
//////////    Реализация   //////////
int StringLength(char arr[], const int SIZE)
{
	int lngth = 0;
	for (int i = SIZE - 1; i >= 0; i--)
	{
		if (arr[i] != NULL)
		{
			lngth = i + 1;
			break;
		}
	}
	return lngth;
}
void ToUpper(char arr[], const int SIZE)
{
	for (int i = 0; i < StringLength(arr, SIZE); i++)for (int i = 0; i < StringLength(arr, SIZE); i++)if (arr[i] > 'a' && arr[i] < 'z' || arr[i] > 'а' && arr[i] < 'я')arr[i] = char(int(arr[i]) - 32); else arr[i] = char(int(arr[i]));
}
void ToLower(char arr[], const int SIZE)
{
	for (int i = 0; i < StringLength(arr, SIZE); i++) if (arr[i] > 'A' && arr[i] < 'Z' || arr[i] > 'А' && arr[i] < 'Я')arr[i] = char(int(arr[i]) + 32); else arr[i] = char(int(arr[i]));
}
bool Is_palindrome(char arr[], const int SIZE)
{
	for (int i = 0; i < StringLength(arr, SIZE) / 2; i++)if (arr[i] != arr[StringLength(arr, SIZE) - 1 - i])return 0;
	return 1;
}
void Shrink(char arr[], const int SIZE)
{
	for (int i = 0; i < StringLength(arr, SIZE) - 1; i++)
	{
		if (arr[i] == ' ')
		{
			for (int ii = i + 1; i < StringLength(arr, SIZE) - 1; ii++)
			{
				if (arr[ii] != ' ')
				{
					for (int iii = 0; iii <= StringLength(arr, SIZE) - ii - 1; iii++)
					{
						arr[i + iii + 1] = arr[ii + iii];
						arr[ii + iii] = NULL;
					}
					break;
				}
			}
		}
	}
}
bool Is_int_number(char arr[], const int SIZE)
{
	for (int i = 0; i < StringLength(arr, SIZE); i++)if (arr[i] < '0' || arr[i] > '9')return 0;
	return 1;
}
int To_int_number(char arr[], const int SIZE)
{
	if (Is_int_number(arr, SIZE))
	{
		int n = 0;
		for (int i = 0; i < StringLength(arr, SIZE); i++)
		{
			n *= 10;
			n += ((int)arr[i] - 48);
		}
		return n;
	}
}
bool Is_bin_number(char arr[], const int SIZE)
{
	for (int i = 0; i < StringLength(arr, SIZE); i++)if (arr[i] != '0' && arr[i] != '1')return 0;
	return 1;
}
int Bin_to_dec(char arr[], const int SIZE)
{
	if (Is_bin_number(arr, SIZE))
	{
		int n = 0;
		for (int i = StringLength(arr, SIZE) - 1; i >= 0; i--)
		{
			//cout << "i= " << i << " n= " << n << " arr[StringLength(arr, SIZE)-i-1]-48 = " << int(arr[StringLength(arr, SIZE) - i - 1] - 48) << endl;
			int st = 1;
			for (int ii = i - 1; ii >= 0; ii--)st *= 2;
			//cout << "st= " << st << endl;
			n += (st * (int)(arr[StringLength(arr, SIZE) - i - 1] - 48));
			//cout << "n= " << n << endl;
		}
		return n;
	}
}
bool Is_hex_number(char arr[], const int SIZE)
{
	char HEX[] = "ABCDEF1234567890";
	for (int i = 0; i < StringLength(arr, SIZE); i++)
	{
		bool Hex = 0;
		for (int ii = 0; ii < 16; ii++)
		{
			if (arr[i] == HEX[ii])
			{
				Hex = 1;
				break;
			}
			//cout << "arr[i]= " << arr[i] << " HEX[ii]= " << HEX[ii] << " Hex= " << Hex << endl;
		}
		if (!Hex)return 0;
	}
	return 1;
}
int hex_to_dec(char arr[], const int SIZE)
{
	if (Is_hex_number(arr, SIZE))
	{
		int n = 0;
		char HEX[] = "0123456789ABCDEF";
		int Hex = 0;
		
		for (int i = StringLength(arr, SIZE) - 1; i >= 0; i--)
		{
			for (int i = 0; i < StringLength(arr, SIZE); i++)
			{
				for (int j = 0; j < 16; j++)
				{
					if (arr[i] == HEX[j])
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
		return n;
	}
}
