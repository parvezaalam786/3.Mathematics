#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num,count1=0,T,n;
    double ans ;
    cin>>T;
    while(T--)
    {
        cin>>n;
        ans = 0.00;
        for(int i=1;i<=n;i++)
        {
            ans += (double)n/(i*1.0); 
        }
        count1=0;
        num = ans;
        while(num!=0)
        {
            count1++;
            num/=10;
        }
        if(ans==1)
        cout<<"1.00"<<endl;
        else
        cout<<setprecision(2+count1)<<ans<<endl;
    }
    return 0;
}