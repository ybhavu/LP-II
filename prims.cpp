#include <bits/stdc++.h>
using namespace std;

#define V 5

int minKey(vector<int> key,vector<bool> mset){

    int min = INT_MAX,min_ind;

    for(int v =0;v<V;v++){
        if(mset[v] == false && key[v]<min){
            min = key[v],min_ind = v;
        }
    }
    return min_ind;
}
void printMST(vector<int> pr,vector<vector<int>> gr){
    cout<<"EDGE \t WEIGHT\n";
    for (int i = 1; i < V; i++)
		cout << pr[i] << " - " << i << " \t"
			<< gr[i][pr[i]] << " \n";
}

void primMST(vector<vector<int>> gr){
    vector<int> pr(V);
    vector<int> key(V,INT_MAX);
    vector<bool> mset(V,false);

    key[0] = 0;

    pr[0] = -1;

    for(int cnt = 0;cnt<V-1;cnt++){
        int u = minKey(key,mset);

        mset[u] = true;

        for(int v =0;v<V;v++){
            if(gr[u][v] && mset[v] == false &&
             gr[u][v]<key[v]){
                pr[v] = u, key[v] = gr[u][v];
                
            }
        }
    }
    printMST(pr,gr);



}

int main(){
    vector<vector<int>> graph= {{ 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };
    
    primMST(graph);


    return 0;
}