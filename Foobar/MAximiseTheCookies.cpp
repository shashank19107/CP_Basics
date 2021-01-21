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

bool check(ll arr[], ll nums[], ll curr,ll k, ll n){
	lp(i, 0, n){
		if(arr[i]*curr > nums[i]){
			if(k < arr[i]*curr - nums[i] ){
				return false;
			}
			else{
				k -= arr[i]*curr - nums[i] ;
			}
		}
	}
	return true;

}



int main()
{
	ll n,k;
	cin>>n>>k;
	ll arr[n];
	ll nums[n];
	lp(i,0,n){
		cin>>arr[i];
	}
	lp(i,0,n){
		cin>>nums[i];
	}
	ll beg =0;
	ll end = 2100000009;
	ll mid;
	while(beg<end){
		mid = (end) - (end-beg)/2;
		if(check(arr, nums, mid, k, n)){
			beg = mid;
		}
		else{
			end = mid - 1;
		}
	}
	cout<<beg<<endl;





return 0;
}