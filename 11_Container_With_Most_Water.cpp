class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxArea = 0;
        
        while(i < j) {
            int h = min(height[i], height[j]);
            maxArea = max((j - i) * h, maxArea);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxArea;
    }
};
