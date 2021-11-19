

void moveZeroes(int* nums, int numsSize){
    int j=0, t;
    for(int i=0; i<numsSize; i++){
        if(nums[i] != 0){
            t = nums[j];
            nums[j] = nums[i];
            nums[i] = t;
            j++;
        }
    }
}
