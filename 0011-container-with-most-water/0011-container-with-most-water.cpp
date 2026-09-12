class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0,right = height.size() - 1;
        long long max_area = INT_MIN;
        while(left < right){
            long long  area  = (right - left)*min(height[right],height[left]);
            if(height[left] >= height[right]){
                right--;
            }
            else{
                left++;
            }
            max_area = max(max_area,area);
        }
        return max_area;
    }
};