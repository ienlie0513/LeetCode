

bool isPalindrome(char * s){
    int h=0, t=0;
    while(s[t] != '\0'){
        if(islower(tolower(s[t])) || isdigit(s[t])){
            s[h] = tolower(s[t]);
            h++;
        }
        t++;
    }
    
    h--;
    t = 0;
    while(t<h){
        if(s[h] != s[t])
            return false;
        t++;
        h--;
    }
    return true;
}
