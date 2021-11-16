

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    *returnSize = 2;
    int *ans = (int *)malloc(sizeof(int)*2);
    
    int left=0, right=numbersSize-1, sum;
    while(left<right){
        sum = numbers[left]+numbers[right];
        if(sum == target){
            ans[0] = left+1;
            ans[1] = right+1;
            break;
        }
        if(sum < target){
            left++;
        }
        if(sum > target){
            right--;
        }
    }
    return ans;
}
