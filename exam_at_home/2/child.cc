/*
* author: wang-yang
* email: tnst92002@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> V;
    vector<int> indeg;
    vector<int> w;
    V.resize(N);
    w.resize(N);
    indeg.resize(N, 0);

    for (int i=0;i<N;++i) {
        cin >> w[i];
    }

    while (M--) {
        int s, t;
        cin >> s >> t;
        V[s].emplace_back(t);
        indeg[t]++;
    }

    stack<int> st;
    for (int i=0;i<N;++i)
        if (indeg[i] == 0)
            st.emplace(i);

    vector<int> res;
    while (!st.empty()) {
        int v = st.top();
        st.pop();

        res.emplace_back(v);
        for (int u:V[v])
        {
            indeg[u]--;
            if (indeg[u] == 0)
                st.emplace(u);
        }
    }

    reverse(res.begin(), res.end());

    for (int v:res)
        for (int u:V[v])
            w[v] = max(w[v], w[u]);

    for (int i=0;i<N;++i) {
        if(i)cout <<' ';
        cout << w[i];
    }
}
