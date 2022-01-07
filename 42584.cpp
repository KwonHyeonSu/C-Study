#include <string>
//프로그래머스 - 주식가격

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int count = 0;
    
    for(int i = 0; i < prices.size(); i++)
    {
    	count = 0;
    	for(int j = i+1; j < prices.size(); j++)
    	{
    		if(prices[i] <= prices[j]) count++;
    		else{
    			count++;
    			break;
			}
		}
		answer.push_back(count);
	}
       
    return answer;
}

int main()
{
	vector<int> prices = {1, 2, 3, 2, 3};
	
	solution(prices);

	return 0;
}
