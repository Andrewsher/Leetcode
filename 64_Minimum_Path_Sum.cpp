#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int> >& grid) {
		int m = grid.size();
		if(m <= 0) return 0;
		int n = grid[0].size();
		if(n <= 0) return 0;
		int result = 0;

		//array[i][j]表示从(i, j)出发到达目的的路径长度
		int** array = new int* [m];
		for(int i = 0; i < m; i++) {
			array[i] = new int[n];
		}

		// 目的地
		array[m - 1][n - 1] = grid[m - 1][n - 1];
		// 最右边一行或最下边一列
		for(int i = m - 2; i >= 0; i--) {
			array[i][n - 1] = grid[i][n - 1] + array[i + 1][n - 1];
		}
		for(int j = n - 2; j >= 0; j--) {
			array[m - 1][j] = grid[m - 1][j] + array[m - 1][j + 1];
		}
		// 其他位置
		for(int i = m - 2; i >= 0; i--) {
			for(int j = n - 2; j >= 0; j--) {
				// 向右、向下的两条路径，取长度更小的一条
				int min = array[i + 1][j] < array[i][j + 1]? array[i + 1][j] : array[i][j + 1];
				array[i][j] = grid[i][j] + min;
			}
		}
		result = array[0][0];

		 // 回收arrat的空间
		for(int i = 0; i < m; i++) {
			delete[] array[i];
			array[i] = NULL;
		}
		delete [] array;
		array = NULL;

		return result;
	}
};

int main() {
	Solution* S = new Solution();
	delete S;
	return 0;
}