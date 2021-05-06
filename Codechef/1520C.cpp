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
		if(n==2){
			cout<<-1<<endl;
			continue;
		}
		int arr[n*n+1];
		int n2= n*n;
		memset(arr, 0, sizeof(arr[0])*(n*n));
		int index=1;
		for(int i=1; i<=n2; i++){
			arr[index]=i;
			index+=2;
			if(index>n2 && n%2==0)
			{index = 2;}
			else if(index>n2 && n%2==1){
				index = 2;
			}

		}
		for(int i =0; i<n;i++){
			for(int j=0; j<n;j++){
				cout<<arr[(i*n)+j+1]<<" ";
			}
			cout<<endl;
		}

	}

return 0;
}