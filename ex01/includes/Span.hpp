#include <string>
#include <exception>
#include <iostream>

#ifndef SPAN_HPP
#define SPAN_HPP

#ifdef DEBUG
#define DEBUG_PRINT(msg) (std::cerr << (msg) << std::endl)
#else
#define DEBUG_PRINT(msg)
#endif // DEBUG_PRINT

using std::ostream;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

typedef unsigned int uint;

class Span
{
public:
/* -------------------------------- Orthodox ------------------------------- */
	explicit Span(uint N);
	~Span() throw();
	Span(const Span &other);
	Span &operator=(const Span &other);
/* --------------------------- Memeber functions --------------------------- */
	void addNumber(int n);
	uint shortestSpan();
	uint longestSpan();
/* ------------------------------- Debugging ------------------------------- */
#ifdef DEBUG
	uint get_count() const { return _count; }
	uint get_maxSize() const { return _maxSize; }
	uint *get_array() const { return _arr; }
#endif // DEBUG
/* ------------------------------- OutOfRange ------------------------------- */
class OutOfRange : public std::exception
{
public:
	explicit OutOfRange(const string &msg);
	~OutOfRange() throw();
	OutOfRange(const OutOfRange &other);
	const char *what() const throw();
private:
	string _msg;
};
private: // Span private members
	uint _count;
	uint _maxSize;
	uint *_arr;
};

ostream &operator<<(ostream &os, const Span &span);

#endif // SPAN_HPP
