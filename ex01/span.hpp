#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Span
{
	private:
		std::vector<int> v;
		unsigned int n;
		unsigned int count_n;
	public:
		Span();
		Span(unsigned int n);
		void add(std::vector<int>::iterator start, std::vector<int>::iterator finish);
		void addNumber(int num);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
		Span(const Span &old);
		const Span & operator=(const Span & to_assignation);
		~Span();

		class too_many_numbers : public std::exception {
			virtual const char *what() const throw();
		};

		class too_few_numbers : public std::exception {
			virtual const char *what() const throw();
		};
};

#endif