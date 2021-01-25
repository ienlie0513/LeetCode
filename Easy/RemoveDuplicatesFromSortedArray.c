int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;

    int length = 1;
    for(int i=1; i<numsSize; i++){
        if(nums[i] != nums[length-1]){
            nums[length] = nums[i];
            length++;
        }
    }

    return length;
}
