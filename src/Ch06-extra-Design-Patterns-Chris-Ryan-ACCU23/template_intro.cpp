#include <vector>
#include <set>
#include <iostream>

template <typename Container>
void print(const Container &c)
{
  std::cout << "{";

  // for (int i = 0; i < c.size(); i++)
  // {
  //   std::cout << c.at(i) << ", ";
  // }

  // for (auto it = c.begin(); it != c.end(); it++)
  // {
  //   std::cout << *it << ", ";
  // }
  // if (c.empty())
  //   std::cout << "}";
  // else
  //   std::cout << "\b\b} \n";

  std::cout << __PRETTY_FUNCTION__ << std::endl;
  // Recommended fix by Gemini
  const char *separator = "";
  for (const auto &element : c)
  {
    std::cout << separator << element;
    separator = ", ";
  }
  std::cout << "} \n";
}

int main()
{
  std::vector vec{1, 2, 3, 4, 4};
  std::set set{1, 2, 3, 4, 4};
  print(vec);
  print(set);
  print<std::vector<int>>(vec); // You must specify the full type, e.g., std::vector<int>
  return 0;
}

// #include <vector>
// #include <set>
// #include <iostream>

// // To use runtime polymorphism, we first define an abstract interface (a "contract").
// // Any class that inherits from IPrintable and implements printTo can be used.
// struct IPrintable
// {
//   virtual ~IPrintable() = default;                  // Virtual destructor is essential for polymorphic base classes.
//   virtual void printTo(std::ostream &os) const = 0; // Pure virtual function.
// };

// // Next, we create an "adapter" class. It's a template that can wrap any container,
// // and it implements our IPrintable interface.
// template <typename Container>
// class PrintableContainer : public IPrintable
// {
// public:
//   // Store a reference to the actual container.
//   PrintableContainer(const Container &c) : container_(c) {}

//   // Implement the interface's virtual function. This is where the print logic now lives.
//   void printTo(std::ostream &os) const override
//   {
//     os << "{";
//     const char *separator = "";
//     for (const auto &element : container_)
//     {
//       os << separator << element;
//       separator = ", ";
//     }
//     os << "} \n";
//   }

// private:
//   const Container &container_;
// };

// // The print function is no longer a template. It takes a reference to the abstract
// // interface. It has no idea what the concrete type (vector, set, etc.) is.
// void print(const IPrintable &printable)
// {
//   // The call to printTo() is resolved at RUNTIME via virtual dispatch.
//   printable.printTo(std::cout);
// }

// int main()
// {
//   std::vector vec{1, 2, 3, 4, 4};
//   std::set set{1, 2, 3, 4, 4};

//   // We wrap our concrete containers in the adapter before calling print.
//   PrintableContainer<std::vector<int>> printable_vec(vec);
//   PrintableContainer<std::set<int>> printable_set(set);

//   print(printable_vec);
//   print(printable_set);

//   // Note: The old way of calling `print(vec)` will no longer compile
//   // because `print` is not a template and `std::vector` does not implement `IPrintable`.
//   return 0;
// }