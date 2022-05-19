/*
* author: wang-yang
* email: tnst92002@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

int ord[256] = {0};
vector<char> trans(string s) {
    ord['('] = 7122;
    ord['&'] = 1;
    ord['|'] = 2;
    ord['^'] = 3;
    vector<char> res;
    stack<char> st;

    for (char c:s) {
        if (isalnum(c)) {
            res.emplace_back(c);
        } else if (c=='(') {
            st.push(c);
        } else if (c==')') {
            while (true) {
                c = st.top(); st.pop();
                if (c=='(')
                    break;
                res.emplace_back(c);
            }
        } else {
            while (!st.empty() && ord[st.top()] < ord[c] ) {
                res.emplace_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        res.emplace_back(st.top());
        st.pop();
    }

    return res;
}

bool run(const vector<char> &expr, bool *v) {
    stack<bool> st;

    for (auto c : expr) {
        if (isdigit(c)) {
            st.emplace(c-'0');
        } else if (isalpha(c)) {
            st.emplace(v[c-'A']);
        } else {
            bool R = st.top(); st.pop();
            bool L = st.top(); st.pop();

            switch (c) {
                case '&': L&=R; break;
                case '|': L|=R; break;
                case '^': L^=R; break;
            }

            st.emplace(L);
        }
    }

    return st.top();
}

int main() {
    string buf;
    getline(cin, buf);

    auto expr = trans(buf);

    int T;
    cin >> T;
    while (T--) {
        bool val[5];
        for (int i=0;i<5;++i)
            cin >> val[i];
        cout << !!run(expr, val) << '\n';
    }
}