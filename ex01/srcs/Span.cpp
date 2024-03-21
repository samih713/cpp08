#include "Span.hpp"
#include <cstdlib>
#include <vector>

using std::vector;

/* -------------------------------- Orthodox ------------------------------- */
Span::Span(uint N) : _count(0), _maxSize(N), _arr(new uint[N])
{
	DEBUG_PRINT("Span constructor called");
}

Span::~Span() throw()
{
	DEBUG_PRINT("Span destructor called");
	delete[] _arr;
}

Span::Span(const Span &other) : _count(other._count), _maxSize(other._maxSize)
{
	DEBUG_PRINT("Span copy constructor called");
	_arr = new uint[_maxSize];
	for (uint i = 0; i < _count; i++)
		_arr[i] = other._arr[i];
}

Span &Span::operator=(const Span &other)
{
	DEBUG_PRINT("Span copy assignement called");
	if (this == &other)
		return *this;
	delete[] _arr;
	_count = other._count;
	_maxSize = other._maxSize;
	_arr = new uint[_maxSize];
	for (uint i = 0; i < _count; i++)
		_arr[i] = other._arr[i];
	return *this;
}

/* --------------------------- Memeber functions --------------------------- */
void Span::addNumber(int n)
{
	if (_count >= _maxSize)
		throw OutOfRange("Span is full");
	_arr[_count++] = n;
}

uint Span::shortestSpan() {
	if (_count < 2)
		throw OutOfRange("Span is too short");

	vector<uint> v(_arr, _arr + _count);
	std::sort(v.begin(), v.end());

	uint min = UINT_MAX;
	uint diff;

	for (uint i = 0; i < _count - 1; i++) {
		diff = v[i + 1] - v[i];
		if (diff < min)
			min = diff;
	}

	return min;
}

uint Span::longestSpan() {
	if (_count < 2)
		throw OutOfRange("Span is too short");

	uint min = *std::min_element(_arr, _arr + _count);
	uint max = *std::max_element(_arr, _arr + _count);

	return max - min;
}

/* ------------------------------- OutOfRange ------------------------------- */
Span::OutOfRange::OutOfRange(const string &msg) : _msg(msg){}
Span::OutOfRange::~OutOfRange() throw(){}
Span::OutOfRange::OutOfRange(const Span::OutOfRange &other) : _msg(other.what()){}
const char *Span::OutOfRange::what() const throw() { return _msg.c_str(); }

/* ------------------------------- Debugging ------------------------------- */
#ifdef DEBUG
ostream &operator<<(ostream &os, const Span &span){

	uint _count = span.get_count();
	uint _maxSize = span.get_maxSize();
	uint *_arr = span.get_array();

	os << "Span: " << _count << " / " << _maxSize << " [";
	for (uint i = 0; i < _count; i++)
		os << _arr[i] << (i + 1 < _count ? ", " : "");
	os << "]";
	return os;
}
#endif // DEBUG
