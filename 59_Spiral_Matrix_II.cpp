#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > res;
		vector<int> tmp;
		for(int i = 0; i < n; i++) {
			tmp.clear();
			for(int j = 0; j < n; j++) {
				tmp.push_back(0);
			}
			res.push_back(tmp);
		}

		int leftEdge = 0, rightEdge = n - 1, upEdge = 0, downEdge = n - 1;
		int i = 0, j = 0;
		int num = 1;
		while(true) {
			for(i = leftEdge; i <= rightEdge; i++) {
				res[upEdge][i] = num;
				// cout << res[upEdge][i] << " ";
				num++;
			}
			// cout << endl;
			upEdge++;
			if(upEdge > downEdge) break;

			for(i = upEdge; i <= downEdge; i++) {
				res[i][rightEdge] = num;
				// cout << res[i][rightEdge] << " ";
				num++;
			}
			// cout << endl;
			rightEdge--;
			if(rightEdge < leftEdge) break;

			for(i = rightEdge; i >= leftEdge; i--) {
				res[downEdge][i] = num;
				num++;
			}
			downEdge--;
			if(downEdge < upEdge) break;

			for(i = downEdge; i >= upEdge; i--) {
				res[i][leftEdge] = num;
				num++;
			}
			leftEdge++;
			if(leftEdge > rightEdge) break;
		}
		
		
		

		// for(i = 0; i < n; i++) {
		// 	for(j = 0; j < n; j++) {
		// 		cout << res[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		return res;
	}
};

int main() {
	Solution* S = new Solution();
	S->generateMatrix(3);
	return 0;
}