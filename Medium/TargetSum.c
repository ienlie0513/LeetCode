int DFS(int* nums, int numsSize, int target, int i){
    if(i == numsSize-1)
        if(!(target+nums[i]) && !(target-nums[i]))
            return 2;
        else if(!(target+nums[i]) || !(target-nums[i]))
            return 1;
        else
            return 0;
    
    int t1 = target-nums[i];
    int t2 = target+nums[i];
    i++;
    return DFS(nums, numsSize, t1, i) + DFS(nums, numsSize, t2, i);
}

int findTargetSumWays(int* nums, int numsSize, int target){
    return DFS(nums, numsSize, target, 0);    
}
