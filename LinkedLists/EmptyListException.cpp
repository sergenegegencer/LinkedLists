#include "EmptyListException.h"

EmptyListException::EmptyListException(const std::string& msg) {
	this->message += msg;
}

const char* EmptyListException::what() const throw() {
	return this->message.c_str();
}