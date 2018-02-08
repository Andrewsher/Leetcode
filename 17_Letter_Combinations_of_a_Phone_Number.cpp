class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string letter[10] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> result;
        result.push_back("");   //初始化result，让它有一个空的串，若最后result为空还是要删去
        vector<string> temp;
        for(int i = 0; i < digits.size(); i++) {
            temp.clear();
            int number = digits[i] - '0';
            if(number > 9 || number < 0) continue; // 输入非数字
            if(letter[number].empty()) {           // 输入0或1,什么也不做
                continue;
            }
            // if(result.empty()) {                   // 输入第一个数字，此时结果为空串，直接把对应的字母作为结果
            //     for(int k = 0; k < letter[number].size(); k++) {
            //         result.push_back((string)letter[number][k]);
            //     }
            //     continue;
            // }                                     
            for(int j = 0; j < result.size(); j++) {    // 输入一个数字，为结果中的每一个字符串都添加新的字符
                for(int k = 0; k < letter[number].size(); k++) {
                    temp.push_back(result[j] + letter[number][k]);
                }
            }
            // 把temp中的结果转到result中
            result.clear();
            for(int l = 0; l < temp.size(); l++) {
                result.push_back(temp[l]);
            }
        }
        if(result.size() == 1 && result[0] == "") result.clear();
        return result;
    }
};
