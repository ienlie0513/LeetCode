int minSubArrayLen(int target, int* nums, int numsSize){
    int sum=0, j=0, length=INT_MAX;
    for(int i=0; i<numsSize; i++){
        sum += nums[i];
        
        while(sum >= target){
            if(length>(i-j+1))
                length = (i-j+1);
            sum -= nums[j];
            j++;
        }
    }
    
    return length==INT_MAX?0:length; 
}
