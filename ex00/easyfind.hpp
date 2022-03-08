#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> 

template <typename T>
std::vector<int>::iterator easyfind(T t, int i) {
	class not_found : public std::exception {
		virtual const char *what() const throw() { return ("Element isn't found"); }
	};
	
	std::vector<int>::iterator found = find(t.begin(), t.end(), i);
	if (found == t.end()) {
		throw not_found();
	}
	return (found);
}

template <typename T>
std::list<float>::iterator easyFind(T t, float i) {
	class not_found : public std::exception {
		virtual const char *what() const throw() { return ("Element isn't found"); }
	};
	
	std::list<float>::iterator found = find(t.begin(), t.end(), i);
	if (found == t.end()) {
		throw not_found();
	}
	return (found);
}

#endif