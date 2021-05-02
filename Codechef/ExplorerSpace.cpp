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
    int n, m, k;
    cin>>n>>m>>k;
    int **graph;
    graph = new *int[n];

    lp(i, 0, n){
        graph[i] = new int[m];
    }
    int we;
    lp(i, 0, n){
        lp(j, 0, m-1){
            cin>>we;
            graph[i][j] = we;
            graph
        }
    }


        return 0;
    }