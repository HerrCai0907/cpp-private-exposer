#include "exposer.hpp"
#include <gtest/gtest.h>
#include <vector>

int g;
class Test1 {
public:
  int get_a() { return a; }
  double get_b() { return b; }
  std::vector<int> &get_c() { return c; }

private:
  int a;
  double b;
  std::vector<int> c{};
};

ACCESS(Test1, a, int)
TEST(ExposerPrivate, Integer) {
  Test1 t1{};
  get_a_from_Test1(t1) = 10;
  EXPECT_EQ(t1.get_a(), 10);
}

ACCESS(Test1, b, double)
TEST(ExposerPrivate, Double) {
  Test1 t1{};
  get_b_from_Test1(t1) = 1.2;
  EXPECT_EQ(t1.get_b(), 1.2);
}

ACCESS(Test1, c, std::vector<int>)
TEST(ExposerPrivate, Vec) {
  Test1 t1{};
  std::vector<int> Target{1, 2, 3};
  get_c_from_Test1(t1) = Target;
  EXPECT_EQ(t1.get_c(), Target);
}
