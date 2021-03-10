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


int main()
    {
        //cout<<"Hello World!!\n";
        int t;
        cin>>t;
        while(t--){
            int n;
            int k;
            cin>>n>>k;
            char arr[n];
            cin>>arr;
            int i;
            for(i=0; i<n/2;i++){
                if(arr[i]==arr[n-1-i]){
                    k--;
                }
                else{
                    k--;
                    break;
                }

            }
            if(i==n-1-i){
                k--;
            }
            
            if(k>=0){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }

        return 0;
    }