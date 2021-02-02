char * addBinary(char * a, char * b){
    int carry = 0;
    char *ans;
    if(strlen(a)>strlen(b)){
        ans = (char *)calloc(strlen(a)+2, sizeof(char));
    
        for(int i=0; i<strlen(b); i++){
            ans[strlen(a)-i-1] = 
                ((a[strlen(a)-i-1] - '0') + (b[strlen(b)-i-1] - '0') + carry) % 2 + '0';
            carry = ((a[strlen(a)-i-1] - '0') + (b[strlen(b)-i-1] - '0') + carry) / 2;
        }
        
        for(int i=strlen(b); i<strlen(a); i++){
            ans[strlen(a)-i-1] = ((a[strlen(a)-i-1] - '0') + carry) % 2 + '0';
            carry = ((a[strlen(a)-i-1] - '0') + carry) / 2;
        }
        
        if(carry == 0)
            return ans;
        
        for(int i=strlen(a); i>=0; i--)
            ans[i+1] = ans[i];
        ans[0] = '1';
    }
    else{
        ans = (char *)calloc(strlen(b)+2, sizeof(char));
    
        for(int i=0; i<strlen(a); i++){
            ans[strlen(b)-i-1] = 
                ((a[strlen(a)-i-1] - '0') + (b[strlen(b)-i-1] - '0') + carry) % 2 + '0';
            carry = ((a[strlen(a)-i-1] - '0') + (b[strlen(b)-i-1] - '0') + carry) / 2;
        }
        
        for(int i=strlen(a); i<strlen(b); i++){
            ans[strlen(b)-i-1] = ((b[strlen(b)-i-1] - '0') + carry) % 2 + '0';
            carry = ((b[strlen(b)-i-1] - '0') + carry) / 2;
        }
        
        if(carry == 0)
            return ans;
        
        for(int i=strlen(b); i>=0; i--)
            ans[i+1] = ans[i];
        ans[0] = '1';
    }
        
    return ans;
}
