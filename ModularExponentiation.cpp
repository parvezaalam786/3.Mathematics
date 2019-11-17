#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll M=1e9+7;

ll ModularExponentiation(ll num,ll power) 
{
    ll result = 1;
    while(power>0)
    {
        if(power%2==1)
            result = (result*num)%M;
        num = (num*num)%M;
        power = power/2;    
    }
    return result;   
}
int main()
{
    cout<<ModularExponentiation(2,50);   
  
    return 0;
}
