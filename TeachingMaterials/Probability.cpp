#include "Probability.h"

namespace math
{
    std::string range_error() {
        return "Out of range!";
    }

    /*template<class T>
    requires std::is_floating_point_v<T>
    Probability<T>::Probability(T p)
        : m_Prob{p}
    {
        if((m_Prob < 0) || (m_Prob > 1))
            throw std::out_of_range{"Out of range"};
    }*/
}