/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; s.insert(x);
    }
    int q; cin >> q;
    while (q--) {
        int op, x; cin >> op >> x;
        if (op == 1) {
            s.insert(x);
            cout << s.size() << "\n";
        } else if (op == 2) {
            s.erase(x);
            cout << s.size() << "\n";
        } else if (op == 3) {
            cout << (s.count(x) == 1? "Yes\n" : "No\n");
        } else if (op == 4) {
            auto it = s.lower_bound(x);
            cout << (it == s.end()? -1 : *it) << "\n";
        } else {
            auto it = s.upper_bound(x);
            cout << (it == s.end()? -1 : *it) << "\n";
        }
    }
}

