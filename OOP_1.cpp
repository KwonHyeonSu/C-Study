#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

const int name_len = 100;

typedef struct
{
	int id, cash;
	char name[name_len];
}Account;

Account accArr[100];
int acc_num = 0;

int ShowMenu()
{
	int input;
	cout << "\n-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
	cin >> input;
	return input;
}

void Case_1()
{
	int id, cash;
	char name[name_len];

	cout << "\n\n[계좌개설]" << endl;

	cout << "계좌 ID: ";
	cin >> id;

	cout << "이 름: ";
	cin >> name;

	cout << "입금액: ";
	cin >> cash;

	accArr[acc_num].id = id;
	strcpy(accArr[acc_num].name, name);
	accArr[acc_num].cash = cash;
	acc_num++;
}

void Case_2()
{
	int id, cash;
	cout << "\n\n[입    금]" << endl;
	cout << "계좌ID: ";
	cin >> id;

	

	for (int i = 0; i < acc_num; i++)
	{
		if (accArr[i].id == id)
		{
			cout << "입금액: ";
			cin >> cash;

			accArr[i].cash += cash;
			cout << "입금 완료";
			break;
		}
	}

	cout << "계좌를 찾을 수 없습니다." << endl;
	return;
}

void Case_3()
{
	int id, cash;
	cout << "\n\n[출    금]" << endl;
	cout << "계좌ID: ";
	cin >> id;

	for (int i = 0; i < acc_num ; i++)
	{
		if (accArr[i].id == id)
		{
			cout << "출금액: ";
			cin >> cash;

			accArr[i].cash -= cash;
			cout << "출금 완료" << endl;
			return;
		}
	}

	cout << "ID를 찾을 수 없습니다." << endl;

	return;
}

void Case_4()
{
	cout << "\n\n[계좌정보 전체 출력]" << endl;
	if (acc_num == 0)
	{
		cout << "계좌 정보가 없습니다." << endl << endl;

		return;
	}

	for (int i = 0; i < acc_num; i++)
	{
		cout << "계좌ID: " << accArr[i].id << endl;
		cout << "이름 : " << accArr[i].name << endl;
		cout << "잔액 : " << accArr[i].cash << endl << endl;
	}

	return;
}

int main()
{
	while (true)
	{
		int input = ShowMenu();
		
		if (input == 5)
		{
			cout << "\n\n[프로그램 종료]" << endl;
			break;
		}

		switch (input)
		{
			case 1:
				Case_1();
				break;

			case 2:
				Case_2();
				break;

			case 3:
				Case_3();
				break;

			case 4:
				Case_4();
				break;

			default:
				cout << "잘못 입력하셨습니다. 다시 입력하세요.\n\n" << endl;
		}
			
	}
	return 0;
}
