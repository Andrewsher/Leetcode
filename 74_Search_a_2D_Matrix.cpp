class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if(m <= 0) return false;
		int n = matrix[0].size();
		bool result = false;

		// i, j 表示当前查找的位置
		// 从右上角开始查找
		int i = 0, j = n - 1;
		while(i < m && j >= 0) {
			if(matrix[i][j] > target) j--;
			else if(matrix[i][j] < target) i++;
			else {
				result = true;
				break;
			}
		}
		return result;
	}
};