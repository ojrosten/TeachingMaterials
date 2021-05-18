#include "Probability.h"
#include "Foo.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <variant>
#include <set>

class Outputer
{
public:
    Outputer(const std::string& separator) : m_Separator{separator}
    {}

    void operator()(const int e) { std::cout << e << m_Separator; }

private:
    const std::string& m_Separator;
};

stuff::Foo make()
{
    stuff::Foo f{};

    return f;
}

stuff::Foo make2()
{
    return stuff::Foo{};
}

std::vector<int> foo()
{
    std::vector<int> v{};

    // SOme non-trivial stuff

    return v;
}

void swap(stuff::Foo& lhs, stuff::Foo& rhs)
{
    auto tmp{std::move(lhs)};
    //lhs = rhs; // operator=(const&)
    lhs = std::move(rhs); // operator=(&&)
    rhs = std::move(tmp);
}

template<class T>
void swap(T& lhs, T& rhs)
{
    auto tmp{std::move(lhs)};
    //lhs = rhs; // operator=(const&)
    lhs = std::move(rhs); // operator=(&&)
    rhs = std::move(tmp);
}

int main()
{
  try
  {
      using namespace stuff;

      Foo f{}, g{std::move(f)};// , h{make()}, k{make2()};
      
      swap(f, g);

      std::vector<Foo> x, y;

      std::swap(x, y);
  }
  catch(std::exception& e)
  {
    std::cout << e.what() << '\n';
  }
}
