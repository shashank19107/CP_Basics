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

int findmsb(int n){
	int ret = 0;
	while(n>0){
		ret= n%10;
		n/=10;
	}
	return ret;
}

int findnum (int n){
	int ret =0;
	while(n>0){
		ret++;
		n/=10;
	}
	return ret;
}

bool isnor(int n, int b){
	//int ret = n%10;
	while(n>0){
		if(b > n%10 ){
			return false;
		}
		n/=10;
	}
	return true;
}


int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int msb = findmsb(n);
		int num = findnum(n);
		int ans =0;
		lp(i,1,10){
			if(msb>i){
				ans += num;
				//cout<<"i "<<i<<" "<<num<<endl;
			}
			else if(msb==i && isnor(n,i)){
				ans += num;
				//cout<<"i "<<i<<" "<<num<<endl;
			}
			else{
				ans += num-1;
			}
		}
		cout<<ans<<"\n";
	}



return 0;
}