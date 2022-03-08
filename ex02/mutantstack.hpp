#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>

template <typename Type>
class MutantStack : public std::stack<Type>
{
	public:
		class iterator : public std::iterator<std::input_iterator_tag, Type> {
			private:
				Type *p;
			public:
				iterator(Type *x) : p(x) {};
				iterator(const iterator &old) : p(old.p) {};
				bool operator!=(const iterator & to_compare) const {return (p != to_compare.p);};
				bool operator==(const iterator & to_compare) const {return (p == to_compare.p);};
				const iterator & operator++(void) {++p; return (*this);};
				const iterator & operator--(void) {--p; return (*this);};
				Type & operator*() {return (*p);};
		};

		const MutantStack & operator=(MutantStack & to_assignation);
		~MutantStack();

		// parent has default constructor 
		// parent has construstion by copy 
		
		iterator end(void) {
			iterator e(&this->top() + 1);
			return (e);
		};
		
		iterator begin(void) {
			iterator b(&this->top() + 1 - this->size());
			return (b);
		};
};

template <typename Type>
MutantStack<Type>::~MutantStack() { }

template <typename Type>
const MutantStack<Type> & MutantStack<Type>::operator=(MutantStack<Type> & to_assignation) {
	if (*this == to_assignation)
		return (*this);
	unsigned int s = to_assignation.size();
	while (!this->empty()) {
		this->pop();
	}
	for (unsigned int i = 0; i < s; i++) {
		this->push(to_assignation.c[i]);
	}
	return (*this);
}

#endif