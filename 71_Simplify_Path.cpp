#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> names;
		string result, temp;
		temp.clear();
		result.clear();
		path = path + "/";
		for(int i = 0; i < path.size(); i++) {
			char c = path[i];
			if(c == '/') {
				if(temp == "..") {
					if(names.size() > 0) names.pop_back();
					else;
				}
				else if(temp == ".") ;
				else if(temp == "") ;
				else names.push_back(temp);
				temp.clear();
			}
			else {
				temp = temp + c;
			}
		}
		for(int i = 0; i < names.size(); i++) {
			result = result + "/" + names[i];
		}
		if(result.empty()) result = result + "/";
		return result;
	}
};