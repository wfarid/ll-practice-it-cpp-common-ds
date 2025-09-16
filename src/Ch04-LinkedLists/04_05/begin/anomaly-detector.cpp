#include <iostream>
#include <list>

template <class T>
class SensorData
{
private:
  std::list<T> list;

public:
  void add_reading(T value)
  {
    list.push_back(value);
  }

  void smooth_data_by_elimination()
  {
    if (list.size() < 2)
      return;

    for (auto it = list.begin(); it != list.end();)
    {
      auto it_next = it;
      it_next++;

      if (it_next == list.end() || list.empty())
      {
        break;
      }

      if (*it_next > 2.0 * (*it))
      {
        std::cout << "Spike detected" << std::endl;
        // std::advance(it, 2); //Noted: commented to keep looing at the same element, after one node/element is removed
        list.erase(it_next);
        continue;
      }

      if (*it_next < 0.5 * (*it))
      {
        std::cout << "Dip detected" << std::endl;
        // std::advance(it, 2); //Noted: commented to keep looing at the same element, after one node/element is removed
        list.erase(it_next);
        continue;
      }

      it++;
    }
  }

  void smooth_data()
  {
    if (list.size() < 2)
      return;

    auto prev = list.begin();
    auto curr = prev;
    curr++;
    while (curr != list.end())
    {
      if (*curr >= (*prev * 2) || *curr <= (*prev * 0.5))
      {
        *curr = *prev;
      }
      curr++;
      prev++;
    }
  }

  void print_data(std::string prefix = "")
  {
    if (!prefix.empty())
      std::cout << prefix << ": ";

    if (list.empty())
    {
      std::cout << "{}" << std::endl;
      return;
    }

    std::cout << "{";
    for (auto const &v : list)
    {
      std::cout << v << ", ";
    }
    std::cout << "\b\b} " << std::endl;
  }
};

auto main() -> int
{
  std::cout << __FILE__ << std::endl;
  SensorData<float> dataOne;
  dataOne.add_reading(10.0);
  dataOne.add_reading(4.0);
  dataOne.add_reading(0.4);
  dataOne.print_data("dataOne prior smoothing by elimination");
  dataOne.smooth_data_by_elimination();
  dataOne.print_data("dataOne post  smoothing by elimination");

  SensorData<double> dataTwo;
  dataTwo.add_reading(10.0);
  dataTwo.add_reading(24.0);
  dataTwo.add_reading(6.0);
  dataTwo.add_reading(2.0);
  dataTwo.add_reading(4.0);
  dataTwo.print_data("dataTwo prior smoothing");
  dataTwo.smooth_data();
  dataTwo.print_data("dataTwo post  smoothing");
}