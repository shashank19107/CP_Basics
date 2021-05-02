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

int nearest;
int node;
vvi graph;
int ans[200005][2];
vi near_s(200005);
int special[200005];
vi visited(200005);

int dfs1 (   int s ){
    visited[s]= 1;
    int ret=-1;
   // cout<<" "<<s<<" ";
    for(int i: graph[s]){
        if(visited[i]==0){
            ret = max(ret , dfs1( i));
        }
    }
    if(special[s]){
        near_s[s] =s;
        return  s;
    }
    near_s[s] = ret;
    return ret;

}

void dfs2( int s ,  int value, int d,  int last_s){
    visited[s]=1;
    if(near_s[s] !=-1){
        value=0;
        last_s=near_s[s];
        ans[s][0] = d;
        ans[s][1] = near_s[s];
    }
    else{
       // cout<<s<<" d is "<<d<<" and last_s is "<<last_s<<" value is "<<value<<endl;
        ans[s][0] = d-value-value;
        ans[s][1] = last_s;
        //cout<<ans[s][0]<<ans[s][1]<<endl;

    }
    for(int i: graph[s]){
        if(visited[i]==0){
             dfs2(   i,  value+1, d+1,   last_s);
        }
    }
    //return ans;




}

int main()
{
    int t;
    cin>>t;
    // int **ans  = new int*[200005];
    // lp(i, 0, 200005){
    //     ans[i] = new int[2];
    // }
    while(t--){
        int n,k,a;
        cin>>n>>k>>a;

        memset(special, 0, sizeof(special[0])*(n+1));
        //cout<<"here";
        
        int tem;
        //cout<<"here";
        lp(i, 0, k){
            cin>>tem;
            special[tem]=1;
        }
        
        //cout<<"Hi\n";
        
        
        lp(i, 0, n+1){
            vi temp;
            graph.push_back(temp);
        }
        //cout<<"here 1\n";
        int x,y;
        lp(i, 1,n){
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);

        }
        nearest = 200005;
        //cout<<"here 2\n";
        
        
        //vi visited(n+1);
        memset(&visited[0] , 0, sizeof(visited[0])*(n+1));
        
        memset(&near_s[0] , 0, sizeof(near_s[0])*(n+1));

        dfs1(   a );
        //cout<<endl;

        lp(i,0,n+1){
           // cout<<near_s[i]<<" ";

            visited[i]=0;
        }
        //cout<<endl;
        
        dfs2(  a,  0, 0,   near_s[a]);
        lp(i, 1, n+1){
            
            cout<<ans[i][0]<<" ";
        }
        cout<<endl;
        lp(i, 1, n+1){
            cout<<ans[i][1]<<" ";
        }
        cout<<endl;
        graph.clear();



    }


        return 0;
    }


  /* HOST_NAME_MAX
  jkhd
  */

