bool isValid(char * s){
    int str[10000];
    int index = 0;
    for(int i=0; i<strlen(s); i++){
        if(index == 0 && (s[i] == ')' || s[i] == ']' || s[i] == '}')) return false;
        if(s[i] == '('){
            str[index] = 0;
            index++;
        }
        if(s[i] == ')'){
            if(str[index-1] == 0){
                index--;
            }
            else return false;
        }
        if(s[i] == '['){
            str[index] = 1;
            index++;
        }
        if(s[i] == ']'){
            if(str[index-1] == 1){
                index--;
            }
            else return false;
        }
        if(s[i] == '{'){
            str[index] = 3;
            index++;
        }
        if(s[i] == '}'){
            if(str[index-1] == 3){
                index--;
            }
            else return false;
        }
    }
    if(index != 0) return false;
    return true;
}
