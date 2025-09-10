#include <stack>
#include <iostream>
#include <string>

std::string reverseString(const std::string &str)
{
  //Time: O(n), Space: O(n)
  
  std::stack<char> stack;
  std::string str_out = "";

  for (int i = 0; i < str.length(); i++)
  {
    stack.push(str[i]);
  }

  while (!stack.empty())
  {
    str_out = str_out + stack.top();
    stack.pop();
  }

  return str_out;
}

int main()
{
  std::string reversed_str;
  reversed_str = reverseString("abcdef");
  std::cout << reversed_str << std::endl;
  reversed_str = reverseString("Hello, World\n");
  std::cout << reversed_str << std::endl;
}