// Topological sorting
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

class Graph
{
private:
    int **adj;
    int n;

public:
    Graph(int numb)
    {
        n = numb;
        adj = new int *[n + 1];
        for (int i = 0; i < n + 1; ++i)
            adj[i] = new int[n + 1];
        for (int i = 0; i < n + 1; ++i)
        {
            for (int j = 0; j < n + 1; j++)
                adj[i][j] = 0;
        }
    }
    void addVertex(int src, int dest)
    {
        adj[src][dest] = 1;
    }
    void TopologicalSort()
    {
        int indegree[n + 1] = {0};
        bool visited[n + 1] = {false};
        int T[n + 1];
        queue<int> s;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[j][i])
                    indegree[i]++;
            }
        }
        cout << "Indegree Array: ";
        print(indegree, n);
        for (int i = 1; i <= n; i++)
        {
            if (!indegree[i])
            {
                s.push(i);
                visited[i] = true;
            }
        }
        int j = 1;
        while (!s.empty())
        {
            int a = s.front();
            s.pop();
            T[j++] = a;
            for (int i = 1; i <= n; i++)
            {
                if (adj[a][i] && !visited[i])
                {
                    indegree[i]--;
                    if (!indegree[i])
                    {
                        s.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
        cout << "Topologically Sorted Vertices: ";
        for (int i = 1; i <= n; i++)
            cout << T[i] << " ";
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter size:";
    cin >> n;
    Graph G(n);
    cout << "Enter edges:" << endl;
    int a, b;
    while (true)
    {
        cin >> a >> b;
        if (a != -1 && b != -1)
            G.addVertex(a, b);
        else
            break;
    }
    G.TopologicalSort();
}
