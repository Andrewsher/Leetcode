/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > permute(vector<int>& nums) {
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
				tmpRes = permute(tmpNums);

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
