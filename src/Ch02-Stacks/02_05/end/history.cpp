#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BrowserHistory
{
private:
    stack<string> historyStack;

public:
    // Visiting a website
    void visit(const string &url)
    {
        cout << "Visiting: " << url << endl;
        historyStack.push(url);
    }

    // Clicking the back button
    void back()
    {
        cout << "Navigating back" << endl;
        if (!historyStack.empty())
        {
            historyStack.pop();
        }
    }

    // Checking the current site
    string current() const
    {
        if (historyStack.empty())
        {
            return "No sites currently being viewed.";
        }
        return historyStack.top();
    }
};

int main()
{
    BrowserHistory bh;

    bh.visit("explorecalifornia.org");
    bh.visit("pixelford.com");
    bh.visit("landonhotel.com");

    cout << "Current Site: " << bh.current() << endl;

    bh.back();
    cout << "Current Site: " << bh.current() << endl;

    bh.back();
    cout << "Current Site: " << bh.current() << endl;

    bh.back();
    cout << "Current Site: " << bh.current() << endl;

    return 0;
}
