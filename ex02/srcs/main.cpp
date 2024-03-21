#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);

	const MutantStack<int> mstack2 = mstack;
	for (MutantStack<int>::const_iterator it= mstack2.cbegin(); it != mstack2.cend(); it++)
		cout << *it << endl;
	return 0;
}
