void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int temp[nums1Size];
    int index_1 = 0;
    int index_2 = 0;
    int index_temp = 0;
    
    while(index_1 < m && index_2 < n){
        if(nums1[index_1] < nums2[index_2]){
            temp[index_temp++] = nums1[index_1];
            index_1++;
        }
        else{
            temp[index_temp++] = nums2[index_2];
            index_2++;
        }
    }
    for(int i=index_1; i<m; i++)
        temp[index_temp++] = nums1[i];
    for(int i=index_2; i<n; i++)
        temp[index_temp++] = nums2[i];
    for(int i=0; i<m+n; i++)
        nums1[i] = temp[i];
}
