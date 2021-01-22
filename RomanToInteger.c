int romanToInt(char * s){
    int value=0;
    
    for(int i=0; i<strlen(s); i++){
        int v;
        
        switch(s[i]) {
            case 'I':
                if(s[i+1] == 'V' || s[i+1] == 'X')
                    v = -1;
                else
                    v = 1;
                break;
            case 'V':
                v = 5;
                break;
            case 'X':
                if(s[i+1] == 'L' || s[i+1] == 'C')
                    v = -10;
                else
                    v = 10;
                break;
            case 'L':
                v = 50;
                break;
            case 'C':
                if(s[i+1] == 'D' || s[i+1] == 'M')
                    v = -100;
                else
                    v = 100;
                break;
            case 'D':
                v = 500;
                break;
            case 'M':
                v = 1000;
                break;
            default:
                break;
        }
        
        value += v;
    }
    return value;
}
