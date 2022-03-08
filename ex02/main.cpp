#include <iostream>
#include <list>
#include <deque>    

#include "mutantstack.hpp"

// clang++ -Wall -Wextra -Werror -std=c++98 main.cpp mutantstack.cpp 

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top = " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size = " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(21);
	mstack.push(0);
	std::cout << "size after push = " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "=== members MutantStack mstack ===" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "std::stack (copy of MutantStack) size = " << s.size() << std::endl;

	std::stack<int> d = s;
	std::cout << "std::stack (copy of s) size = " << s.size() << std::endl;

	MutantStack<int> a;
	std::cout << "size new empty MutantStack = " << a.size() << std::endl;
	a = mstack;
	std::cout << "size new MutantStack after assignation = " << a.size() << std::endl;
	a.push(42);
	{
		MutantStack<int>::iterator start = a.begin();
		MutantStack<int>::iterator finish = a.end();
		std::cout << "=== members MutantStack a after push ===" << std::endl;
		while (start != finish) {
			std::cout << *start << std::endl;
			++start;
		}
	}
	it = mstack.begin();
	std::cout << "=== members MutantStack mstack ===" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "=== test construction by copy ===" << std::endl;
	MutantStack<int> b(a);
	{
		MutantStack<int>::iterator start = b.begin();
		MutantStack<int>::iterator finish = b.end();
		std::cout << "=== members MutantStack b after copy ===" << std::endl;
		while (start != finish) {
			std::cout << *start << std::endl;
			++start;
		}
	}
	MutantStack<int> c = mstack;
	{
		MutantStack<int>::iterator start = c.begin();
		MutantStack<int>::iterator finish = c.end();
		std::cout << "=== members MutantStack c after copy ===" << std::endl;
		while (start != finish) {
			std::cout << *start << std::endl;
			++start;
		}
	}
	return 0;
}

// int main()
// {
// 	std::list<int> mstack;
// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	std::cout << mstack.back() << std::endl;
// 	mstack.pop_back();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	mstack.push_back(42);
// 	mstack.push_back(0);
// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite) {
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	return 0;
// }
