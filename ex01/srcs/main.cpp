#include "Span.hpp"
#include <iostream>

void init_span(Span &span, uint N) {
	for (uint i = 0; i < N; i++) {
		span.addNumber(rand() % 10000000);
	}
}

int main() {
	Span a(1000);

	init_span(a, 1000);
	cout << a.shortestSpan() << endl;
	return 0;
}
