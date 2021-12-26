#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

class Book
{
private:
	char* title; //책의 제목
	char* isbn; //국제 표준 도서번호
	int price; //책의 정가

public:
	//생성자
	Book(char* mytitle, char* myisbn, int myprice) : price(myprice) 
	{
		title = new char[strlen(mytitle) + 1];
		strcpy(title, mytitle);

		isbn = new char[strlen(myisbn) + 1];
		strcpy(isbn, myisbn);
	}

	//복사생성자
	Book(const Book& copy)
	{
		title = new char[strlen(copy.title) + 1];
		strcpy(title, copy.title);

		isbn = new char[strlen(copy.isbn) + 1];
		strcpy(isbn, copy.isbn);

		price = copy.price;
	}

	//대입연산자
	Book& operator=(const Book& ref)
	{
		delete[] title; //메모리 누수 방지
		delete[] isbn;

		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);

		return *this;
	}

	void ShowInfo()
	{
		cout << "title : " << title << endl;
		cout << "isbn : " << isbn << endl;
		cout << "price : " << price << endl;
	}

	//소멸자
	~Book()
	{
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book
{
private:
	char* DRMkey; //보안관련 키

public:

	//생성자
	EBook(char* myDRMkey, char* mytitle, char* myisbn, int myprice) 
		: Book(mytitle, myisbn, myprice)
	{
		DRMkey = new char[strlen(myDRMkey) + 1];
		strcpy(DRMkey, myDRMkey);
	}

	//복사생성자
	EBook(const EBook& copy) : Book(copy)
	{
		DRMkey = new char[strlen(copy.DRMkey) + 1];
		strcpy(DRMkey, copy.DRMkey);

	}

	//대입연산자
	EBook& operator=(const EBook& ref)
	{
		Book::operator=(ref);

		delete[] DRMkey;

		DRMkey = new char[strlen(ref.DRMkey) + 1];
		strcpy(DRMkey, ref.DRMkey);

		return *this;
	}

	void ShowEBookInfo()
	{
		ShowInfo();
		cout << "DRMkey : " << DRMkey << endl;
	}

	//소멸자
	~EBook()
	{
		delete[] DRMkey;
	}
};

int main()
{
	EBook ebook1((char*)"좋은 c++ book", (char*)"555-12345", (char*)"fdx0w", 10000);
	EBook ebook2 = ebook1;
	ebook2.ShowEBookInfo();
	cout << endl;
	EBook ebook3((char*)"dumy", (char*)"dumy", (char*)"dumy", 0);
	ebook3 = ebook2;
	ebook3.ShowEBookInfo();

	return 0;
}
