#include <vector>
#include <iostream>
#include "span.hpp"

// clang++ -Wall -Wextra -Werror -std=c++98 main.cpp span.cpp

int main () {
	std::cout << "=== test default constructor ===" << std::endl;
	Span a;
	std::cout << "ok" << std::endl;

	std::cout << "=== test longestSnap with empty vector ===" << std::endl;
	try {
		std::cout << a.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "=== test shortestSpan with empty vector ===" << std::endl;
	try {
		std::cout << a.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "=== test constuctor with argument ===" << std::endl;
	Span b(10);
	std::cout << "ok" << std::endl;

	std::cout << "=== test addNumber ===" << std::endl;
	b.addNumber(20);
	std::cout << "ok" << std::endl;
	
	std::cout << "=== test assignation operator ===" << std::endl;
	a = b;
	std::cout << "ok" << std::endl;

	std::cout << "=== test addNumber after assignation ===" << std::endl;
	a.addNumber(30);
	std::cout << "ok" << std::endl;

	std::cout << "=== test longestSnap after addNumber and assignation ===" << std::endl;
	try {
		std::cout << a.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "=== test shortestSpan after addNumber and assignation ===" << std::endl;
	try {
		std::cout << a.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "=== test construction by copy ===" << std::endl;
	Span c(b);
	std::cout << "ok" << std::endl;

	std::cout << "=== fill vector ===" << std::endl;
	a.addNumber(0);
	a.addNumber(-10);
	a.addNumber(40);
	a.addNumber(-50);
	a.addNumber(60);
	a.addNumber(-70);
	a.addNumber(80);
	a.addNumber(-90);

	std::cout << "ok\n=== test overload ===" << std::endl;
	try {
		a.addNumber(100);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "=== test longestSnap ===" << std::endl;
	std::cout << a.longestSpan() << std::endl;

	std::cout << "=== test shortestSpan ===" << std::endl;
	std::cout << a.shortestSpan() << std::endl;

	std::cout << "=== test 10500 numbers with empty vector with same size ===" << std::endl;
	Span d(10500);
	std::vector<int> v(10500, 10500);
	d.add(v.begin(), v.end());
	v[10000] = 0;

	std::cout << "ok\n=== test longestSnap ===" << std::endl;
	std::cout << d.longestSpan() << std::endl;

	std::cout << "=== test 10500 numbers with empty vector with other size (less) ===" << std::endl;
	std::vector<int> w(10000, 10000);
	Span e(10500);
	e.add(w.begin(), w.end());
	std::cout << "ok\n=== test longestSnap ===" << std::endl;
	std::cout << e.longestSpan() << std::endl;

	std::cout << "=== test addNumber after add ===" << std::endl;
	e.addNumber(5000);
	e.addNumber(9000);

	std::cout << "ok\n=== test longestSnap ===" << std::endl;
	std::cout << e.longestSpan() << std::endl;

	std::cout << "=== test shortestSpan ===" << std::endl;
	std::cout << e.shortestSpan() << std::endl;

	std::cout << "=== test 10500 numbers with empty vector with other size (more) ===" << std::endl;
	std::vector<int> x(20000, 20000);
	Span f(10500);
	std::cout << "\n=== test addNumber before add ===" << std::endl;
	f.addNumber(500);
	try {
		std::cout << "ok\n=== test add ===" << std::endl;
		f.add(x.begin(), x.end());
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "=== test longestSnap ===" << std::endl;
	std::cout << f.longestSpan() << std::endl;

	std::cout << "=== test shortestSpan ===" << std::endl;
	std::cout << f.shortestSpan() << std::endl;

	std::cout << "=== test overload with 10500 numbers ===" << std::endl;
	try {
		f.addNumber(100);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(5);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// }