#include <queue>
#include <iostream>

class MerchOrderSystem
{
private:
  std::queue<int> normalPriorityQueue, highPriorityQueue;

public:
  void placeOrder(int orderId, bool isPriority)
  {
    std::queue<int> *ptrQueue;
    if (isPriority)
    {
      ptrQueue = &highPriorityQueue;
    }
    else
    {
      ptrQueue = &normalPriorityQueue;
    }
    ptrQueue->push(orderId);
    std::cout << __func__
              << "OrderId: " << orderId << ", priority : " << (isPriority ? "high" : "normal") << " "
              << ", " << "Orders normalPriority: " << normalPriorityQueue.size()
              << ", " << "Orders highPriority: " << highPriorityQueue.size()
              << std::endl;
  }

  int fulfillOrder()
  {

    int orderId = -1;

    if (!highPriorityQueue.empty())
    {
      orderId = highPriorityQueue.front();
      highPriorityQueue.pop();
      std::cout << __func__ << "highPriorityOrderId " << orderId << " fulfilled" << std::endl;
      return orderId;
    }

    if (!normalPriorityQueue.empty())
    {
      orderId = normalPriorityQueue.front();
      normalPriorityQueue.pop();
      std::cout << __func__ << "normalPriorityQueue " << orderId << " fulfilled" << std::endl;
      return orderId;
    }

    std::cout << __func__ << ": No order ids available to be fulfilled" << std::endl;
    return -1;
  }
};

int main(void)
{

  MerchOrderSystem system;
  system.placeOrder(1, true);
  system.placeOrder(3, true);
  system.placeOrder(2, false);
  system.fulfillOrder();
  system.fulfillOrder();
  system.fulfillOrder();
  system.fulfillOrder();
}