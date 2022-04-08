/*
* author: wang-yang
* email: tnst92002@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> run(vector<int> s) {
    int cnt[26] = {0};
    vector<int> res;
    for (int c : s)
        cnt[c]++;
    bool Suc;
    int order = 0;
    do {
        Suc = false;
        if (order == 0) {
            for (int i=0;i<26;++i) {
                if (cnt[i]) {
                    Suc = true;
                    cnt[i]--;
                    res.push_back(i);
                }
            }
        } else {
            for (int i=25;i>=0;--i) {
                if (cnt[i]) {
                    Suc = true;
                    cnt[i]--;
                    res.push_back(i);
                }
            }
        }
        order = 1 - order;
    } while (Suc);
    return res;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        int len;
        cin >> len;
        vector<int> buf(len);
        for (int &i: buf) cin >> i;
        auto res = run(buf);
        for (size_t i=0; i<res.size();++i)
        {
            if (i) cout << ' ';
            cout << res[i];
        }
        cout << '\n';
    }
}