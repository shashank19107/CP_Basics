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


double sumOfAP(double a, double d, double n)
{
    double sum = (n / 2) * (2 * a + (n - 1) * d);
    return sum;
}
 
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		char arr[n];
		cin>>arr;
		//cout<<arr;
		int front[n+1];
		//int costf[n+1];
		//int costback[n+1];
		int back[n+1];
		memset(front, 0, sizeof(front[0])*(n+1));
		memset(back, 0, sizeof(back[0])*(n+1));
		//memset(costf, 0, sizeof(costf));
		//memset(costback, 0, sizeof(costback));
		int till=0;
		lp(i, 0, n){
			if(arr[i]=='.'){
				
				front[i] = i-till;
				till++;
			}
			//cout<<front[i]<<" ";

		}
		//cout<<endl;
		till=0;
		for(int i= n-1; i>=0; --i){
			if(arr[i]=='.'){
				back[i]= n-1-i-till;
				till++;

			}
			
		}
		// lp(i, 0, n){
		// 	cout<<back[i]<<" ";
		// }
		// cout<<endl;
		long long ans=0;
		lp(i, 0, n){
			if(arr[i]=='.'){
				ans+= min(front[i], back[i]);
			}
		}
		cout<<ans<<endl;




	}


return 0;
}