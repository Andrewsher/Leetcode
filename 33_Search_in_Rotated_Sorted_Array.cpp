class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        int size = nums.size();
        if(size > 0) {
            int left = 0, right = size - 1;
            while(left < right) {
                int mid = (left + right) / 2;
                if(nums[mid] == target) {
                    index = mid;
                    break;
                }
                else if(nums[mid] >= nums[left]) {
                    if(nums[mid] > target) {
                        right = mid;
                    }
                    else {
                        left = mid;
                    }
                }
                else {
                    if(nums[mid] < target) {
                        right = mid;
                    }
                    else{
                        left = mid;
                    }
                }
            }
         }
        return index;
    }
};
