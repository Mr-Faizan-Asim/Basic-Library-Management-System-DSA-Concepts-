#include<iostream>
using namespace std;
class Book {
public:
    string name;
    string author;
    int year;
    Book(string name, string author, int year)
    {
        this->name = name;
        this->author = author;
        this->year = year;
    }
    Book()
    {

    }
  
    friend ostream& operator<<(ostream& out, const Book& t)
    {
        out << t.name<<endl;
        out << t.author << endl;
        out << t.year << endl;
        return out;
    }
    
};