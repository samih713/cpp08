#include <algorithm>
#include <stdexcept>

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template<typename T>
int easyfind(const T &container, const int &find)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), find);
    return (it != container.end() ? *it : throw std::runtime_error("Not found!"));
}

#endif // EASYFIND_HPP
