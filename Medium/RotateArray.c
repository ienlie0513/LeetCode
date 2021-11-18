void reverse(int* nums, int start, int end){
    int t;
    while(start<end){
        t = nums[start];
        nums[start] = nums[end];
        nums[end] = t;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k){
    if(numsSize <= 1)
        return;
    
    k %= numsSize;
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
}
