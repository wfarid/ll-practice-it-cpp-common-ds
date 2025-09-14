#include <iostream>
#include <list>

class Route
{
private:
  std::list<std::string> stops;
  // auto it = stops.begin();
  std::list<std::string>::iterator it;

public:
  void add_stop(const std::string &stop)
  {
    stops.push_back(stop);
    std::cout << __func__ << ": " << stop << ", list size: " << stops.size() << std::endl;
    // std::advance(it, 1);
    if (stops.size() == 1)
    {
      it = stops.begin();
    }
  }

  std::string current_stop()
  {
    if (!stops.empty())
      return *it;
    else
      return "N/A";
  }

  void next_stop()
  {
    if (stops.empty())
      return;

    // std::advance(it, 1); // why doesn't it++ work?
    it++;
    if (it == stops.end())
    {
      std::cout << __func__ << ": " << "it ptr passed last node" << std::endl;
      // it--;
      it = stops.begin();
    }
  }

  void prev_stop()
  {
    if (stops.empty())
      return;

    if (it == stops.begin())
    {
      std::cout << __func__ << ": " << "it ptr passed first node" << std::endl;
      it = stops.end();
    }
    it--;
  }

  void remove_stop()
  {
    // TODO: To remove a stop.
  }

  void set_stop_to_first()
  {
    std::cout << __func__ << std::endl;
    it = stops.begin();
  }

  void set_stop_to_last()
  {
    std::cout << __func__ << std::endl;
    it = stops.end();
    it--;
  }

  void print()
  {
    for (auto iter = stops.begin(); iter != stops.end(); iter++)
    {
      size_t i = std::distance(stops.begin(), iter); // or size_t index = it - stops.begin()
      // std::cout << std::format("[{}] {}, ", i, *it);
      int dist = std::distance(iter, it);
      std::cout << "[" << i << "]:" << *iter << (dist == 0 ? "*" : "") << ", ";
    }
    std::cout << "\b\b  " << std::endl;
  }
};

int main(void)
{
  std::cout << __FILE__ << std::endl;
  Route route;
  route.add_stop("Stop A");
  route.add_stop("Stop B");
  route.next_stop();
  route.add_stop("C");
  route.add_stop("D");
  route.next_stop();
  route.print();
  std::cout << "current stop: " << route.current_stop() << std::endl;
  // route.next_stop();
  // route.next_stop();
  route.set_stop_to_first();
  std::cout << "current stop: " << route.current_stop() << std::endl;
  route.prev_stop();
  std::cout << "current stop: " << route.current_stop() << std::endl;
  std::cout << std::flush;
}