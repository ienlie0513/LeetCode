int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *ans = (int *)malloc(sizeof(int)*(digitsSize+1));
    *returnSize = digitsSize;
    int carry = 1;
    for(int i=digitsSize-1; i>=0; i--){
        ans[i] = (digits[i] + carry) % 10;
        carry = (digits[i] + carry) / 10;
    }

    if(carry == 0)
        return ans;
    (*returnSize)++;
    for(int i=digitsSize-1; i>=0; i--)
        ans[i+1] = ans[i];
    ans[0] = carry;
    return ans;
}
