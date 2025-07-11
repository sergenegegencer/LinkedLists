#pragma once
#include <iostream>
#include <exception>

class IndexOverflowException : public std::exception {
private:
	std::string message = "Index Overflow: ";

public:
	IndexOverflowException(const std::string& msg);
	const char* what() const throw();
};