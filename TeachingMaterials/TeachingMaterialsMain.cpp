#include "Probability.h"
#include "Foo.h"

#include <iostream>
#include <vector>


int main()
{
  try
  {
     math::Probability<double> p{0.7};

    stuff::Foo f{};
    int i{f.get()};
  }
  catch(std::exception& e)
  {
    std::cout << e.what() << '\n';
  }
}
