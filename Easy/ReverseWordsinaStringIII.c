void reverse(char *s, int start, int end){
    char t;
    while(start<end){
        t = s[start];
        s[start] = s[end];
        s[end] = t;
        start++;
        end--;
    }
}

char * reverseWords(char * s){
    int j=0;
    for(int i=0; s[i]!='\0'; i++){
        if(s[i] == ' '){
            reverse(s, j, i-1);
            j = i+1;
        }
    }
    reverse(s, j, strlen(s)-1);
    return s;
}
