#include <bits/stdc++.h>
using namespace std;

void dfsrecurr(vector<vector<int>> &v, int st, vector<bool> &visited)
{
    visited[st] = true;
    cout << st << " ";

    for (int i = 0; i < v[st].size(); ++i)
    {
        int adjver = v[st][i];
        if (!visited[adjver])
        {
            dfsrecurr(v, adjver, visited);
        }
    }
}

void dfs(vector<vector<int>> &v, int st)
{
    int n = v.size();
    vector<bool> visited(n, false);
    dfsrecurr(v, st, visited);
}

void bfs(vector<vector<int>> &v, int st)
{
    int n = v.size();
    vector<bool> visited(n, false);
    visited[st] = true;
    queue<int> q;
    q.push(st);

    while (!q.empty())
    {
        int curr = q.front();
        cout << curr << " ";
        q.pop();

        for (int i = 0; i < v[curr].size(); ++i)
        {
            int adjver = v[curr][i];
            if (!visited[adjver])
            {
                visited[adjver] = true;
                q.push(adjver);
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    vector<vector<int>> v(n);

    cout << "Enter edges: " << endl;
    for (int i = 0; i < 5; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout << "DFS :" << endl;
    dfs(v, 0);
    cout << endl;

    cout << "BFS :" << endl;
    bfs(v, 0);
    cout << endl;

    return 0;
}