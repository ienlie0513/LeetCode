void rotate(int* nums, int numsSize, int k){
    if(k == 0 || numsSize == 1 || numsSize==k)
        return;
    
    k %= numsSize;
    
    int tmp[numsSize];
    int nid;
    
    for(int i=0; i<numsSize; i++){
        nid = (i+k)%numsSize;
        tmp[nid] = nums[i];
    }    

    for(int i=0; i<numsSize; i++){
        nums[i] = tmp[i];
    }
}
