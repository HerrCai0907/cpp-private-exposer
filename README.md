# cpp-private-exposer

This project want to expose private member in cpp and make it readable and writeable.

## usage

```c++
#include "exposer.hpp"

class Test {
    double a = 0.5;
};
ACCESS(Test, a, double)
int main() {
    double & t_a  ::get_a_from_Test(t)
}

```
