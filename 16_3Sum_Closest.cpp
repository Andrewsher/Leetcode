class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> sums;    // 存储求和结果
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) { // 获取和target相近的求和结果
            int j = i + 1, k = nums.size() - 1;
            while(j < k) {
                sums.push_back(nums[i] + nums[j] + nums[k]);
                if(sums.back() > target) k--;
                else if(sums.back() < target) j++;
                else return sums.back();
            }
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        }
        
        // 找到sums中和target最为接近的数字
        int result = sums[0];
        int gap = abs(target - sums[0]);
        for(int i = 1; i < sums.size(); i++) {
            if(gap > abs(target - sums[i])) {
                gap = abs(target - sums[i]);
                result = sums[i];
            }
        }
        
        return result;
    }
};
