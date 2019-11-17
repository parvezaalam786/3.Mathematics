/// Sieve of Eratosthenes === used for finding the prime numbers upto N in O(NloglogN)
#include<iostream>
using namespace std;
#define ll long long
void Sieve(int N)
{
    bool isPrime[N+1];
    for(ll i=0;i<=N;i++)
        {
            isPrime[i] = true;
        }
    isPrime[0] = false;
    isPrime[1] = false;
    for(ll i=2;i*i<=N;i++)
    {
        if(isPrime[i] == true)
            {
                for(ll j=i*i;j<=N;j+=i)
                {
                    isPrime[j] = false;
                }
            }
    }
    for(ll i=1;i<=N;i++)
    {
        if(isPrime[i])
            cout<<i<<" ";
    }
}
int main()
{
    long long int N;
    cout<<"Enter the number"<<endl;
    cin>>N;
    Sieve(N);
    getch();
    return 0;
}
