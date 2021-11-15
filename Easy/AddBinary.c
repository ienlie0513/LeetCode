char * addBinary(char * a, char * b){
    int carry=0;
    if(strlen(a)>strlen(b)){
        char *t = b;
        b = a;
        a = t;
    }
    char *ans = (char *)malloc(sizeof(char)*(strlen(b)+2));
    ans[strlen(b)+1] = '\0';
    
    int i=strlen(a)-1, j=strlen(b)-1, k=strlen(b);
    for(; i>=0; i--, j--, k--){
        carry = (a[i]-'0') + (b[j]-'0') + carry;
        ans[k] = carry%2 + '0';
        carry /= 2;
    }
    
    for(; j>=0; j--, k--){
        carry = (b[j]-'0') + carry;
        ans[k] = carry%2 + '0';
        carry /= 2;
    }
    
    if(carry){
        ans[k] = carry + '0';
    }
    else{
        for(;k<strlen(b)+1; k++){
            ans[k] = ans[k+1];
        }
    }
        
    return ans;
}
