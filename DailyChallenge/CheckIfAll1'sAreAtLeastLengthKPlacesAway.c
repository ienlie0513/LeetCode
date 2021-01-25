bool kLengthApart(int* nums, int numsSize, int k){
    if(k == 0)
        return true;
    
    int index = -1;
    for(int i=0; i<numsSize; i++){
        if(nums[i] == 1 && index == -1)
            index = i;
        else if(nums[i] == 1){
            if(i - index <= k)
                return false;
            index = i;
        }
    }
    return true;
}
