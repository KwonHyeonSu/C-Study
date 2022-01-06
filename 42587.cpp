//programmers 스택큐/프린터문제 

#include <iostream>
#include <vector>

using namespace std;

void vprint(vector<int> v);
int location = 2;
vector<int> Push_back(vector<int> &v)
{
	v.push_back(v[0]);
	v.erase(v.begin());
	
	return v;
}


int solution(vector<int> priorities, int &location) {
    int answer = 0;
    int flag = 0;
    
    while(priorities.size()!=0)
    {
	    for(int i=1;i<priorities.size(); i++)
	    {
	    	if(priorities[0] < priorities[i])
	    	{
	    		Push_back(priorities);
	    		flag = 1;
	    		if(location == 0) location = priorities.size()-1;
	    		else location--;
	    		break;
			}
			else flag = 0;
		}
		
		//front is biggest 
		if(flag == 0)
		{
			priorities.erase(priorities.begin());
			if(location == 0) break;
			else answer++;
			location--;
		}	
	}
	++answer;
    return answer;
}

void Init(vector<int> &priorities)
{
	priorities.push_back(2);
	priorities.push_back(1);
	priorities.push_back(3);
	priorities.push_back(2);
}

void vprint(vector<int> v)
{
	cout <<"---vprint---" << endl;
	
	for(int i=0;i<v.size();i++)
	{
		cout << v[i] << " ";
	}
	
	cout << "loc : " << location << endl;
	return;
}



int main()
{
	vector<int> priorities;
	
	Init(priorities);
	
	cout << solution(priorities, location);
	
	
	return 0;
}
