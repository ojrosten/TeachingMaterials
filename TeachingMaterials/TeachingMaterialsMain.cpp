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

int main()
{
  try
  {
      /*using namespace math;

      Probability<double> p{0.5}, q{0.7};
      std::cout << p.raw_value() << '\n';
      std::cout << q.raw_value() << '\n';

      p += q;*/

      std::vector<int> v{1, 2, 3, 4, 3, 6};
      auto i{v.begin()};
      while(i != v.end())
      {
          if(*i == 3)
          {
              i = v.erase(i);
          }
          else
          {
              ++i;
          }
      }

      std::string separator{" "};

      auto fn = [separator](int e) { 
          e *= 2;
          return e;
      };

      std::vector<int> w{};

      std::transform(v.begin(), v.end(), std::back_inserter(w), fn);

      for(auto e : v)
          std::cout << e << ' ';

      std::cout << '\n';

      for(auto e : w)
          std::cout << e << ' ';

      using namespace math;
      using Prob = Probability<double>;
      std::array<Prob, 6> a{Prob{0.7}, Prob{0.5}, Prob{0.2}, Prob{0.1}, Prob{0.0}, Prob{0.6}};
      auto found = std::find(a.begin(), a.end(), math::Probability<double>{0.5});
      std::cout << '\n' << std::distance(a.begin(), found) << '\n';
  }
  catch(std::exception& e)
  {
    std::cout << e.what() << '\n';
  }
}
