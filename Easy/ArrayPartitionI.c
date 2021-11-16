void swap(int* nums, int i, int j){
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
}

void sort(int* nums, int left, int right){
    if(left<right){
        int i=left;
        for(int j=left; j<right; j++){
            if(nums[j]<nums[right]){
                swap(nums, i, j);
                i++;
            }
        }
        swap(nums, i, right);
        
        sort(nums, left, i-1);
        sort(nums, i+1, right);
    }
}

int arrayPairSum(int* nums, int numsSize){
    sort(nums, 0, numsSize-1);
    int sum=0;
    for(int i=0; i<numsSize; i+=2){
        sum += nums[i];
    }
    return sum;
}
