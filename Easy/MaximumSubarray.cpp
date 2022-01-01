class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN, cur=0;
        for(int i=0; i<nums.size(); i++){
            cur += nums[i];
            ans = max(cur, ans);
            cur = max(cur, 0);
        }
        return ans;
    }
};
