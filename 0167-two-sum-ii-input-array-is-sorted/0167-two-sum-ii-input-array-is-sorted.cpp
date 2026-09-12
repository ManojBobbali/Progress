class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0,right = numbers.size()-1;
        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                vector<int> v;
                v.push_back(left+1);
                v.push_back(right+1);
                return v;
            }
            if(sum < target)left++;
            else right--;
        }
        return {};
    }
};