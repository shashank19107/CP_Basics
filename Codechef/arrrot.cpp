//Hello, this is a snippet for c++.
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h> 
#include <cmath>

using namespace std;
#define lp(i,a,n) for(int i=a;i<(n);++i)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int mod = 1000000007;


int main()
{
    int n;
    cin>>n;
    int arr[n];
    int sum =0; 
    lp(i, 0, n){
        cin>>arr[i];
        sum+=arr[i];
        sum%=mod;

    }
    ll q;
    cin>>q;
    int par;
    for(int i=0; i<q;i++){
        //cin>>par;
        sum+=sum;
        sum= sum%mod;
        cout<<sum<<endl;

    }




        return 0;
    }