#pragma once
#include <iostream>
#include <exception>

class EmptyListException : public std::exception {
private:
	std::string message = "Empty List: ";

public:
	EmptyListException(const std::string& msg);
	const char* what() const throw();
};