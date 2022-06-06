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
    unordered_set<string> s;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        s.insert(str);
    }
    int q; cin >> q;
    int op1_cnt = 0;
    while (q--) {
        int op; cin >> op;
        string str; cin >> str;
        if (op == 1) {
            op1_cnt += 1;
            s.insert(str);
            cout << s.size() << "\n";
        } else if (op == 2) {
            s.erase(str);
            cout << s.size() << "\n";
        } else {
            cout << (s.count(str) == 1? "Yes\n" : "No\n");
        }
    }
}