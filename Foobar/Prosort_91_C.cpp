#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <cstring>
#include<math.h>
#include <bits/stdc++.h>

using namespace::std;


long long gcd(long long a, long long b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 



int main(){

    int n;
    cin>>n;
    int x;
    cin>>x;
    long long gc=-1;
    for(int i=0; i<n;i++){
        int t1;
        cin>>t1;
        t1 = abs(t1-x);
        if(gc == -1){
            gc = t1;
        }
        else{
            gc = gcd(gc, t1);
        }
    }
    cout<<gc<<endl;





    return 0;
}
