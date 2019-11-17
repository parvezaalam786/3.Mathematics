#include<bits/stdc++.h>
using namespace std;
int main()
{
    long int sum1=0,i=2,num,sum2=0,num2;
    vector<long int> v1;
    cin>>num;
    num2=num;
    while(num!=1)
    {
        if(num%i==0)
        {
            v1.push_back(i);
            num/=i;
        }
        else
        {
            i++;
        }
    }
    vector<long int>::iterator i1;
    for(i1=v1.begin(); i1!=v1.end(); i1++)
    {
        long int d = *i1;
        if(d>=10)
        {
            while(d>0)
            {
                sum1+=d%10;
                d/=10;
            }
        }
        else
        {
            sum1+=d;
        }  
    }
    while(num2>0)
    {
        sum2+=num2%10;
        num2/=10;
    }
    //cout<<sum1<<" "<<sum2;
    if(sum1==sum2)
    cout<<"1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}
