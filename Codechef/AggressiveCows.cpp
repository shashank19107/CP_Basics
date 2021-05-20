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

int n;
bool check(int arr[], int c, int i){
	int counter=arr[0];
	int j=0;
	c--;
	while(j<n){
		//counter+=arr[j];
		if(arr[j]-counter>=i){
			counter=arr[j];
			c--;

		}
		if(c==0){
			return true;
		}
		j++;
	}
	return false;
}



int main()
{
	int t;
	cin>>t;
	while(t--){
		int c;
		cin>>n>>c;
		int arr[n];
		lp(i, 0, n){
			cin>>arr[i];
		}
		sort(arr, arr+n);
		int beg=1;
		int end=1000000000;
		int mid;
		while(beg<end){
			mid = end- ((end-beg)/2);
			if(check(arr, c, mid)){
				beg= mid;
			}
			else{
				end = mid-1;
			}



		}
		cout<<beg<<"\n";



	}



return 0;
}