/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        // cout << "result.size() = " << result.size() << endl;
        vector<vector<int> > tmp;
        if(candidates.size() <= 0 || target == 0) return result;
        for(int i = 0; i < candidates.size(); i++) {
            if(candidates[i] == 0) continue;
            if(candidates[i] < target) {
                tmp = combinationSum(candidates, target - candidates[i]);	// {{4,6}, {5,5}}
                // if(tmp.size() == 1) {
                // 	for(int j = 0; j < tmp[0].size(); j++) {
                // 		cout << tmp[0][j] << " ";
                // 	}
                // }
                for(int j = 0; j < tmp.size(); j++) {
                    tmp[j].push_back(candidates[i]);											// {{2, 4, 6}, {2, 5, 5}}
                    // cout << tmp[j].back() << endl;
                    // for(int k = 0; k < tmp[j].size(); k++) {
                    // 	cout << tmp[j][k];
                    // }
                    // cout << endl;
                    result.push_back(tmp[j]);
                }
                // for(int j = 0; j < tmp.size(); j++) {
                // 	result.push_back(tmp[j]);													// add tmp to result
                // }
            }
            else if(candidates[i] == target) {
                vector<int> equal;
                equal.push_back(candidates[i]);
                result.push_back(equal);
                // if(result.back().at(0) == candidates[i]) cout << target << endl;
                break;
            }
            else break;
        }
        // if(target == 1)
        // for(int i = 0; i < result.size(); i++) {
        // 	// print a line
        // 	for(int j = 0; j < result[i].size(); j++) {
        // 		cout << j << " ";
        // 	}
        // 	cout << endl;
        // }
        // cout << endl;

        if(result.size() > 0) {
            // Order result, delete the duplicates
            list<vector<int> > tmp;
            tmp.clear();
            for(int i = 0; i < result.size(); i++) {
                std::sort(result[i].begin(), result[i].end());
                tmp.push_back(result[i]);
            }
            tmp.sort();
            tmp.unique();
            result.clear();
            while(!tmp.empty()) {
                result.push_back(tmp.front());
                tmp.pop_front();
            }
        }

        return result;
    }
};
