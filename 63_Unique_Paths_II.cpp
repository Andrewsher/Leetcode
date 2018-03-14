class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        		int result = 0;
        		int m = obstacleGrid.size();
        		if(m <= 0) return 0;
        		int n = obstacleGrid[0].size();
        		if(n <= 0) return 0;

        		// array[i][j] 表示位置(i, j)到目标的路径数目
        		int** array = new int* [m];
        		for(int i = 0; i < m; i++) {
        			array[i] = new int[n];
        		}
        		
        		// 目的地
        		if(1 == obstacleGrid[m - 1][n - 1]) array[m - 1][n - 1] = 0;
        		else array[m - 1][n - 1] = 1;
        		// 最右边一列或最下边一行
        		for(int i = m - 2; i >= 0; i--) {
        			if(1 == obstacleGrid[i][n - 1]) array[i][n - 1] = 0;
        			else array[i][n - 1] = array[i + 1][n - 1];
        		}
        		for(int j = n - 2; j >= 0; j--) {
        			if(1 == obstacleGrid[m - 1][j]) array[m - 1][j] = 0;
        			else array[m - 1][j] = array[m - 1][j + 1];
        		}
        		//其他位置
        		for(int i = m - 2; i >= 0; i--) {
        			for(int j = n - 2; j >= 0; j--) {
        				// 不可通行
        				if(1 == obstacleGrid[i][j]) array[i][j] = 0;
        				// 可以通行
        				else array[i][j] = array[i][j + 1] + array[i + 1][j];
        			}
        		}

        		result = array[0][0];

        		for(int i = 0; i < m; i++) {
        			delete [] array[i];
        			array[i] = NULL;
        		}
        		delete [] array;
        		array = NULL;

        		return result;
	}
};