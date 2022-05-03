/*
* author: jamie
* email: jinjiedeng.jjd@gmail.com
*/
#include <iostream>
#include <vector>

int64_t Priority (char c)
{
  if      (c == '*' || c == '/') { return 2; }
  else if (c == '+' || c == '-') { return 1; }
  return 0;
}

void InfixToPostfix (std::string const& infix, std::string& postfix)
{
  std::string stack;
  for (auto c : infix)
  {
    if ('A' <= c && c <= 'E')
    {
      postfix.push_back(c);
    }
    else if (c == '(')
    {
      stack.push_back(c);
    }
    else if (c == ')')
    {
      while (stack.back() != '(')
      {
        postfix.push_back(stack.back());
        stack.pop_back();
      }
      stack.pop_back();
    }
    else
    {
      auto priority {Priority(c)};
      while (!stack.empty() && Priority(stack.back()) >= priority)
      {
        postfix.push_back(stack.back());
        stack.pop_back();
      }
      stack.push_back(c);
    }
  }
  while (!stack.empty())
  {
    postfix.push_back(stack.back());
    stack.pop_back();
  }
  return;
}

int64_t Evaluate (std::string const& postfix, std::vector<int64_t> const& values)
{
  std::vector<int64_t> stack;
  for (auto c : postfix)
  {
    if ('A' <= c && c <= 'E')
    {
      stack.push_back(values[c - 'A']);
    }
    else
    {
      auto rhs {stack.back()}; stack.pop_back();
      auto lhs {stack.back()}; stack.pop_back();
      if      (c == '+')  { stack.push_back(lhs + rhs); }
      else if (c == '-')  { stack.push_back(lhs - rhs); }
      else if (c == '*')  { stack.push_back(lhs * rhs); }
      else if (c == '/')  { stack.push_back(lhs / rhs); }
    }
  }
  return stack.back();
}

int main ()
{
  std::string infix;
  std::cin >> infix;
  std::string postfix;
  InfixToPostfix(infix, postfix);
  uint64_t T;
  std::cin >> T;
  std::vector<int64_t> values(5);
  while (T--)
  {
    for (auto& value : values) { std::cin >> value; }
    std::cout << Evaluate(postfix, values) << "\n";
  }
  return 0;
}