#include <iostream>
#include <vector>
// #include <format>

class Route
{
private:
  // Make use of using to understand it
  using vectorOfStrings = std::vector<std::string>; // typedef std::vector<std::string> vectorOfStrings; is old style
  using iterator = std::vector<std::string>::iterator;
  using iteratorC = vectorOfStrings::const_iterator;

  std::vector<std::string> stops;
  std::vector<std::string>::iterator it;
  // NOTE: There is an issue when the underlying array in the vector container is re-allocated.
  // The issue is that when the underlying array is re-allocated, `it` is pointing to an invalid
  // address. This doesn't happen in the list version, because you don't need to re-allocate the
  // contiguous block of memory.
  // If you reserve 100 elements in the underlying array (i.e., comment the line below in the constructor),
  // you will not see any issues, till the vector object needs to reallocate more than 100 elements,
  // at which case, the iterator object will also point to an invalid memory address, so any function
  // trying to use the iterator object will have an issue (not yield correct results) or if you dereference
  // it will crash.
  // That's why keeping track of the current index would be better than keeping track of the current iterator
  int idx = -1;
  iteratorC itC; // Not used. Just to show case how iteratorC type is used.

public:
  Route()
  {
    // stops.reserve(100);
  }
  void add_stop(const std::string &stop)
  {
    std::cout << __func__ << ": " << "-----" << std::endl;
    std::cout << __func__ << ": " << "&stops: " << &stops << ", vector underlying container address: " << stops.data() << ", " << stops.capacity() << std::endl;
    std::cout << __func__ << ": " << "Iterator points to address: " << static_cast<const void *>(&*it) << std::endl;
    stops.push_back(stop);

    if (stops.size() == 1) // stops.begin() == stops.end() - 1
    {
      it = stops.begin();
      int dist = std::distance(it, stops.begin());
      idx = 0;
    }
    std::cout << __func__ << ": " << "&stops: " << &stops << ", vector underlying container address: " << stops.data() << ", " << stops.capacity() << std::endl;
    std::cout << __func__ << ": " << "Iterator points to address: " << static_cast<const void *>(&*it) << std::endl;
  }

  void print()
  {
    if (stops.empty())
    {
      std::cout << __func__ << ": No stops in route" << std::endl;
      return;
    }

    for (auto it = stops.begin(); it < stops.end(); it++)
    {
      size_t i = std::distance(stops.begin(), it); // or size_t index = it - stops.begin()
      // std::cout << std::format("[{}] {}, ", i, *it);
      // int dist = std::distance(it, stops.begin());
      // // std::cout << *it << std::endl;
      // std::cout << dist << std::endl;
      std::cout << "[" << i << "]:" << *it << (i == idx ? "*" : "") << ", ";
    }
    std::cout << "\b\b  " << std::endl;
  }

  void next_stop()
  {
    if (stops.empty())
      return;

    idx++;
    if (idx == stops.size()) // NOTE: stops.size() is similar to stops.end()
    {
      idx = 0;
    }
  }

  void prev_stop()
  {

    if (stops.empty())
      return;

    if (idx == 0)
    {
      idx = stops.size();
    }
    idx--;
  }

  void remove_stop(const std::string &stop)
  {
    auto it = std::find(stops.begin(), stops.end(), stop);
    const int index = std::distance(stops.begin(), it);
    std::cout << __func__ << ": " << index << std::endl;
    if (it != stops.end())
    {
      std::cout << __func__ << ": element / value found "
                << std::endl;
      stops.erase(it);
      idx--;
    }
    else
    {
      std::cout << __func__ << ": value \"" << stop << "\" not available in route " << std::endl;
    }
  }

  friend std::ostream &operator<<(std::ostream &os, const Route &route)
  {
    os << __func__ << ": " << "idx: " << route.idx;
    return os;
  }
};

int main(void)
{
  Route route;
  route.add_stop("A");
  // route.add_stop("B");
  // route.add_stop("C");
  // route.add_stop("D");
  route.next_stop();
  route.next_stop();
  route.remove_stop("X");
  route.remove_stop("A");
  route.print();
  std::cout << route << std::endl;
  // operator<<(std::cout, route) << std::endl;
}