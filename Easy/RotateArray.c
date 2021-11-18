

void rotate(int* nums, int numsSize, int k){
    if(k == 0 || numsSize == 1 || numsSize==k)
        return;
    
    k = k%numsSize;
    
    int tmp[k];
    
    for(int i=numsSize-k, j=0; i<numsSize; i++, j++){
        tmp[j] = nums[i];
    }    

    for(int i=numsSize-1; i>=k; i--){
        nums[i] = nums[i-k];
    }

    for(int i=0; i<k; i++){
        nums[i] = tmp[i];
    }
}
