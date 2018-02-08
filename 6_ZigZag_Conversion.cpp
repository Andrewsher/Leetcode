class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        string* str = new string[numRows];
        
        int row = 0;    //当前行
        int direction = 0;  //当前运动方向，1（向下），-1（向上）
        
        for(int i = 0; i < s.length(); i++) {   //逐个填入列表
            str[row].push_back(s[i]);  //在相应行填入字符
            if(row == 0) {  //位于最高行
                direction = 1;  //向下运动
            }
            if(row == numRows - 1) {    //位于最低行
                direction = -1;     //向上运动
            }
            row += direction;   //运动
        }
        
        s.clear();
        for(int i = 0; i < numRows; i++) {  //逐行添加到s中
            s.append(str[i]);
        }
        delete[] str;
        
        return s;
    }
};
