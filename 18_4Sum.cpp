class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end()); // 排序
        if(nums.size() < 4) return result;  // 输入数字少于4个，直接返回
        int a = 0, b = 1, c = 2, d = 3;     // index
        for(a = 0; a < nums.size() - 3; a++) {
            for(b = a + 1; b < nums.size() - 2; b++) {
                c = b + 1;
                d = nums.size() - 1;
                while(c < d) {
                    int sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if(sum > target) d--;
                    else if(sum < target) c++;
                    else {
                        result.push_back((vector<int>){nums[a], nums[b], nums[c++], nums[d--]});
                        while(c < d && nums[c] == nums[c - 1]) c++; // 除去重复的数字，注意c和d已经改变，故而nums[c] ?= nums[c - 1]
                        while(c < d && nums[d] == nums[d + 1]) d--; // nums[d] ?= nums[d + 1]
                    }
                }
                while(b < nums.size() - 2 && nums[b] == nums[b + 1]) b++;
            }
            while(a < nums.size() - 3 && nums[a] == nums[a + 1]) a++;
        }
        return result;
    }
};
