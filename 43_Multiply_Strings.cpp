
class Solution {
public:
	string multiply(string num1, string num2) {
		string* str = new string();	//逆序
		string* result = new string();	//顺序
		//int acc = 0;	//进位位
		if(num1.length() == 1 && num1[0] == '0') return "0";
		if(num2.length() == 1 && num2[0] == '0') return "0";
		str->append(220, '0');
		for(int i = 0; i < num1.length(); i++) {
			for(int j = 0; j < num2.length(); j++) {
				// 化为int型
				int n1 = num1.at(num1.length() - i - 1) - '0';
				int n2 = num2.at(num2.length() - j - 1) - '0';
				// 求 i + j 位的数字
				int acc = n1 * n2 + (str->at(i + j) - '0');
				int k = 0;
				// cout << acc << endl;
				// 累加，从第i + j 位开始
				while(acc > 0) {
					// cout << acc << endl;
					// 个位替换之
					// cout << "line 26" << endl;
					// str->replace(i + j + k, 1, 1, acc % 10 + '0');
					str->at(i + j + k) = acc % 10 + '0';
					// 十位数字拿出来与前一位相加，形成新的进位位
					// cout << "line 29" << endl;
					acc = acc / 10 + (str->at(i + j + k + 1) - '0');
					// cout << "line 31" << endl;
					k ++;
				}
				// cout << "line 34" << endl;
				// str->replace(i + j + 1, 1, 1, str->at(i + j + 1) + (tmp / 10));
			}
			// cout << "line 37" << endl;
		}
		// cout << "line 39" << endl;
		// 逆序转化为顺序
		int found = str->find_last_not_of('0');
		// cout << "line 42" << endl;
		// cout << "found = " << found << endl;
		for(int i = found; i >= 0; i--){
			result->append(1, str->at(i));
		}

		delete str;
		return *result;
	}
};
