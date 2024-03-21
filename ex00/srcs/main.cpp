#include "easyfind.hpp"
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main()
{
    vector<int> a(3, 4);
    list<int>   b(3, 4);
    cout << easyfind(b, 2) << endl;
    return 0;
}
