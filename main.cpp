#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
	public:
    	vector<int> twoSum(vector<int>& nums, int target) 
    	{
        	vector<int> sol;
        	for(int i =0; i < nums.size(); ++i)
        	{
            	int diff = target - nums[i];
            	if(numDiff.find(diff) != numDiff.end())
            	{
                	sol.push_back(numDiff[diff]);
                	sol.push_back(i);
               		return sol;
            	}
            	numDiff[nums[i]] = i;
        }
        return sol;
    }
	private:
    	unordered_map<int, int> numDiff;
};
