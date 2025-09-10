#include <queue>
#include <iostream>

class CallCenter
{
private:
  std::queue<int> idQueue;

public:
  void receive_call(const int &id)
  {
    idQueue.push(id);
  }

  int process_call()
  {
    if (idQueue.empty())
    {
      return -1;
    }
    int id = idQueue.front();
    idQueue.pop();
    return id;
  }

  int getRemainingCallsCount() const
  {
    return idQueue.size();
  }
};

int main(void)
{
  std::cout << __FILE__ << std::endl;
  CallCenter callCenter;
  std::cout << callCenter.process_call() << ", RemainingCallsCount: " << callCenter.getRemainingCallsCount() << std::endl;
  callCenter.receive_call(12345);
  callCenter.receive_call(55555);
  std::cout << callCenter.process_call() << ", RemainingCallsCount: " << callCenter.getRemainingCallsCount() << std::endl;
}