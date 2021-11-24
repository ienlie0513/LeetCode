char pair(char c){
    if(c == ')')
        return '(';
    if(c == ']')
        return '[';
    if(c == '}')
        return '{';
    return '0';
}

bool isValid(char * s){
    char stack[5000];
    int top = 0;
    stack[0] = s[0];
    for(int i=1; i<strlen(s); i++){
        if(top>5000)
            return false;

        if(top >= 0 && pair(s[i])!='0' && stack[top] == pair(s[i])){
            top--;
        }
        else{
            top++;
            stack[top] = s[i];
        }
    }
    
    if(top < 0)
        return true;
    else
        return false;
}
