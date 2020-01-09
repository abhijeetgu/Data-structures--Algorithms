//calculate range of bigger prime number
#include<iostream>
using namespace std;

#define ll long long int

void prime_sieve(ll p[])
{
    //first mark all odd numbers prime
    for(ll i=3;i<=1000000; i+=2)
    {
        p[i]=1;
    }

    //sieve
    for(ll i=3;i<=1000000; i+=2)
    {
        //if the current number is not marked (it is prime)
        if(p[i]==1)
        {
            // mark all the multiples of i as not prime
            for(ll j=i*i; j<= 1000000; j=j+i)
            {
                p[j]=0;
            }
        }


    }

    // special cases
    p[2]=1;
    p[1]=p[0]=0;


}
int main()
{
    ll n;
    cin>>n;

    ll p[1000000] = {0};
    prime_sieve(p);

    for(ll i=0;i<=n;i++)
    {
        if(p[i]==1)
        {
            cout<<i<<" ";
        }
    }

    return 0;
}
