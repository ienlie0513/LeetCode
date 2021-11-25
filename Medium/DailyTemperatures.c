/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
    *returnSize = temperaturesSize;
    int *ans = (int*)calloc(temperaturesSize, sizeof(int));
    int *stack = (int*)calloc(temperaturesSize, sizeof(int));
    int top = -1;
    
    for(int i=0; i<temperaturesSize; i++){
        while(top >= 0 && temperatures[stack[top]]<temperatures[i]){
            ans[stack[top]] = i-stack[top];
            top--;
        }
        top++;
        stack[top] = i;
    }
    
    return ans;
}
