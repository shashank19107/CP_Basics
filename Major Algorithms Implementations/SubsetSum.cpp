
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <cstring>
#include<math.h>

using namespace::std;


bool solve(long long arr[], long long aim, int beg, int end){
    if(aim<0){
        return false;
    }
    if(aim == 0){
        return true;
    }
    if(beg==end){
        return arr[beg]==aim;
    }
    if(solve(arr, aim, beg+1,end)){
        return true;
    }


    return solve(arr, aim-arr[beg], beg+1,end) ;
}

int main(){
    int n;
     cin>>n;
    while (n--)
    {
        /* code */
        long long a,b;
        cin>>a>>b;
        long long arr[a];
        for(int i=0;i<a;i++){
            cin>>arr[i];
        }
        if(solve(arr, b, 0, a-1)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }

    }
    
    
    return 0;


}
