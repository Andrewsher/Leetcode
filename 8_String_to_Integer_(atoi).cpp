class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int i = 0, tag = 1;
        i = str.find_first_not_of(' ');
        if(i == str.size()) return 0;
        if(str[i] == '+' || str[i] == '-') {
            if(str[i] == '+') tag = 1;
            else tag = -1;
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9') {
            int temp = result * 10 + (str[i] - '0');
            if(temp / 10 != result) {
                cout << "Up to limits!" << endl;
                if(tag == 1) return INT_MAX;
                else return -1 * INT_MAX - 1;
            }
            result = temp;
            i++;
        }
        result = result * tag;
        return result; 
    }
};
