#include<iostream>
#include<vector>
#include<Windows.h>
#include<string>
#include<conio.h>
#include<list>
#include "../Book.cpp"
#include<stdio.h>
using namespace std;
void pageHeader();
void gotoxy(int x, int y);
int listPrinter(int n, vector<string> menu);
string menutaker(int n);
void Booker(vector<Book>& Books, string x);
Book FindBook(vector<Book>& Books, string name, string author, int n, string condition);
Book GetBook();

int main()
{
	vector<string> menu = { "ADD BOOK","UPDATE BOOK","DELETE BOOK","TOTAL BOOKS","EXIT"};
	vector<Book> Books;
	while (true)
	{
		int size = menu.size();
		system("cls");
		pageHeader();
		listPrinter(size, menu);
		string x = menutaker(size);
		Booker(Books, x);
		Sleep(2000);
		if (x == "5")
		{
			break;
		}
	}
}
// 
void Booker(vector<Book> &Books,string x)
{
	if (x == "1")
	{
		Books.push_back(GetBook());
	}
	if (x == "2")
	{
		string name,author;
		cin >> name;
		cin >> author;
		Book temp = FindBook(Books, name, author,Books.size() - 1,"up");
		cout << temp;
		
	}
	if (x == "3")
	{
		string name, author;
		cin >> name;
		cin >> author;
		FindBook(Books, name, author, Books.size() - 1, "del");
		
	}
	if (x == "4")
	{
		cout << Books.size();
	}
}

// 
Book FindBook(vector<Book> &Books,string name,string author,int n,string condition)
{

	if (n == -1)
	{
		Book x;
		return x;
	}
	if (Books[n].name == name)
	{
		if (condition == "up")
		{
			Books[n].author = author;
			return Books[n];
		}
		if (condition == "del")
		{
			Books.erase(Books.begin() + n);
			Book x;
			return x;
		}
	}
	return FindBook(Books, name, author,n - 1,condition);
}
// 
Book GetBook()
{
	Book x = Book();
	cin >> x.name;
	cin >> x.author;
	cin >> x.year;
	return x;
}
// Get menu Option
string menutaker(int n)
{
	string x;
	gotoxy(75, n + 12);
	cout << "CHOOSE: ";
	gotoxy(83, n + 12);
	cin >> x;
	return x;
}
// Link List printer
int listPrinter(int n,vector<string> menu)
{
	if (n == 0)
	{
		return 0;
	}
	gotoxy(75,n + 10);
	cout << to_string(n) <<"   " << menu[n - 1];
	return listPrinter(n - 1, menu);
}
// Header of page
void pageHeader()
{
	system("cls");
	gotoxy(38, 5);
	cout << "*********************************************************************************************" << endl;
	gotoxy(38, 6);
	cout << "#                                    LIBRARY MANAGEMENT SYTEM                               #" << endl;
	gotoxy(38, 7);
	cout << "*********************************************************************************************" << endl;

}

void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

