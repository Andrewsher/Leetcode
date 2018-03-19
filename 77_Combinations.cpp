#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
		vector<int> temp;
		if(n <= 0 || k <= 0 || n < k) return result;
		if(k == 1) {
			for(int i = 1; i <= n; i++) {
				temp.clear();
				temp.push_back(i);
				result.push_back(temp);
			}
			return result;
		}
		// j个数中间挑选k - 1 个数，然后再加一个数
		for(int j = n - 1; j >= k - 1; j--) {
			// cout << "j = " << j << endl;
			vector<vector<int> > tmpRes = combine(j, k - 1);
			for(int i = 0; i <tmpRes.size(); i++) {
				tmpRes[i].push_back(j + 1);
				// for(int k = 0; k < tmpRes[i].size(); k++) cout << tmpRes[i][k] << endl;
				result.push_back(tmpRes[i]);
			}
		}
		return result;
	}
};

int main() {
	Solution* S = new Solution();
	vector<vector<int> > v = S->combine(4, 2);
	cout << "v.size() = " << v.size() << endl;
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	delete S;
	return 0;
}