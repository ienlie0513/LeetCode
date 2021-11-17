

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int j=-1, max=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i] != 1){
            if((i-j-1)>max){
                max = i-j-1;
            }
            j=i;
        }
    }
    
    if((numsSize-1-j)>max){
        max = numsSize-1-j;
    }
    return max;
}
