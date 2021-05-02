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
        int l;
        cin>>l;
        int he=0;
        char hl[l];
        cin>>hl;
        bool fl =false;


        lp(i, 0, l){
            //cin>>hl;
            he+=int(hl[i]-'0');
            if(he>= i-he+1){
                fl=true;
                break;
                
            }
            

        }
        if(fl){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }


        return 0;
    }