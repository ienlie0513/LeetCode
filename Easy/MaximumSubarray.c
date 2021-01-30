int maxSubArray(int* nums, int numsSize){
    int sum = INT_MIN;
    int temp_sum = 0;
    int minus = INT_MIN;
    for(int i=0; i<numsSize; i++){
        temp_sum += nums[i];
        if(nums[i] > 0 && temp_sum > sum)
            sum = temp_sum;
        else{
            if(nums[i] > minus)
                minus = nums[i];
            if(temp_sum < 0)
                temp_sum = 0;
        }
    }
    if(sum < minus)
        sum = minus;
    return sum;
}
