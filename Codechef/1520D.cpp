//Hello, this is a snippet for c++.

#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h> 
#include <cmath>
//#define ll long long
using namespace std;
#define lp(i,a,n) for(int i=a;i<(n);++i)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;


long long printNcR(int n, int r)
{
 
    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;
 
    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
 
            // gcd of p, k
            long long m = __gcd(p, k);
 
            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;
 
            n--;
            r--;
        }
 
        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }
 
    else
        p = 1;
 
    // if our approach is correct p = ans and k =1
    return p;
}




int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[2*(n+1)];
		int temp;
		memset(arr, 0, sizeof(arr[0])*(2*(n+1)));
		lp(i, 1, n+1){
			cin>>temp;
			arr[n+(temp-i)]++;

		}
		long long ans=0;
		lp(i, 0, 2*(n+1)){
			if(arr[i]>=2)
			{
				ans += printNcR(arr[i], 2);
			}
		}
		cout<<ans<<endl;


	}



return 0;
}