#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		int length = nums.size();
		if(length <= 0) return false;
		sort(nums.begin(), nums.end());
		int left = 0, right = length - 1;
		while(left <= right) {
			cout << "nums[" << left << "] = " << nums[left] << " nums[" << right << "] = " << nums[right] << endl;
			if(left == right && nums[left] == target) return true;
			if(left == right && nums[left] != target) return false;
			int mid = (left + right) / 2;
			if(nums[mid] == target) return true;
			else if(nums[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
			if(nums[left] == nums[right] && nums[left] != target) return false;
		}
		return false;
	}
};

int main() {
	Solution* S = new Solution();
	int array[] = {1, 3};
	vector<int> nums;
	for(int i = 0; i < 2; i++) {
		nums.push_back(array[i]);
	}
	cout << S->search(nums, 3) << endl;
	return 0;
}