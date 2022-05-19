/*
* author: wang-yang
* email: tnst92002@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> V;
void dfs(int v) {
    cout << ' ' << v;
    for (int u:V[v])
        dfs(u);
    cout << ' ' << v;
}

int main() {
    int N;
    cin >> N;
    V.resize(N);

    for (int i=0;i<N;++i) {
        int v, u;
        cin >> v;
        while (v--) {
            cin >> u;
            V[i].emplace_back(u);
        }
    }

    cout << "Euler tour:";
    dfs(0);
    cout << '\n';
}