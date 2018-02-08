class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, length = 0;
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        for(int i = 0; i < s.size(); i++) {
            int left = i, right = i;
            while (right < s.size() - 1 && s[right] == s[right + 1]) right++;
            while (right < s.size() - 1 && left > 0 && s[left - 1] == s[right + 1]) {
                right++;
                left--;
            }
            if (length < right - left + 1) {
                length = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, length);
    }
};
