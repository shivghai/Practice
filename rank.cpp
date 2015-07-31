#include<iostream>
#include<stdio.h>
using namespace std;
 
int a[45000];
int ans[45000];
int n;
 
void display(int t[], int n)
{
 
    for(long i=0;i<n;++i)
        printf("%d\n",t[i]);
}
 
void ins(int val, int pos, int maxpos)
{
    for(int i=maxpos;i>pos;--i)
        a[i]=a[i-1];
 
        a[pos]=val;
 
}
 
void getans(int val, int pos)//pos from 0
{
    if(pos==0)
    {
        a[0]=val;
        ans[0]=1;
        return;
    }
 
    for(int i=pos-1;i>=0;--i)
    {//1 2 3 4
        if(val>a[i])
            {
                ans[pos]=pos-i;
                ins(val,i+1,pos);
                return;
            }
            if(i==0)
            {
                ans[pos]=pos+1;
                ins(val,i,pos);
                return;
            }
    }
}
 
int main()
{
    int x;
    cin>>n;
    for(long i=0;i<n;++i)
        {
            scanf("%d",&x);
            getans(x,i);
        }
    display(ans,n);
    return 0;
}
