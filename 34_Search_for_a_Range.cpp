class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);    // 递归调用
    }
private:
    vector<int> search(vector<int>& nums, int target, int low, int high) {
        if(low > high) return {-1, -1}; // 越界返回-1
        if(nums[low] == target && nums[high] == target) {   // 与target相等，返回{low, high}
            return vector<int> {low, high};
        }
        if(nums[low] <= target && target <= nums[high]) {   // target处于查找范围之间，可以进行查找
            int middle = (low + high) / 2;
            vector<int> left = search(nums, target, low, middle);// 查找低位
            vector<int> right = search(nums, target, middle + 1, high);// 查找高位
            if(left[0] == -1) return right;
            if(right[0] == -1) return left;
            return vector<int> {left[0], right[1]};
        }
        return {-1, -1};                                    // 默认返回-1
        
    }
};
