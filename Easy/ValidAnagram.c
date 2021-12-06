bool isAnagram(char * s, char * t){
    int count[26]={0};
    char *sptr = s;
    char *tptr = t;
    while(*sptr != '\0') count[*sptr++ -'a']++;
    while(*tptr != '\0') count[*tptr++ -'a']--;
    
    for(int i=0; i<26; i++)
        if(count[i])
            return false;
        
    return true;
}
