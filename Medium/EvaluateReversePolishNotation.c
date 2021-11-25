int evalRPN(char ** tokens, int tokensSize){
    if(tokensSize == 1)
        return atoi(tokens[0]);
    
    int *stack = (int*)malloc(sizeof(int)*tokensSize);
    int ans, top=-1;
    
    for(int i=0; i<tokensSize; i++){
        if(!atoi(tokens[i]) && *tokens[i]-'0'!=0){
            if(*tokens[i] == '+') ans = stack[top-1]+stack[top];
            if(*tokens[i] == '-') ans = stack[top-1]-stack[top];
            if(*tokens[i] == '*') ans = stack[top-1]*stack[top];
            if(*tokens[i] == '/') ans = (int)round(stack[top-1]/stack[top]);
            top--;
            stack[top] = ans;
        }
        else{
            top++;
            stack[top] = atoi(tokens[i]);
        }
    }
        
    return ans;
}
