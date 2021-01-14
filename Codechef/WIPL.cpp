#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <cstring>
#include<math.h>
#include <bits/stdc++.h>

using namespace::std;

int n;

int solve(int arr[], int i, int k1, int k2, int dp[4004][4004]){
    if(k1 <=0 && k2<=0){
        return 0;
    }
    if(n<=i){
        return 10000000;
    }
    int a=10000000,b=10000000;
    if(k1<0){
        k1=0;
    }
    if(dp[i][k1]==-1){
        
        if(k1>0){
        a = solve(arr, i+1, k1-arr[i], k2,dp );
        }
        if(k2>0){
            b = solve(arr, i+1, k1, k2-arr[i], dp);
        }
    }
    return dp[i][k1]=1+min(a,b);

}


int main(){

    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>n>>k;
        //vector<int> heights(n);
        int dp[4004][4004];
        memset(dp, -1, sizeof(dp));
        int heights[n];

        int temp;
        for(int i=0; i<n;i++){
            cin>>heights[i];
            //heights.push_back(temp);
        }
        sort(heights, heights+n, greater<int>());
        int answer =solve(heights, 0, k, k, dp);
        

        if(answer > 100000){
            cout<<"-1"<<endl;
        }
        else{
            cout<<answer<<endl;
        }



    }

return 0;

}
