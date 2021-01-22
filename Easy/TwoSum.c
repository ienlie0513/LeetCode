
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *returnNums = malloc(sizeof(int)*2);
    *returnSize = 2;
        
    for (int i=0; i<numsSize; i++){
        for (int j=i+1; j<numsSize; j++){
            if (nums[i]+nums[j]==target){
                returnNums[0]=i;
                returnNums[1]=j;
                return returnNums;
            }
        }
    }
    return returnNums;
}
