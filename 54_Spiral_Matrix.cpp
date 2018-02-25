#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> >& matrix) {
		static const int UP = 0;
		static const int DOWN = 1;
		static const int RIGHT = 2;
		static const int LEFT = 3;
		int direction = RIGHT;
		vector<int> result;
		if(matrix.size() <= 0 || matrix[0].size() <= 0) return result;
		int* tag = new int[matrix.size() * matrix[0].size()];	// tag[i * matrix[0].size() + j] 表示第i行j列
		for(int i = 0; i < matrix.size() * matrix[0].size(); i++) { // Initialize
			tag[i] = 0;
		}
		int i = 0, j = 0;	//当前位置
		while(1) {
			if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) break;
			if(1 == tag[i * matrix[0].size() + j]) break;
			//处理
			result.push_back(matrix[i][j]);
			tag[i * matrix[0].size() + j] = 1;
			// 进一
			switch(direction) {
				case UP:
					if(0 == i || 1 == tag[(i - 1) * matrix[0].size() + j]) {
						direction = RIGHT;
						j++;
					}
					else {
						i--;
					}
					break;
				case DOWN:
					if(matrix.size() - 1 == i || 1 == tag[(i + 1) * matrix[0].size() + j]) {
						direction = LEFT;
						j--;
					}
					else {
						i++;
					}
					break;
				case LEFT:
					if(0 == j || 1 == tag[i * matrix[0].size() + j - 1]) {
						direction = UP;
						i--;
					}
					else {
						j--;
					}
					break;
				case RIGHT:
					if(matrix[0].size() - 1 == j || 1 == tag[i * matrix[0].size() + j + 1]) {
						direction = DOWN;
						i++;
					}
					else {
						j++;
					}
					break;
				default: break;
			}
		}
		delete [] tag;
		return result;
    	}
};

int main() {
	Solution* A = new Solution();
	vector<vector<int> > matrix;
	vector<int> tmp;
	for(int i = 0; i < 3; i++) {
		tmp.clear();
		for(int j = 1; j <= 3; j++) {
			tmp.push_back(i * 3 + j);
		}
		matrix.push_back(tmp);
	}

	cout << "matrix = "<< endl;
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	cout << "result = " << endl;
	vector <int> result;
	result = A->spiralOrder(matrix);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	cout << "result.size() = " << result.size() << endl;

	return 0;

}