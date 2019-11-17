#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1000006] = {0};
ll lastocc[1000006] = {0};
ll ans[1000006] = {0};
int main()
{
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    memset(lastocc, 0 ,sizeof(lastocc));
    memset(ans, 0 ,sizeof(ans));
    ans[0] = 0;
    double sum = 0.00;

    for(ll i=1;i<=n;i++)
    {
        ans[i] = ans[i-1]+(i-lastocc[arr[i]]);
        lastocc[arr[i]] = i;
        sum = sum + ans[i];
    }
    double ans1=0.00;
    ans1 = (2*(sum-n)+n)/(n*n*1.0);
    cout<<fixed<<setprecision(6)<<ans1<<endl;
    return 0;
}