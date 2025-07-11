#include "IndexOverflowException.h"

IndexOverflowException::IndexOverflowException(const std::string& msg) {
	this->message += msg;
}

const char* IndexOverflowException::what() const throw() {
	return (this->message).c_str();
}