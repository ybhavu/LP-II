#include <bits/stdc++.h>
using namespace std;

#define V 9

int minDist(vector<int> dist,vector<bool> sset){
    int min = INT_MAX,min_ind;

    for(int v=0;v<V;v++){
        if(sset[v] == false && dist[v]<=min){
            min = dist[v],min_ind= v;
        }
    }
    return min_ind;
}

void printSol(vector<int> dist){
    cout << "Vertex \t Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijktras(vector<vector<int>> gr, int src){
    vector<int> dist(V,INT_MAX);
    dist[src] = 0;

    vector<bool> sset(V,false);

    for(int cnt = 0;cnt < V-1;cnt++){
        int u = minDist(dist,sset);

        sset[u] = true;
        // cout<<u<<endl;
        for(int v =0;v<V;v++){

            if(!sset[v] && gr[u][v] && dist[u] != INT_MAX
             && dist[u]+gr[u][v] < dist[v]){
                dist[v] = dist[u] +gr[u][v];
                // cout<<v<<endl;
             }
        }
        

    }
    printSol(dist);
}

int main(){
    vector<vector<int>>gr = {{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }};

    dijktras(gr,0);
    return 0;
}