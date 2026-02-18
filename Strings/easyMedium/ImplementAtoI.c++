
int myAtoi(string s) {
    int i=0 , n=s.size();
    while(i<n && s[i]==' ')i++;
    if(i==n)return 0;
    int sign=1;
    if(s[i]=='-'){
        sign=-1;
        i++;
    }else if(s[i]=='+')i++;
    cout<<i<<endl;
    long long sol=0;
    while(i<n){
        if(s[i]>='0' and s[i]<='9'){
            long long num = int(s[i]-'0');
            sol=(sol*10+num);
            if(sign*sol>INT_MAX)return INT_MAX;
            else if(sign*sol<INT_MIN)return INT_MIN;
            cout<<sol<<endl;
            i++;
        }else break;
    }
    return sign*sol;
    

}