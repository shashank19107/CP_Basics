#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n+1];
        map<ll,ll> m;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            m[i]=arr[i];
        }
        int check=0;
        sort(arr+1,arr+n+1);
        for(int i=1; i<=n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            ll x=arr[i]*m[i];
            cout<<x<<endl;
			
            if(ceil(sqrt((float)(x)))==floor(sqrt((float)(x)))){
                
            }
            else{
                check=1;
                break;
            }
        }
        if(check==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}