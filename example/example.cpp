#include "exposer.hpp"
#include <iostream>

class Test {
  double a = 0.5;

public:
  void dump() { std::cout << "dump: " << a << std::endl; }
};

ACCESS(Test, a, double)

int main() {
  Test t{};
  std::cout << ::get_a_from_Test(t) << std::endl;
  t.dump();
  ::get_a_from_Test(t) -= 1;
  std::cout << ::get_a_from_Test(t) << std::endl;
  t.dump();
}
