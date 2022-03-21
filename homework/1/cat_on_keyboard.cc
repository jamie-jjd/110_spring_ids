/*
* author: redleaf
* email: redleaf23477@gapp.nthu.edu.tw
*/
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        string str; cin >> str;
        list<char> ans;

        auto it = ans.end();
        for (auto ch : str) {
            if (ch == '[') {
                it = ans.begin();
            } else if (ch == ']') {
                it = ans.end();
            } else {
                ans.insert(it, ch);
            }
        }

        for (auto x : ans) cout << x;
        cout << "\n";
    }
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <list>

int main ()
{
  uint64_t T {};
  std::cin >> T;
  while (T--)
  {
    std::string line;
    std::cin >> line;
    std::list<char> output;
    auto it {output.end()};
    for (auto c : line)
    {
      if (c == '[')       { it = output.begin(); }
      else if (c == ']')  { it = output.end(); }
      else                { output.insert(it, c); }
    }
    for (auto c : output) { std::cout << c; }
    std::cout << "\n";
  }
  return 0;
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <deque>

void FlushBufferToOutput (std::deque<char>& buffer, std::deque<char>& output)
{
  while (!buffer.empty())
  {
    output.push_front(buffer.back());
    buffer.pop_back();
  }
  return;
}

int main ()
{
  uint64_t T {};
  std::cin >> T;
  while (T--)
  {
    std::string line;
    std::cin >> line;
    std::deque<char> buffer, output;
    bool is_end {true};
    for (auto c : line)
    {
      if (c == '[')
      {
        is_end = false;
        FlushBufferToOutput(buffer, output);
      }
      else if (c == ']')
      {
        is_end = true;
      }
      else
      {
        if (is_end) { output.push_back(c); }
        else        { buffer.push_back(c); }
      }
    }
    FlushBufferToOutput(buffer, output);
    for (auto c : output) { std::cout << c; }
    std::cout << "\n";
  }
  return 0;
}