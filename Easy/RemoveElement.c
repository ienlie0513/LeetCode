int removeElement(int* nums, int numsSize, int val){
    if(numsSize == 0)
        return 0;

    int length = 0;
    for(int i=0; i<numsSize; i++){
        if(nums[i] != val){
            nums[length] = nums[i];
            length++;
        }
    }

    return length;
}
