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
    int t;
    cin>>t;
    while(t--){
        int n,w,wr;
        cin>>n>>w>>wr;
        int arr[n];
        unordered_map<int, int> map;
        ll max = wr;
        int i;

        lp(j, 0, n){
            cin>>i;
            if(map.find(i)!= map.end()){
                //cout<<"Here ";
                max += i + i;
                map.erase(i);

            }
            else{
                map[i]=1;
            }
           // cout<<max<<" ";

        }
        if(max>= w){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }


        return 0;
    }