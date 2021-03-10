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
        int n;
        int k;
        cin>>n>>k;
        int arr[n];
        int min=0,max=0;
        vi se;
        lp(i,0,n){
            int temp;
            cin>>temp;
            se.push_back(temp);
            if(temp>max){max=temp;}

        }
        sort(se.begin(),se.end());
        vi:: iterator itr;
        for(int j =0; j<n;j++){
            if(se[j]<=min){
                min = se[j]+1;
            }
            else{
                break;
            }
        }
        //cout<<max<<" "<<min<<"\n";
        int size=0;

        if(min <= max){
            if(k>0)
            if(find(se.begin(), se.end(), (min+max+1)/2)==se.end())
            size++;
        }
        else{
            if(k>0)
            size+=k;
        }
        //cout<<size<<"\n";
        int ans =1;
        int prev = *(se.begin());
        for(itr = se.begin(); itr!=se.end();++itr){
            //cout<<prev<<" "<<*itr<<"\n";
            if(itr!=se.begin()){
                if(*itr!=prev){
                    ans++;
                }
               
            }
             prev= *itr;

        }
        if(k==0){
            cout<<ans<<"\n";
        }
        else
        cout<<size+ans<<"\n";


    }


        return 0;
    }