#include "span.hpp"

Span::Span() : n(0) {
	this->count_n = 0;
}

Span::~Span() { }

Span::Span(unsigned int n) : n(n) {
	this->count_n = 0;
}

void Span::add(std::vector<int>::iterator start, std::vector<int>::iterator finish) {
	unsigned int free = this->n - this->count_n;
	std::vector<int>::iterator n_finish;
	unsigned int old_count = this->count_n;
	bool flag = false;

	if (free < (finish - start)) {
		n_finish = start + free;
		this->count_n = n;
		flag = true;
	}
	else {
		n_finish = finish;
		this->count_n = count_n + (finish - start);
	}
	this->v.resize(this->count_n);
	std::vector<int>::iterator v_start = this->v.begin() + old_count;
	std::copy(start, n_finish, v_start);
	if (flag)
		throw too_many_numbers();
}

void Span::addNumber(int num) {
	if (this->count_n < this->n) {
		this->count_n++;
		this->v.push_back(num);
		return ;
	}
	throw too_many_numbers();
}

unsigned int Span::shortestSpan(void) {
	int min_diff;

	if (this->v.size() < 2)
		throw too_few_numbers();
	if (this->v[0] > this->v[1])
		min_diff = this->v[0] - this->v[1];
	else
		min_diff = this->v[1] - this->v[0];
	for (unsigned int i = 0; i < this->count_n; i++) {
		for (unsigned int j = i + 1; j < this->count_n; j++) {
			if (this->v[i] > this->v[j]) {
				if ((this->v[i] - this->v[j]) < min_diff)
					min_diff = this->v[i] - this->v[j];
			}
			else {
				if ((this->v[j] - this->v[i]) < min_diff)
					min_diff = this->v[j] - this->v[i];
			}
		}
	}
	return (min_diff);
}

unsigned int Span::longestSpan(void) {
	int min;
	int max;
	unsigned int i;

	if (this->v.size() < 2)
		throw too_few_numbers();
	min = *std::min_element(this->v.begin(), this->v.end());
	max = *std::max_element(this->v.begin(), this->v.end());
	return (max - min);
}

Span::Span(const Span &old) {
	*this = old;
	return ;
}

const Span & Span::operator=(const Span & to_assignation) {
	if (this == &to_assignation) {
		return (*this);
	}
	this->v = to_assignation.v;
	this->count_n = to_assignation.count_n;
	this->n = to_assignation.n;
	return (*this);
}

const char *Span::too_many_numbers::what() const throw() {
	return ("the array is full!");
}

const char *Span::too_few_numbers::what() const throw() {
	return ("the array doesn't contain numbers or containts only one number!");
}
