/*
* author: wang-yang
* email: tnst92002@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    stack <char> st;
    for (char c : s) {
        switch (c) {
            case '(':
                st.emplace(')');
                break;
            case '[':
                st.emplace(']');
                break;
            case ')':
            case ']':
                if (st.empty() || st.top() != c)
                    return false;
                st.pop();
                break;
            default:
                __builtin_unreachable();
        }
    }
    return st.empty();
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        string buf;
        cin >> buf;
        if (check(buf)) cout << "Yes\n";
        else cout << "No\n";
    }
}