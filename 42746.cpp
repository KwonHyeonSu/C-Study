//프로그래머스 42746 

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b)
{
	return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s;
	
	for(auto num : numbers)
		s.push_back(to_string(num));
		
	sort(s.begin(), s.end(), cmp);
	
	if(s[0] == "0") return "0";
	
	for(auto num : s)
	{
		answer += num;
	}
    return answer;
}

int main()
{
	vector<int> numbers = {3, 0, 30, 34, 5, 9};
	solution(numbers);
		
	return 0;
}
