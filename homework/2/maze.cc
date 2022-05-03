/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using P = tuple<int,int>;

P find_pos(vector<string> &maze, char ch) {
    for (size_t i = 0; i < maze.size(); i++) {
        for (size_t j = 0; j < maze[i].size(); j++) {
            if (maze[i][j] == ch) return P(i, j);
        }
    }
    return P(-1, -1);
}

bool bfs(vector<string> &maze, const P START) {
    vector<int> dr {-1, 1, 0, 0}, dc {0, 0, -1, 1};
    string dir("UDLR");
    auto legal = [&](int r, int c) {
        return 0 <= r && r < (int)maze.size() && 0 <= c && c < (int)maze[0].size();
    };
    auto print_sol = [&](int r, int c) {
        string str;
        while (P(r, c) != START) {
            char d = maze[r][c];
            str.push_back(d);
            if (d == 'U') r += 1;
            else if (d == 'D') r -= 1;
            else if (d == 'L') c += 1;
            else c -= 1;
        }
        reverse(str.begin(), str.end());
        cout << str.size() << "\n";
    };
    // bfs
    queue<P> q({START});
    while (!q.empty()) {
        P f = q.front(); q.pop();
        auto [r, c] = f;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (!legal(nr, nc)) continue;
            if (maze[nr][nc] == '.') {
                maze[nr][nc] = dir[i];
                q.emplace(nr, nc);
            } else if (maze[nr][nc] == 'B') {
                maze[nr][nc] = dir[i];
                print_sol(nr, nc);
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<string> maze(n);
    for (auto &r : maze) cin >> r;
    P pos_start = find_pos(maze, 'A');
    if (!bfs(maze, pos_start)) {
        cout << "IMPOSSIBLE\n";
    }
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <deque>
#include <iostream>
#include <tuple>
#include <vector>

auto Coordinates (std::vector<std::string> const& maze, char ch)
{
  auto R {static_cast<int64_t>(maze.size())};
  auto C {static_cast<int64_t>(maze[0].size())};
  int64_t r {}, c {};
  while (r != R)
  {
    if (maze[r][c] == ch) { break; }
    if (c != C) { ++c; }
    else        { ++r; c = 0; }
  }
  return std::make_pair(r, c);
}

int64_t ShortestDistance
(
  std::vector<std::string> const& maze,
  int64_t r_A,
  int64_t c_A,
  int64_t r_B,
  int64_t c_B
)
{
  auto R {static_cast<int64_t>(maze.size())};
  auto C {static_cast<int64_t>(maze[0].size())};
  std::vector<int64_t> dr = {0, 0, 1, -1};
  std::vector<int64_t> dc = {1, -1, 0, 0};
  std::vector<std::vector<bool>> is_in_deque(maze.size(), std::vector<bool>(maze[0].size()));
  std::deque<std::tuple<int64_t, int64_t, int64_t>> queue;
  queue.push_back(std::make_tuple(r_A, c_A, 0));
  is_in_deque[r_A][c_A] = true;
  while (!queue.empty())
  {
    auto [r, c, d] {queue.front()}; queue.pop_front();
    for (uint64_t i {}; i != 4; ++i)
    {
      auto next_r {r + dr[i]}, next_c {c + dc[i]};
      if
      (
        next_r != -1 &&
        next_r != R &&
        next_c != -1 &&
        next_c != C &&
        maze[next_r][next_c] != '#' &&
        !is_in_deque[next_r][next_c]
      )
      {
        if (next_r == r_B && next_c == c_B) { return (d + 1); }
        queue.push_back(std::make_tuple(next_r, next_c, d + 1));
        is_in_deque[next_r][next_c] = true;
      }
    }
  }
  return 0;
}

int main ()
{
  int64_t R, C;
  std::cin >> R >> C;
  std::vector<std::string> maze(R);
  for (auto& row : maze) { std::cin >> row; }
  auto [r_A, c_A] {Coordinates(maze, 'A')};
  auto [r_B, c_B] {Coordinates(maze, 'B')};
  auto d {ShortestDistance(maze, r_A, c_A, r_B, c_B)};
  if (d) { std::cout << d; }
  else   { std::cout << "IMPOSSIBLE"; }
  return 0;
}
