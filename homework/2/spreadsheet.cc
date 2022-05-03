/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> indeg(n, 0);
    vector<LL> val(n, 0);
    for (int i = 0; i < m; i++) {
        char ch; cin >> ch;
        int e = ch - 'A';
        int v; cin >> v; v--;
        while (e--) {
            int u; cin >> u; u--;
            graph[u].emplace_back(v);
            indeg[v] += 1;
        }
        cin >> val[v];
    }

    queue<int> q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) {
        q.emplace(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : graph[u]) {
            if (--indeg[v] == 0) q.emplace(v);
            val[v] += val[u];
        }
    }
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) cout << val[i] << "\n";
        else cout << "#REF!\n";
    }
}
