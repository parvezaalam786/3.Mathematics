#include<bits/stdc++.h>
#define ll long long
ll arr[1000010]={0},prefixSum[1000010]={0}; /// prefixSum array is storing the frequency
using namespace std;
int main()
{
    int T,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        ll sum = 0;
        memset(prefixSum, 0 ,sizeof(prefixSum));
        prefixSum[0] = 1;    ///When no elements is choosen then sum is 0 which is divisible

        for(int i=0;i<N;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            sum%=N;
            sum = (sum+N)%N; ///For negative numbers... making it positive first
            prefixSum[sum]++;
        }
        ll ans = 0;
          for(int i=0;i<N;i++)
            {
               // cout<<prefixSum[i]<<" ";
                ll num = prefixSum[i];
                ans+= (num*(num-1))/2;
            }
            cout<<ans<<endl;
    }
    return 0;
}