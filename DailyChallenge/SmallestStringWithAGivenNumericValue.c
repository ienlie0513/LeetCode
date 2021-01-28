char * getSmallestString(int n, int k){
    char *ans = (char *)malloc(sizeof(char) * (n+1));
    ans[n] = '\0';
    
    int z_num = (k-n)/25;
    int a_num = n-z_num-1;
    int mid = k-a_num-z_num*26;
    
    for(int i=0; i<a_num; i++)
       ans[i] = 'a';
    if(a_num >= 0)
        ans[a_num] = mid+96;
    for(int i=a_num+1; i<n; i++)
       ans[i] = 'z';
    
    return ans;
}
