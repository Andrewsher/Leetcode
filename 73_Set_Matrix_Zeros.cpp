#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
                void setZeroes(vector<vector<int> >& matrix) {
        		int rows = matrix.size();
        		int cols = matrix[0].size();
        		bool row0 = false;	//标记最上边一行
        		bool col0 = false;	// 标记最左边一列

                                                                            for(int i = 0; i < rows; i++) {
                                                                                if(0 == matrix[i][0]) col0 = true;
                                                                            }
                                                                            for(int j = 0; j < cols; j++) {
                                                                                if(0 == matrix[0][j]) row0 = true;
                                                                            }

        		for(int i = 1; i < rows; i++) {
        			for(int j = 1; j < cols; j++) {
        				if(0 == matrix[i][j]) {
        					matrix[i][0] = matrix[0][j] = 0;
        				}
        			}
        		}


        		for(int i = rows - 1; i >= 1; i--) {
        			for(int j = cols - 1; j >= 1; j--) {
        				if(0 == matrix[i][0] || 0 == matrix[0][j]) {
        					matrix[i][j] = 0;
        				}
        			}
        		}
        		if(true == col0) {
                                                                                                                  cout << "col0 == true" << endl;
        			for(int i = 0; i < rows; i++) matrix[i][0] = 0;
        		}
        		if(true == row0) {
                                                                                                                  cout << "row0 == true" << endl;
        			for(int j = 0; j < cols; j++) matrix[0][j] = 0;
        		}
	}
};

int main() {
        vector<vector<int> > num;
        vector<int> tmp;

        int array[4][4] = {
                {1, 2, 3, 4},
                {5, 0, 5, 2},
                {8, 9, 2, 0},
                {5, 7, 2, 1}
        };

        for(int i = 0; i < 4; i++) {
                tmp.clear();
                for(int j = 0; j < 4; j++) {
                        tmp.push_back(array[i][j]);
                }
                num.push_back(tmp);
        }

        Solution* S = new Solution();
        S->setZeroes(num);

        for(int i = 0; i < num.size(); i++) {
                for(int j = 0; j < num[i].size(); j++) {
                        cout << num[i][j] << " ";
                }
                cout << endl;
        }


        return 0;
}