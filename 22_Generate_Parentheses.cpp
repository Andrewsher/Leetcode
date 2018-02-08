class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        list<string> tmp;
        if(n <= 0) return result;
        result = generateParenthesis(n - 1);    // 递归
        if(result.empty()) {
            result.push_back("()");
            return result;
        }
        tmp.clear();
        for(int i = 0; i < result.size(); i++) {    // 为每一个位置添加一对'()'
            for(int j = 0; j < result[i].length(); j++) {
                tmp.push_back(result[i].substr(0, j) + "()" + result[i].substr(j, result[i].length() - j));
                // cout << tmp.back() << endl;
            }
        }
        result.clear();
        tmp.sort();
        tmp.unique();
        // cout << "----------" << endl;
        // cout << "tmp.size() = " << tmp.size() << endl;
        for(string s : tmp) {
            cout << s << endl;
            result.push_back(s);
        }
        tmp.clear();
        return result;
    }
};
