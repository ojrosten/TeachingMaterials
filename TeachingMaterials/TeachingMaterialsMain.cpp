#include "Probability.h"
#include "Foo.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <variant>

int main()
{
  try
  {
      using namespace math;

      Probability<double> p{0.5}, q{0.7};
      std::cout << p.raw_value() << '\n';
      std::cout << q.raw_value() << '\n';

      p += q;
  }
  catch(std::exception& e)
  {
    std::cout << e.what() << '\n';
  }
}
