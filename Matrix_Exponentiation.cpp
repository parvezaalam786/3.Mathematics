//SPOJ- SEQ Recursive Sequence
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000000
ll k;
vector<ll> a,b,c;

vector<vector<ll> > multiply(vector<vector<ll> > A,vector<vector<ll> > B)
{
    //storing result in third matrix
    vector<vector<ll> > C(k+1,vector<ll>(k+1)); 
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            for(int x=1;x<=k;x++)
            {
                C[i][j] = (C[i][j]+(A[i][x]*B[x][j])%MOD)%MOD;
            }
        }
    }
    return C;
}

vector<vector<ll> > pow(vector<vector<ll> > A,ll p)
{
    //Base case
    if(p==1)
    return A;
    //Recursive case
    if(p&1){
        return multiply(A,pow(A,p-1));
    }
    else{
        vector<vector<ll> > X = pow(A,p/2);
        return multiply(X,X);
    }
}

int Compute(int n)
{
    //Base Case
    if(n==0)
    {
        return 0;
    }
    //n<=k
    if(n<=k)
    {
        return b[n-1];
    }
    //Here we will use matrix exponentiation
    vector<ll> F1(k+1);
    //1.Creating F1 vector
    for(int i=1;i<=k;i++)
    {
        F1[i] = b[i-1];
    }
    //2.Creating Transformation Matrix
    vector<vector<ll> > T(k+1,vector<ll>(k+1));
    
    // Initialize T
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i<k){
                if(j==i+1){
                    T[i][j] = 1;
                }
                else{
                    T[i][j] = 0;
                }
                continue;
            }
            //Last row : store the coefficients in reverse order
            T[i][j] = c[k-j];
        }
    }
    //3. compute T^(n-1)
    T = pow(T,n-1);
    //4. Multiply by F1 : Here only the first element is our result
    ll res = 0;
    for(int i=0;i<=k;i++)
    {
        res = (res + (T[1][i]*F1[i])%MOD)%MOD;
    }
    return res;
}
int main()
{
    ll t,n,num;
    cin>>t;
    while(t--)
    {
        cin>>k;
        //Initial vector F1
        for(int i=0;i<k;i++)
        {
            cin>>num;
            b.push_back(num);
        }
        //Coefficients
        for(int i=0;i<k;i++)
        {
            cin>>num;
            c.push_back(num);
        }
        // the value of nth term
        cin>>n;
        cout<<Compute(n)<<endl;

        b.clear();
        c.clear();
    }
    return 0;
}
