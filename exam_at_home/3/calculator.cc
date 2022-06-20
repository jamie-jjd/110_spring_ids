/*
* author: wang-yang
* email: tnst92002@gmail.com
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> mp;
    int T;

    cin >> T;

    auto getLV = [&](){
        string s;
        cin >> s;
        if (isdigit(s[0]) || s[0] == '-')
            return stoi(s);
        return mp[s];
    };

    while (T--) {
        string op;

        cin >> op;

        if (op == "print") cout << getLV() << '\n';
        else {
            // add R1, L1, L2 // a1 = a2 + a3
            string RV;
            cin >> RV;

            int L1 = getLV();
            int L2 = getLV();
            
            if (op == "add") L1 = L1 + L2;
            else if (op == "sub") L1 = L1 - L2;
            else if (op == "mul") L1 = L1 * L2;
            else if (op == "div") L1 = L1 / L2;

            mp[RV] = L1;
            cout << L1 << '\n';
        }
    }
}

/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <unordered_map>

int32_t LookupSymbolTable
(
  std::unordered_map<std::string, int32_t>& symbol_table,
  std::string const& rvalue
)
{
  if (rvalue[0] == '-' || std::isdigit(rvalue[0])) { return std::stoi(rvalue); }
  return symbol_table[rvalue];
}

int main ()
{
  uint64_t T; std::cin >> T;
  std::unordered_map<std::string, int32_t> symbol_table;
  while (T--)
  {
    std::string operation, lvalue, rvalue_0, rvalue_1;
    std::cin >> operation >> lvalue;
    if (operation != "print")
    {
      std::cin >> rvalue_0 >> rvalue_1;
      auto rvalue_0_int {LookupSymbolTable(symbol_table, rvalue_0)};
      auto rvalue_1_int {LookupSymbolTable(symbol_table, rvalue_1)};
      if (operation == "add")       { symbol_table[lvalue] = rvalue_0_int + rvalue_1_int; }
      else if (operation == "sub")  { symbol_table[lvalue] = rvalue_0_int - rvalue_1_int; }
      else if (operation == "mul")  { symbol_table[lvalue] = rvalue_0_int * rvalue_1_int; }
      else if (operation == "div")  { symbol_table[lvalue] = rvalue_0_int / rvalue_1_int; }
      std::cout << symbol_table[lvalue] << "\n";
    }
    else { std::cout << symbol_table[lvalue] << "\n"; }
  }
  return 0;
}