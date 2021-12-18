#(더블)포인터에서 참조자(Reference)를 사용

#include <iostream>

using namespace std;

int main(void)
{
	int a = 5;
	int* p = &a;
	int** dp = &p;

	cout << a << " " << *p  << " " << **dp << endl;

	int& r = a;
	int* (&pr) = p;
	int** (&dpr) = dp;

	cout << r << " " << *pr << " " << **dpr << endl;


	return 0;
}
