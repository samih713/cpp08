#include <algorithm>
#include <stdexcept>

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template<typename T>
int easyfind(const T &container, const int &find)
{
    return (*std::find(container.begin(), container.end(), find));
}

#endif // EASYFIND_HPP
