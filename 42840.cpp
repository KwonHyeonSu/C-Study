#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int max(int a, int b)
{
	return (a>b)?a:b;
}
vector<int> solution(vector<int> answers)
{
	vector<int> answer;
	
	vector<int> two = {2,1,2,3,2,4,2,5};
	vector<int> three = {3,3,1,1,2,2,4,4,5,5};
	
	int s[3] = {0,0,0};
	for(int i = 0 ; i < answers.size(); i++)
	{
		if(answers[i] == (i%5)+1){
			s[0]++;
		}
		if(answers[i] == two[i%8]){
			s[1]++;
		}
		if(answers[i] == three[i%10]){
			s[2]++;
		}
	}
	
	int m = max(max(s[0], s[1]),s[2]);

	for(int i=0;i<3;i++)
	{
		if(m == s[i])
			answer.push_back(i+1);
	}
	
	return answer;
}

int main()
{
	vector<int> v = {5,4,3,2,2,5,4,3,2,2};
	solution(v);
	return 0;
}
