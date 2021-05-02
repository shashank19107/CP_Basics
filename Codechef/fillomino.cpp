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
    int n;
    cin>>n;
    int arr[n][n];
    int num[n];
    lp(i, 0, n){
        lp(j, 0, n){
            arr[i][j]=0;
        }
    }
    int a;
    lp(i,0,n){
        cin>>a;
        arr[i][i]=a;
        num[a-1]=i;

    }
    lp(i, 0, n){
        int x,y;
        x = num[i];
        y =x;
        int times = i+1;
        lp(j, 0, times){
            arr[x][y] = i+1;
            if(y-1>=0 && arr[x][y-1]==0){
                y-=1;
            }
            else{
                x+=1;
            }
        }
        
    }
    bool fl = false;
    lp(i, 0, n){
            lp(j, 0, i+1){
               if(arr[i][j]==0){
                   fl = true;
               }
            }
            
        }
    if (fl == false){
        lp(i, 0, n){
            lp(j, 0, i+1){
               cout<<arr[i][j]<<" ";
            }
            cout<<endl;
            
        }
        return 0;

    }
    lp(i, 0, n){
        int x,y;
        x = num[i];
        y =x;
        int times = i+1;
        lp(j, 0, times){
            arr[x][y] = i+1;
            if(y+1<n && arr[x][y+1]==0){
                y+=1;
            }
            else{
                x-=1;
            }
        }
        
    }
    lp(i, 0, n){
            lp(j, 0, i+1){
               cout<<arr[j][i]<<" ";
            }
            cout<<endl;
            
        }
        return 0;




       
    }