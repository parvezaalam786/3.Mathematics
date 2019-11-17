#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long int N,no;
    vector<unsigned long long int> v;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>no;
        v.push_back(no);     
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=j+1;k<N;k++){
                for(int l=k+1;l<N;l++){
                    if((v[i]^v[j]^v[k]^v[l])==0)
                    {
                        cout<<"Yes";
                        return 0;
                    }             
                }
            }
        }
    }
    cout<<"No";
    return 0;
}
