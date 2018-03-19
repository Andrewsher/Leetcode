#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int zeros = -1, twos = nums.size();
		for(int i = 0; i < nums.size(); i++) {
			if(nums[i] == 0) zeros++;
			else if(nums[i] == 2) twos--;
		}
		for(int i = 0; i <= zeros; i++) nums[i] = 0;
		for(int i = zeros + 1; i < twos; i++) nums[i] = 1;
		for(int i = twos; i < nums.size(); i++) nums[i] = 2;
	}
};
