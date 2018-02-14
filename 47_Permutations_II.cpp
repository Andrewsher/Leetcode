#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int> > result;

		if(nums.size() <= 1) {
			result.push_back(nums);
		}
		else {
			vector<int> tmpNums;
			vector<vector<int> > tmpRes;
			// 每次对nums中的一个数单独提取置于首位
			for(int index = 0; index < nums.size(); index++) {
				if(index != nums.size() - 1 && nums[index] == nums[index + 1]) {
					continue;
				}
				// 初始化
				tmpNums.clear();
				for(int i = 0; i < tmpRes.size(); i++) {
					tmpRes[i].clear();
				}
				tmpRes.clear();
				// 取出除了nums[index]以外的数字
				for(int i = 0; i < nums.size(); i++) {
					if(i == index) continue;
					else tmpNums.push_back(nums[i]);
				}
				// 递归地进行处理
				tmpRes = permuteUnique(tmpNums);

				// cout << "nums[index] = " << nums[index] << endl;
				// cout << "tmpRes = [" << endl;
				// for(int i = 0; i < tmpRes.size(); i++) {
				// 	for(int j = 0; j < tmpRes[i].size(); j++) {
				// 		cout << tmpRes[i][j];
				// 	}
				// 	cout << endl;
				// }
				// cout << "]" << endl;
				// 把nums[index]置于首位
				// for(int i = 0; i < tmpRes.size(); i++) {
				// 	result.push_back({nums[index]});
				// 	for(int j = 0; j < tmpRes[i].size(); j++) {
				// 		result[i].push_back(tmpRes[i][j]);
				// 	}
				// }
				for(int i = 0; i < tmpRes.size(); i++) {
					result.push_back(tmpRes[i]);
					result[result.size() - 1].push_back(nums[index]);
				}
			}

			
		}
		return result;
	}
};

int main() {
	vector<int> x ;
	x.push_back(1);
	for(int i = 1; i <=3; i++) {
		x.push_back(i);
	}
	vector<vector<int> > res;
	Solution* a = new Solution();
	res = a->permuteUnique(x);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " " ;
		}
		cout << endl;
	}
	return 0;
}