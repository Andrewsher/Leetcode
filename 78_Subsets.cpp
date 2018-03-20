#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > combine(vector<int> & nums, int index, int n) {
		// 从nums中的index开始，选择n个数
		cout << "  从" << index << "开始选取" << n << "个数" << endl;
		vector<vector<int> > result;
		if(index + n > nums.size()) return result;
		if(n <= 0) return result;
		if(n == 1) {
			for(int i = index; i + n <= nums.size(); i++) {
				vector<int> temp2;
				temp2.clear();
				temp2.push_back(nums[i]);
				result.push_back(temp2);
			}
			cout << "选取1个数，共有" << result.size() << "个" << endl;
			return result;
		}
		for(int i = index; i + n <= nums.size(); i++) {
			vector<vector<int> > temp = combine(nums, i + 1, n - 1);
			cout << "temp.size() = " << temp.size() << endl;
			for(int j = 0; j < temp.size(); j++) {
				temp[j].push_back(nums[i]);
			}
			for(int j = 0; j < temp.size(); j++) {
				result.push_back(temp[j]);
			}
		}
		return result;
	}
	vector<vector<int> > subsets(vector<int>& nums) {
		vector<vector<int> > result;
		vector<vector<int> > temp;
		for(int i = 1; i <= nums.size(); i++) {
			cout << "目前选取" << i << "个数" << endl;
			temp.clear();
			temp = combine(nums, 0, i);
			for(int j = 0; j < temp.size(); j++) {
				result.push_back(temp[j]);
			}
		}
		vector<int> temp2;
		result.push_back(temp2);
		return result;
	}
};

int main() {
	Solution* S = new Solution();
	vector<int> nums;
	int array[] = {1, 2, 3};
	for(int i = 0; i < 3; i++) nums.push_back(array[i]);
	vector<vector<int> > result = S->subsets(nums);
	for(int i = 0; i < result.size(); i++) {
		for(int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	delete S;
	return 0;
}