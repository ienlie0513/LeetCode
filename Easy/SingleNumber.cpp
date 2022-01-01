class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum = sum xor nums[i];
        }
        return sum;
    }
};
