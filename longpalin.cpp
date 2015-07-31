#include<iostream>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
 
int check(char a[], int lower, int upper)
{
    for(int i=0;i<(upper-lower)/2+1;++i)
    {
        if(a[lower+i]!=a[upper-i])
            return 0;
    }
    return 1;
}
 
void findpalindrome(char a[], int len, int checksize)
{
    for(int i=0;i+checksize<len;++i)
    {
        if(check(a,i,i+checksize))
        {
            cout<<checksize+1<<endl;
            for(int j=i;j<=i+checksize;++j)
                cout<<a[j];
            return;
        }
    }
    findpalindrome(a,len,checksize-1);
}
 
int main()
{
    int n;
    cin>>n;
    char a[5000];
    cin>>a;
 
    int len=strlen(a);
 
    findpalindrome(a,len,len);
 
    return 0;
}
