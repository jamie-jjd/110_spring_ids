/*
* author: wang-yang
* email: tnst92002@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

char mp[60][60];
int ft[60][60];
int rt[60][60];
int main() {
    int W, H;

    cin >> H >> W;
    for (int i=0;i<H;++i)
        cin >> mp[i];
    int fx, fy;
    int t;
    int sx, sy, ex, ey;

    cin >> fx >> fy
        >> t
        >> sx >> sy >> ex >> ey;

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    queue<tuple<int,int>> qu;

    memset(ft, 0x3f, sizeof(ft));
    const int INF = ft[0][0];

    qu.emplace(fx, fy);
    ft[fx][fy] = 1;

    while (!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();

        for (int i=0;i<4;++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || H <= nx) continue;
            if (ny < 0 || W <= ny) continue;
            if (mp[nx][ny] != '.' || ft[nx][ny]!=INF) continue;
            if (nx == ex && ny == ey) continue;

            ft[nx][ny] = 1 + ft[x][y];
            qu.emplace(nx, ny);
        }
    }

    memset(rt, 0x3f, sizeof(rt));

    qu.emplace(sx, sy);
    rt[sx][sy] = t;

    int d8x[] = {1,1,1,0,0,-1,-1,-1};
    int d8y[] = {1,0,-1,1,-1,1,0,-1};

    while (!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();

        for (int i=0;i<8;++i) {
            int nx = x + d8x[i];
            int ny = y + d8y[i];

            if (nx < 0 || H <= nx) continue;
            if (ny < 0 || W <= ny) continue;
            if (mp[nx][ny] != '.' || rt[nx][ny]!=INF) continue;
            if (1 + rt[x][y] >= ft[nx][ny]) continue;

            rt[nx][ny] = 1 + rt[x][y];
            qu.emplace(nx, ny);
        }
    }

    if (rt[ex][ey] == INF) cout << "Help!\n";
    else cout << rt[ex][ey] - t << '\n';
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <deque>
#include <iostream>
#include <tuple>
#include <vector>

void BuildForest (std::vector<std::vector<int64_t>>& forest, int64_t H, int64_t W)
{
  std::string line;
  for (int64_t r {}; r != H; ++r)
  {
    std::cin >> line;
    for (int64_t c {}; c != W; ++c)
    {
      if (line[c] == '.') { forest[r][c] = H * W; }
    }
  }
  return;
}

void Fire
(
  std::vector<std::vector<int64_t>>& forest,
  int64_t H, int64_t W, int64_t fx, int64_t fy
)
{
  std::vector<int64_t> dx = {-1, 0, 0, 1};
  std::vector<int64_t> dy = {0, -1, 1, 0};
  std::deque<std::tuple<int64_t, int64_t, int64_t>> queue;
  queue.emplace_back(fx, fy, 1);
  forest[fx][fy] = 1;
  while (!queue.empty())
  {
    auto [x, y, d] {queue.front()}; queue.pop_front();
    for (int64_t i {}; i != 4; ++i)
    {
      auto next_x {x + dx[i]}, next_y {y + dy[i]};
      if (-1 < next_x && next_x < H && -1 < next_y && next_y < W && d + 1 < forest[next_x][next_y])
      {
        queue.emplace_back(next_x, next_y, d + 1);
        forest[next_x][next_y] = d + 1;
      }
    }
  }
  return;
}

void Escape
(
  std::vector<std::vector<int64_t>>& forest,
  int64_t H, int64_t W, int64_t k, int64_t sx, int64_t sy, int64_t ex, int64_t ey
)
{
  std::vector<int64_t> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
  std::vector<int64_t> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
  std::deque<std::tuple<int64_t, int64_t, int64_t>> queue;
  if (k < forest[sx][sy])
  {
    queue.emplace_back(sx, sy, k);
    forest[sx][sy] = k;
    while (!queue.empty())
    {
      auto [x, y, d] {queue.front()}; queue.pop_front();
      for (int64_t i {}; i != 8; ++i)
      {
        auto next_x {x + dx[i]}, next_y {y + dy[i]};
        if (-1 < next_x && next_x < H && -1 < next_y && next_y < W && d + 1 < forest[next_x][next_y])
        {
          queue.emplace_back(next_x, next_y, d + 1);
          forest[next_x][next_y] = d + 1;
        }
      }
    }
  }
  return;
}

int main ()
{
  int64_t H, W;
  std::cin >> H >> W;
  std::vector<std::vector<int64_t>> forest(H, std::vector<int64_t>(W));
  BuildForest(forest, H, W);
  int64_t fx, fy, k, sx, sy, ex, ey;
  std::cin >> fx >> fy >> k >> sx >> sy >> ex >> ey;
  forest[ex][ey] = 0;
  Fire(forest, H, W, fx, fy);
  forest[ex][ey] = H * W;
  Escape(forest, H, W, k, sx, sy, ex, ey);
  if (forest[ex][ey] == H * W) { std::cout << "Help!"; }
  else                         { std::cout << (forest[ex][ey] - k); }
  return 0;
}