class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1, j=n-1, cur=m+n-1;
        if(!m)
            nums1 = nums2;
        
        while(i>=0 && j>=0){
            if(nums2[j]>nums1[i])
                nums1[cur] = nums2[j--];
            else
                nums1[cur] = nums1[i--];
            cur--;
        }
        
        while(j>=0){
            nums1[cur--] = nums2[j--];
        }
    }
};
