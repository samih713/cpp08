#include "easyfind.hpp"
// #include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void init_vector(vector<int> &v, int a) {
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    *it = a++;
}

int main()
{
    vector<int> a(90);
    init_vector(a, 90);
    cout << easyfind(a, 93) << endl;
    return 0;
}
