/*
namespace는 별칭을 사용할 수 있다!

namespace ABC=AAA::BBB::CCC
*/

#include <iostream>

using namespace std;

namespace AAA
{
	namespace BBB
	{
		namespace CCC
		{
			int num=10;
		}
	}
}

int main(void)
{
	namespace ABC = AAA::BBB::CCC;

	cout << ABC::num << endl;
}
