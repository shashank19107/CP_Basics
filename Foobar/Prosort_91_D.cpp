#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <cstring>
#include<math.h>
#include <bits/stdc++.h>

using namespace::std;

bool bfs(int visited[], vector< pair<int, int>> graph[], int i, int curr, int cor[] ){
    for(auto it= graph[i].begin(); it!=graph[i].end();it++){
        if(visited[it->first]==1){
            if(cor[it->first]!= curr + it->second){
                //cout<<it->first<<" returning "<<curr<<endl;
                return false;
            }
        }
            else{
                cor[it->first]= curr + it->second;
                visited[it->first]=1;
                if(bfs(visited, graph, it->first, cor[it->first], cor)==false){
                    //cout<<it->first<<" returning "<<curr<<endl;
                    return false;
                }
        }
    
    }
    return true;
}



int main(){

    int n;
    cin>>n;
    int m;
    cin>>m;
    vector< pair<int, int>> graph[n+1];
    for(int i=0; i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,(-1)*w));
        
    }
    int visited[n+1];
    int cor[n+1];
    memset(visited, 0, sizeof(visited));
    memset(cor, 0, sizeof(cor));
    bool ans =true;
    for(int i=1; i<=n;i++){
        if(visited[i]==0){
            visited[i] = 1;
            cor[i] = 0;
            ans &= bfs(visited, graph, i, 0, cor);
        }
    }
    if(ans){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }










    return 0;
}
