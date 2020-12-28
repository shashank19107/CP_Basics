
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <cstring>
#include<math.h>

using namespace::std;

int get_smaller(int arr[], int i){
    int ret=0;
    while(i>0){
        ret+=arr[i];
        i-= (i & -i);
    }
    return ret;


}

void set(int arr[], int i, int n){
    while(i<= n){
        arr[i] += 1;
        i += (i &-i);
    }
}

void put(int arr[], int i, int n){
    while(i<=n){
        arr[i] -= 1;
        i += (i& -i);
    }
}

int main(){
    int n;
    cin>>n;

    int a[n],b[n];
    //int tree1[n+1];// tree2[n+1];
    bool at[n+1];
    bool bt[n+1];
    bool cut[n+1];
    memset(bt, false, sizeof(bt));
    memset(cut, false, sizeof(cut));
    memset(at, false, sizeof(at));

    //memset(tree2, 0, sizeof(tree2));
    for(int i =0; i<n;i++){
        cin>>a[i];
    }
    for(int i =0; i<n;i++){
        cin>>b[i];
    }
    int totalp = 0;
    long long counter=0;
    for(int i =0; i<n;i++){
        at[a[i]] = true;
        bt[b[i]] = true;
        if(bt[a[i]] && cut[a[i]]){
            totalp--;
            //cout<<"Total decreased be "<<a[i]<<endl;
        }

        if(at[b[i]]==false)     //means not encountered in A or 
        {
           // cout<<"Totla raissed by "<<b[i]<<endl;
            cut[b[i]] = true;
            totalp++;
        }

        counter+=totalp;
        



    }
    cout<<counter<<endl;




    return 0;
}