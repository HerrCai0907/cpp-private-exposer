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

## reference

https://eel.is/c++draft/temp.spec#general-6

> The usual access checking rules do not apply to names in a declaration of an explicit instantiation or explicit specialization, with the exception of names appearing in a function body, default argument, base-clause, member-specification, enumerator-list, or static data member or variable template initializer.
>
> Note 1: In particular, the template arguments and names used in the function declarator (including parameter types, return types and exception specifications) can be private types or objects that would normally not be accessible.
