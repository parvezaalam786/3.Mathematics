#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll Power(ll n,ll x)
{
    int sum;
    if(x==0)
        return 1;
    sum = Power(n,x/2);
    if(x%2==0)
        return sum*sum;
    else 
        return n*sum*sum;        
}
int main()
{
    ll n,x,res=1;
    cin>>n>>x;
    res = Power(n,x);
    cout<<res<<endl;
return 0;
}