#include <iostream>
#include <vector>
using namespace std;

const int n = 6;
bool visited[n] = {};

void dfs_recursion(const vector<vector<int>> &adj_list, int s)
{
    if (visited[s])
        return;
    visited[s] = true;
    cout << s << " -> ";
    for (int v : adj_list[s])
        dfs_recursion(adj_list, v);
}

int main()
{
    vector<vector<int>> adj_list = {{1, 3, 4}, {0, 2, 4}, {1, 5}, {0, 4}, {0, 1, 3}, {2}};
    dfs_recursion(adj_list, 0);
    cout << endl;
}