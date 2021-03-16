#pragma once

#include <type_traits>
#include <stdexcept>
#include <iostream>

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

        Probability(const Probability&) = default;

        Probability& operator=(const Probability&) = default;

        Probability& operator+=(const Probability& rhs)
        {
            Probability q{m_Prob + rhs.m_Prob};
            *this = q;
            return *this;
        }

        [[nodiscard]]
        T raw_value() const
        {
            return m_Prob;
        }
    private:
        T m_Prob{};
    };
}
