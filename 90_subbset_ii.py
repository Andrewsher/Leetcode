'''
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
'''
from copy import deepcopy
class Solution:
	def get_power_subset(self, nums: list) -> list:
		result = []
		if nums is None or len(nums) == 0:
			return [[]]
		
		tmp_integer = nums[0]
		tmp_nums = nums.copy()
		tmp_nums.pop(0)
		
		tmp_result = self.get_power_subset(nums=tmp_nums)
		result.extend(tmp_result)
		tmp_result_1 = deepcopy(tmp_result)
		for i in range(len(tmp_result_1)):
			tmp_result_1[i].insert(0, tmp_integer)
		result.extend(tmp_result_1)

		final_result = []
		for item in result:
			if item not in final_result:
				final_result.append(item)


		return final_result


	def subsetsWithDup(self, nums: list) -> list:
		nums.sort()
		return self.get_power_subset(nums)


if __name__ == '__main__':
	S = Solution()
	x = [1, 2, 2]
	print(S.subsetsWithDup(x))
