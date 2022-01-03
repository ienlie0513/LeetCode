class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> dict;
        vector<int> ans;
        int tmp;
        for(int i=0; i<nums.size(); i++){
            tmp = target - nums[i];
            if(dict.find(tmp) != dict.end()){
                ans.push_back(dict[tmp]);
                ans.push_back(i);
                break;
            }
            dict[nums[i]] = i;
        }
        return ans;
    }
};
