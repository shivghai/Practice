#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
long a[1000000];
long m;
 
void check(long n)
{
    long c=1;
    for(long i=0;i<n;++i)
        if(a[i]>=c)
         ++c;
    m=c;
}
 
 
void mergearrays(long l1, long r1, long l2, long r2)
{
    long *x=new long[r1-l1+1];
    long *y=new long[r2-l2+1];
 
    for(long i=l1;i<=r1;++i)
        x[i-l1]=a[i];
 
    for(long i=l2;i<=r2;++i)
        y[i-l2]=a[i];
 
    long C=l1,c1=0,c2=0;
 
    for(;;)
    {
        if(x[c1]<y[c2])
        {
            a[C]=x[c1];
            ++c1;
            ++C;
        }
        else
        {
            a[C]=y[c2];
            ++c2;
            ++C;
        }
 
        if(c1==r1-l1+1)
        {
            for(;;)
            {
                if(c2==r2-l2+1)
                    break;
                a[C]=y[c2];
                ++c2;
                ++C;
            }
            break;
        }
 
        if(c2==r2-l2+1)
        {
            for(;;)
            {
                if(c1==r1-l1+1)
                    break;
                a[C]=x[c1];
                ++c1;
                ++C;
            }
 
            break;
        }
 
    }
    delete(x);
    delete(y);
}
 
void mergesort(int l, int r)
{
    if(l>=r)
        return;
 
    int middle=(l+r)/2;
 
    mergesort(l,middle);
    mergesort(middle+1,r);
 
    mergearrays(l,middle,middle+1,r);
}
 
int main()
{
    long n;
    cin>>n;
    long x,y;
 
    for(long i=0;i<n;++i)
    {
        scanf("%ld",&x);
        scanf("%ld",&y);
        if(x<y)
            a[i]=x;
        else
            a[i]=y;
    }
 
    mergesort(0,n-1);
 
    check(n-1);
 
    cout<<m;
    return 0;
}
