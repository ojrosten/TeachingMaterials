#pragma once

#include <type_traits>
#include <stdexcept>

namespace math
{
    std::string range_error();

    template<class T>
      requires std::is_floating_point_v<T>
    class Probability
    {
    public:
        constexpr explicit Probability(T p)
            : m_Prob{p}
        {
            if((m_Prob < 0) || (m_Prob > 1))
                throw std::out_of_range{range_error()};
        }
    private:
        T m_Prob{};
    };
}
