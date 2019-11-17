//https://www.geeksforgeeks.org/birthday-paradox/
#include<bits/stdc++.h>
using namespace std;
int minPeople(float req)
{
    if(req==1)
    return 366;
   return ceil(sqrt(2*365*log(1/(1-req)))); 
}
int main()
{
    float req;
    cin>>req;
    int ppl=minPeople(req);
    cout<<ppl<<endl;
    return 0;
}