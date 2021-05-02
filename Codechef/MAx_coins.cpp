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


void print(vi arr){
    for(auto i = arr.begin(); i != arr.end(); i++){
        cout<<*i<<" ";
    }
    cout<<endl;
}

int main()
{
    char arr[200005];
    cin>>arr;
    int n =strlen(arr);
    //cout<<n<<endl;
    vi state( n+1,0);
    vi state_bc( n+1 , 0);
    vi a_before(n+1, 0 );
    vi bc_after(n+1, 0);
    


    lp(i, 0, n){
        if(arr[i]=='A'){
            
            a_before[i+1] =  1 + a_before[i];
           // cout<<"Now"<<endl;

        }
        else{
            a_before[i+1] =0;
        }
        //cout<<"Here 1"<<endl;

        if(arr[i]=='A'){
            state[i+1] = 1;

        }
        else if( arr[i]=='B'){
            if(state[i]==1){
                state[i+1]=2;
            }

        }
        else if (state[i]==2){
            state[i+1] = 3;

        }
        //cout<<"Here 2"<<endl;
    }

    for(int i=n-1; i>=0; i--){
        if(arr[i]=='C'){
            state_bc[i] = 1;

        }
        else if( arr[i]=='B'){
            if(state_bc[i+1]==1){
                state_bc[i]=2;
            }

        }
    }
    print(a_before);
    print(state);
    print(state_bc);

    int ans=0;
    for(int i=2; i<=n;i++){
        if(state[i]==3){
            ans++;
            if(i>2)
            {
                ans  += a_before[i-3];
            }
            if(i<n-2){
                if(state_bc[i+1]==2){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;



        return 0;
    }