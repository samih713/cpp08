#include "Span.hpp"
#include <iostream>

int main() {
	Span a(5);

	a.addNumber(0);
	a.addNumber(5);
	a.addNumber(60);
	a.addNumber(63);
	cout << a.shortestSpan() << endl;
	return 0;
}
