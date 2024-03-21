#include <iostream>
#include <stack>
#include <iterator>
#include <vector>

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

using std::vector;
using std::cout;
using std::cerr;
using std::endl;

typedef unsigned int uint;
template<typename T, class Container=vector<T> >
class MutantStack : public std::stack<T, Container>
{
public:

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	MutantStack(){};
	~MutantStack(){};
	MutantStack(const MutantStack &other){this->c = other.c;};
	MutantStack &operator=(const MutantStack &other){this->c = other.c; return *this;};
	/* ---------------------------- member functions --------------------------- */

	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}

	const const_iterator cbegin() const
	{
		return this->c.begin();
	}

	const const_iterator cend() const
	{
		return this->c.end();
	}
};

#endif // MUTANTSTACK_HPP
