/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

/*
 *  Actually this problem is Dilworth theorem:
 *  Let (x1, y1) <= (x2, y2) iff x1 <= x2 and y1 <= y2
 *  Let (x1, y1) || (x2, y2) iff x1 < x2 and y1 > y2   (incompariable)
 *
 *  The answer is size of the largest antichain of A+B
 */

/*
 * Solution 1 : merge
 */
void sol1() {
    int n, m; cin >> n >> m;
    vector<int> Ax(n), Ay(n);
    vector<int> Bx(m), By(m);
    for (int i = 0; i < n; i++) cin >> Ax[i] >> Ay[i];
    for (int i = 0; i < m; i++) cin >> Bx[i] >> By[i];

    int ans = n + m;
    for (int i = 0, j = 0; i < n && j < m;) {
        if (Ax[i] < Bx[j]) {
            if (Ay[i] <= By[j]) ans--;
            i++;
        } else if (Ax[i] == Bx[j]) {
            if (Ay[i] <= By[j]) i++;
            else j++;
            ans--;
        } else {  // Ax[i] > Bx[j]
            if (By[j] <= Ay[i]) ans--;
            j++;
        }
    }
    cout << ans << "\n";
}

/*
 * Solution 2 : stack
 */
void sol2() {
    using P = pair<int,int>;
    int n, m; cin >> n >> m;
    vector<P> arr(n + m);
    for (auto &[x, y] : arr) cin >> x >> y;
    sort(arr.begin(), arr.end());

    stack<int> Y;
    for (const auto &[x, y] : arr) {
        while (!Y.empty()) {
            if (Y.top() <= y) Y.pop();
            else break;
        }
        Y.emplace(y);
    }

    cout << Y.size() << "\n";
}

/*
 * Solution 3: bucket sort like idea
 *   In the merged list, find the maximum y for each x
 *   Then deleted the dominated points
 */
void sol3() {
    int n, m; cin >> n >> m;
    vector<int> bucket(1000000+1, -1);
    for (int i = 0; i < n + m; i++) {
        int x, y; cin >> x >> y;
        bucket[x] = max(bucket[x], y);
    }
    int ans = 0, mx = 0;
    for (int c = 1000000; c > 0; c--) {
        if (bucket[c] > mx) {
            mx = bucket[c], ans++;
        }
    }
    cout << ans << "\n";
}

/*
 * Solution 4: binary search
 *   For each point find if it is dominated by point in another chain
 */
void sol4() {
    int n, m; cin >> n >> m;
    map<int,int> A, B;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        A[x] = y;
    }
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        B[x] = y;
    }
    int ans = n + m;
    for (auto [x, y] : A) {
        auto it = B.lower_bound(x);
        if (it != B.end() && it->second >= y) ans--;
    }
    for (auto [x, y] : B) {
        auto it = A.lower_bound(x);
        if (it != A.end() && it->second >= y) ans--;
        if (it != A.end() && x == it->first && y == it->second) ans++; // avoid deleteing equal points twice
    }
    cout << ans << "\n";
}

int main() {
    sol1();
    // sol2();
    // sol3();
    // sol4();
}