/*
inline 함수는 매크로함수와 달리 일반 함수처럼 정의할 수 있으며, 매크로 함수처럼 연산속도가 빠르다.

하지만 매크로 함수에는 있지만, 인라인 함수에는 없는 장점이 있다.

매크로는 자료형에 의존적이지 않지만 inline 함수는 자료형에 의존적이어서
데이터의 손실이 발생할 수 있다.

이는 template를 활용하여 극복할 수 있는 문제이다.
*/

#include <iostream>

using namespace std;

template <typename T>
inline T SQUARE(T x)
{
	return x*x
}

int main()
{
	cout << SQUARE(5.5) << endl;
	cout << SQUARE(12) << endl;

	return 0;
}
