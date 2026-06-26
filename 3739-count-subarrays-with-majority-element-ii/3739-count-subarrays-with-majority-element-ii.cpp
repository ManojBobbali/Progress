class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        
        vector<int>freq(nums.size()*2+1);
        long long ans  = 0 , presum = 0;
        freq[nums.size()] = 1;
        int idx = nums.size() ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == target){
                presum += freq[idx];
                idx++;
                freq[idx]++;
            }
            else{
                idx--;
                presum -= freq[idx];
                freq[idx]++;
            }
            ans += presum;
        }
        return ans;
    }
};