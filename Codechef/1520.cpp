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



int main()
{


	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		char prev='x';
		char now;
		int arr[26];
		memset(arr, 0, sizeof(arr[0])*26);
		bool fl = false;
		lp(i, 0, n){
			cin>>now;
			if(now!=prev){
				if(arr[now-'A']>=1){
					fl = true;
				}
				else{
					arr[now-'A'] = 1;
					prev = now;
				}
			}
			prev = now;

		}
		if(fl){
			cout<<"NO\n";
		}
		else{

			cout<<"YES\n";
		}

	}

return 0;
}