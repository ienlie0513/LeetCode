

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int size = nums1Size>nums2Size ? nums2Size: nums1Size;
    int *ans = (int *)malloc(sizeof(int)*size);
    
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int i=0, j=0, k=0;
    while(i<nums1Size && j<nums2Size){
        if(nums1[i] == nums2[j]){
            ans[k] = nums1[i];
            i++;
            j++;
            k++;
        }
        else if(nums1[i]<nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    
    *returnSize = k;
    return ans;
}
