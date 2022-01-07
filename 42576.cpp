//프로그래머스 - 해시 - 완주하지 못한 선수

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <typeinfo>

using namespace std;

void vprint(vector<string> v)
{
	for(int i=0;i<v.size();i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int flag = 0;
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i<completion.size(); i++)
    {

    	if(completion[i]!=participant[i]){
    		answer = participant[i];
    		flag = 1;
    		break;
		}
	}
	if(flag == 0) answer = participant[participant.size()-1];
	
	return answer;
}

int main()
{
	vector<string> a = {"leo", "kiki", "eden"};
	vector<string> b = {"eden", "kiki"};
	
	solution(a, b);
	
	return 0;
}
