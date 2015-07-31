#include<iostream>
using namespace std;
long n;
long MOD=15746;
 
long C_S(long n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    long c,a=1,b=2;
    for(int i=0;i<n-2;++i)
    {
        c=a+b;
        if(c>=MOD)
            c%=MOD;
        a=b;
        b=c;
    }
    return c;
}
 
int main()
{
    cin>>n;
    cout<<C_S(n);
    return 0;
}
 
