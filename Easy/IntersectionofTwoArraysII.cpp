class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> ans;
        
        for(int x: nums1)
            m[x]++;
        
        for(int x: nums2){
            m[x]--;
            
            if(m[x]>=0) ans.push_back(x);
        }
        
        return ans;
    }
};
