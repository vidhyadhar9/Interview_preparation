/*
Roman to Numeric conversion 
This code converts a Roman numeral string to its integer value.
we know th symbols that were used in the roman numbers then 
we know if the element less than the next right elementt then we have to subtract it from the next right element
else we have to add it to the next right element

so we can use the map to store the Roman element and its value and then we can iterate through the string and check the condition
and return the sum of the values.
Tc-->o(n) and space could o(constant)-->o(1)
*/





int romanToInt(string s) { 
    int n=s.size();
    int i=0;
    int sum=0;
    map<char,int>m{{'I',1},{'X',10},{'L',50},{'V',5},{'C',100},{'D',500},{'M',1000}};
    while(s[i+1]!='\0')
    {
        if(m[s[i]]<m[s[i+1]])
        {
            sum-=m[s[i]];
        }
        else
        sum+=(m[s[i]]);
        i++;
    }
    sum+=(m[s[i]]);
    return sum;
}
