#include <iostream>
#include <stack>

class BrowserHistory
{
private:
  std::stack<std::string> historyStack;
  // size_t pageCount = 0;

public:
  void visit(const std::string &url)
  {
    historyStack.push(url);
    // pageCount++;
  }

  void back()
  {
    if (!historyStack.empty())
    {
      historyStack.pop();
      // pageCount--;
    }
  }

  std::string current() const
  {
    if (historyStack.empty())
      return "N/A";

    return historyStack.top();
  }

  size_t getPageCount() const
  {
    return historyStack.size();
  }
};

int main()
{
  BrowserHistory history;
  std::cout << "current: " << history.current() << ", pageCount: " << history.getPageCount() << std::endl;
  history.visit("https://sensya.com");
  history.visit("https://www.yahoo.com");
  std::cout << "current: " << history.current() << ", pageCount: " << history.getPageCount() << std::endl;
  history.back();
  std::cout << "current: " << history.current() << ", pageCount: " << history.getPageCount() << std::endl;
}