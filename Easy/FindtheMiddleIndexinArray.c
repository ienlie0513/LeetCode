int pivotIndex(int* nums, int numsSize){
    if(numsSize==1)
        return 0;
    
    int sum=0;
    for(int i=0; i<numsSize; i++){
        sum+=nums[i];
    }
    
    int currsum=0;
    for(int i=0; i<numsSize; i++){
        if(currsum == sum-currsum-nums[i])
            return i;
        currsum+=nums[i];
    }
    return -1;
}
