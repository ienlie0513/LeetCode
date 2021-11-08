int dominantIndex(int* nums, int numsSize){
    if(numsSize==1)
        return 0;
    
    int max = 0, max_id = -1;
    for(int i=0; i<numsSize; i++){
        if(nums[i]>max){
            max = nums[i];
            max_id = i;
        }
    }

    for(int i=0; i<numsSize; i++){
        if(max<nums[i]*2 && i!=max_id){
            max_id = -1;
        }
    }
    
    return max_id;
}
