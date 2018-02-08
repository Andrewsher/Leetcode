class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        list<int> temp;
        
        for(int i = 0; i < nums.size(); i++) {
            temp.push_back(nums[i]);
        }
        temp.sort();
        
        nums.clear();
        for(int n : temp) {
            nums.push_back(n);
        }
        
        
        for(int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0) k--;//大于0,减小
                else if(sum < 0) j++;   //小于0,增大
                else {
                    result.push_back((vector<int>){nums[i], nums[j], nums[k]}); //加入结果
                    // 跳过相同的j和k
                    while(j < k && nums[j] == result.back().at(1)) j++;
                    while(j < k && nums[k] == result.back().at(2)) k--;
                }
            }
            // 跳过相同的i
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        }
        
        return result;
    }
};
