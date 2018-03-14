#include <iostream>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if(1 == m || 1 == n) return 1;
		int result = 1;
		// 分配内存
		int** array = new int* [m];
		for(int i = 0; i < m; i++) {
			array[i] = new int[n];
		}

		for(int i = 0; i < m; i++) {
			array[i][0] = 1;
		}
		for(int j = 0; j < n; j++) {
			array[0][j] = 1;
		}
		for(int i = 1; i < m; i++) {
			for(int j = 1; j < n; j++) {
				array[i][j] = array[i - 1][j] + array[i][j - 1];
			}
		}
		result = array[m - 1][n - 1];
		// 回收内存
		for(int i = 0; i < m; i++) {
			delete[] array[i];
			array[i] = NULL;
		}
		delete [] array;
		array = NULL;
		
		return result;
		// else return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	}
};

int main() {
	Solution* S = new Solution();
	cout << S->uniquePaths(3, 7);
	delete S;
	S = NULL;
	return 0;
}