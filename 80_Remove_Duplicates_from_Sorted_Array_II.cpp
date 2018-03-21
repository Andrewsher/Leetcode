#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if(nums.size() <= 0) return 0;
		sort(nums.begin(), nums.end());
		int count = 1;
		int i = 1, j = 1;
		int length = nums.size();
		for(i = 1, j = 1; j < length; j++) {
			// i是处理后的index，j是处理前的index
			if(nums[j] == nums[j - 1]) {
				count++;
			}
			else {
				count = 1;
			}
			if(count <= 2) {
				nums[i] = nums[j];
				i++;
			}
			cout << "nums[j] = " << nums[j] << " count = " << count << " i = " << i << endl;
		}
		for(; i < length; i++) {
			cout << i << " pop_back" << endl;
			nums.pop_back();
		}
		return nums.size();
	}
};

int main() {
	Solution* S = new Solution();
	int array[] = {1, 1, 1, 2};
	vector<int> nums;
	for(int i = 0; i < 4; i++) nums.push_back(array[i]);
	int length = S->removeDuplicates(nums);
	for(int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}