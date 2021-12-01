int singleNumber(int* nums, int numsSize){
    int val = nums[0];
    for(int i=1; i<numsSize; i++){
        val ^= nums[i];
    }
    return val;
}
